#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <utility>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <bitset>
#define  pb push_back
#define mp make_pair
#define pii pair< pair<int,int> , pair<int,int> >
#define rep(i,s,n) for(int i=s;i<n;++i)

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int buf_i;
int in(){
    scanf("%d", &buf_i);
    return buf_i;
}
const int INF=~(1<<31);
const ll LINF=~(1LL<<63);

const double eps=1e-6;
ll gcd(ll a, ll b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}

int main(){
#ifdef SSU
    freopen("cj4","r", stdin);
     freopen("cj4out.txt", "w", stdout);
#else
    //  freopen("g.in","r", stdin);
    // freopen("g.out", "w", stdout);
#endif

    int T=in();

    for(int t=0;t<T;++t){
        printf("Case #%d: ",t+1);
        int n=in();
        vector<string> v;
        for(int i=0;i<n;++i){
            string s;
            cin>>s;
            v.pb(s);
        }
        vector<int> w;
        for(int i=0;i<n;++i) w.pb(i);
        int res=0;
        do{
            char last=-1;
            vector<char> u(26,0);
            bool ok=true;

            for(int i=0;i<n;++i){
                for(int j=0;j<v[w[i]].size();++j){
                   // cout<<v[w[i]][j];
                    if(last==-1){
                        u[v[w[i]][j]-'a']=1;
                        last=v[w[i]][j];
                    }else{
                        if(last!=v[w[i]][j]){
                            if(u[v[w[i]][j]-'a']==1){
                                ok=false;
                                goto end;
                            }else{
                                last=v[w[i]][j];
                                u[v[w[i]][j]-'a']=1;
                            }
                        }
                    }
                }
            }
            end:
            if(ok) res++;
            //cout<<" "<<ok<<endl;
        }while(next_permutation(w.begin(),w.end()));
        cout<<res<<endl;

    }
    fflush(stdout);







    return 0;
}
