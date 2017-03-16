#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
#define INF 1<<23

#define I1(a) scanf("%d",&a)
#define I2(a,b) scanf("%d %d",&a,&b)
#define I3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define rep(i,s,e) for(i=s;i<e;i++)
#define repr(i,s,e) for(i=s;i>e;i--)


#define in(a) freopen(a,"r",stdin)
#define out(a) freopen(a,"w",stdout)
#define ll long long
ll BigMod(ll B,ll P,ll M){  ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R%M;}
#define ull unsigned long long
int L,K,S;
string keyboard;
string target;
int last_val;
double n;
map<int,double>MP;
vector<int>PRE;
double mx;

vector<int> PrefixFunction(string S) {
    vector<int> p(S.size());
    int j = 0;
    for (int i = 1; i < (int)S.size(); i++) {
        while (j > 0 && S[j] != S[i])
            j = p[j-1];

        if (S[j] == S[i])
            j++;
        p[i] = j;
    }
    return p;
}

double expected(int pos,int milse,double kotogula){
    mx=max(mx,kotogula);
    double val=0;
    if(pos==S)return kotogula;
    if(milse<K-1){
        for(int i='A';i<='Z';i++){
            if(MP[i]==0)continue;
            double ex=MP[i]/n;
            if(target[milse]==(char)i){
                val+=ex*expected(pos+1,milse+1,kotogula);
            }
            else{
                val+=ex*expected(pos+1,0,kotogula);
            }
        }
    }
    else if(milse==K-1){
        for(int i='A';i<='Z';i++){
            if(MP[i]==0)continue;
            double ex=MP[i]/n;
            if(target[milse]==(char)i){
                if(target[0]==target[target.size()-1] && K>1)
                    val+=ex*expected(pos+1,last_val,kotogula+1.0);
                else
                    val+=ex*expected(pos+1,0,kotogula+1.0);
            }
            else{
                val+=ex*expected(pos+1,0,kotogula);
            }
        }
    }
    return val;
}
int main()
{
    in("in.txt");
    out("out.txt");
    int T,caseno=1;
    cin>>T;

    while(T--){
        cin>>L>>K>>S;
        cin>>keyboard;
        cin>>target;
        MP.clear();
        n=0;
        mx=0;
        for(int i=0;i<keyboard.size();i++){
            MP[keyboard[i]]++;
            n++;
        }
        PRE.clear();
        PRE=PrefixFunction(target);
        last_val=PRE[PRE.size()-1];
        double upori=expected(0,0,0.0);
//        cout<<mx<<endl;
        upori=mx-upori;
        printf("Case #%d: %.8lf\n",caseno++,upori);
//        cout<<"Case #"<<caseno++<<": "<<upori<<endl;
    }
    return 0;
}
