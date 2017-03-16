#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
typedef long long ll;
using namespace std;
////////////1,i,j,k,-1,-i,-j,-k
map<int,char> m;
map<char,int> ma;
map<int,int> mi;
int nMuL[4][4];
int mul(int a, int b){
    //input -4,-3,-2,-1,1,2,3,4
    //output same
    int extraSign=1;
    if(a<0)extraSign*=-1;
    if(b<0)extraSign*=-1;
    return nMuL[mi[a]][mi[b]]*extraSign;
}
string toChar(int a){
    string sss="";
    if(a<0){
        sss="-";
    }
    sss=sss+m[a];
    return sss;
}
void init(){
    m[1]='1';//1
    m[2]='i';//i
    m[3]='j';//j
    m[4]='k';//k
    m[-1]='1';//1
    m[-2]='i';//i
    m[-3]='j';//j
    m[-4]='k';//k

    ma['i']=2;
    ma['j']=3;
    ma['k']=4;

    mi[1]=0;//1
    mi[2]=1;//i
    mi[3]=2;//j
    mi[4]=3;//k
    mi[-1]=0;//1
    mi[-2]=1;//i
    mi[-3]=2;//j
    mi[-4]=3;//k
    //from 0,1,2,3 to -4,-3,-2,-1,1,2,3,4
//t nums[]={1,2,3,4};
////////////1,i,j,k
    nMuL[0][0]=1;
    nMuL[0][1]=2;
    nMuL[0][2]=3;
    nMuL[0][3]=4;

    nMuL[1][0]=2;
    nMuL[1][1]=-1;
    nMuL[1][2]=4;
    nMuL[1][3]=-3;

    nMuL[2][0]=3;
    nMuL[2][1]=-4;
    nMuL[2][2]=-1;
    nMuL[2][3]=2;

    nMuL[3][0]=4;
    nMuL[3][1]=3;
    nMuL[3][2]=-2;
    nMuL[3][3]=-1;
}

string s,ns;
ll L, X,X2,N;
int dp[200000][10][5];
int nums[200000];
int f(int pos, int num, int ayyeha){

    if(ayyeha>=5)return 0;
    if(pos==N){
        return (num==ayyeha && ayyeha==4);
    }
    //cout << pos << " " << num << " " << ayyeha << " " << dp[pos][num][ayyeha] << endl;
    if(dp[pos][num][ayyeha]!=-1)return dp[pos][num][ayyeha];

    int fl=0;

    if(num==ayyeha){
        fl=fl||f(pos+1,nums[pos],ayyeha+1);
    }
    fl=fl||f(pos+1,mul(num,nums[pos]),ayyeha);
    return dp[pos][num][ayyeha]=fl;
}
string solve(){
    for(int i=0;i<N;i++){
        nums[i]=ma[ns[i]];
    }
    memset(dp,-1,sizeof(dp));
    bool fl= f(0,1,2);
    if(fl)return "YES";
    else return "NO";
}
int stepsTo1(int a){
    int b=a;
    int steps=1;
    while(b!=1){
        b=mul(b,a);
        steps++;
    }
    return steps;
}
int sTo1(){
    int a=1;
    for(int i=0;i<L;i++){
        a=mul(a,ma[s[i]]);
    }
    return stepsTo1(a);
}
int main()
{
    freopen("txt.in","r",stdin);
    freopen("out","w",stdout);
    init();
    int T;
    cin >> T;

    for(int t=0;t<T;t++){
        cin >> L >> X;
        cin >> s;
        ns="";
        if(X<12){
            N=L*X;
            for(int i=0;i<X;i++){
                ns=ns+s;
            }
            cout << "Case #" << (t+1) <<": " << solve() << endl;
        } else {
            int st1=sTo1();
            X2=X-st1*2;
            X=X2%st1+st1*2;
            N=L*X;

            for(int i=0;i<X;i++){
                ns=ns+s;
            }
            cout << "Case #" << (t+1) <<": " << solve() << endl;
        }
    }
    return 0;
}
