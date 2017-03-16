#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <ctime>
#include <map>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <list>
#include <vector>
#include <iomanip>
#include <cctype>
#include <complex>
#include <iterator>
#include <ostream>
#include <bitset>
#define all(a) a.begin(),a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define clx complex<long double>
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;
int _bufint;
inline int in(){
    scanf("%d", &_bufint);
    return _bufint;
}
const ll LINF=~((1ll)<<63);
const int INF=~(1<<31);
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
vector<vector<char> > g;
bool can(int x, int y){
    if(y==20) return 0;
    if(g[y+2][x]=='a') return 0;
    if(g[y+1][x-1]=='a') return 0;
    if(g[y+1][x+1]=='a') return 0;

    return 1;
}
bool canleft(int x, int y){
    if(y==20) return 0;
    if(g[y+1][x-2]=='a') return 0;
    if(g[y+2][x-1]=='a') return 0;
    if(g[y+1][x-1]=='a') return 0;
    return 1;
}
bool canright(int x, int y){
    if(y==20) return 0;
    if(g[y+1][x+2]=='a') return 0;
    if(g[y+2][x+1]=='a') return 0;
    if(g[y+1][x+1]=='a') return 0;
    return 1;
}


int main(){
#ifdef SSU
    freopen("output.txt", "r", stdin);
     freopen("output1.txt", "w", stdout);
#endif
  /*  srand(time(0));
    int N=50000000;
    int T=20;
    vector<vector<vector<ll> > >ans(22, vector<vector<ll> >(21, vector<ll>(20,0)));
    for(int i=0;i<N;++i){
        g.assign(25, vector<char>(20,'e'));

        for(int k=0;k<T;++k){
            int x=10;
            int y=0;
            g[y][x]='a';
            while(y<20){
                if(can(x,y)){
                    y++;
                    g[y-1][x]='e';
                    g[y][x]='a';
                    continue;
                }
                if(canleft(x,y) && canright(x,y)){
                    if(rand()&1){
                        g[y][x]='e';
                        --x;
                        ++y;
                        g[y][x]='a';
                    }else{
                        g[y][x]='e';
                        ++x;
                        ++y;
                        g[y][x]='a';
                    }
                }else if(canleft(x,y)){
                    g[y][x]='e';
                    --x;
                    ++y;
                    g[y][x]='a';
                }else if(canright(x,y)){
                    g[y][x]='e';
                    ++x;
                    ++y;
                    g[y][x]='a';
                }else{
                    break;
                }

            }

            for(int i1=0;i1<g.size();++i1){
                for(int j1=0;j1<g[i1].size();++j1){
                    if(g[i1][j1]=='a') ans[k][i1][j1]++;
                    // ans[k+1][i1][j1]+=ans[k][i1][j1];

                }
            }

        }

    }
    for(int k=0;k<ans.size();++k){
        for(int i=0;i<ans[0].size();++i){
            for(int j=0;j<ans[0][i].size();++j){
                int sum=0;
                // for(int k=0;k<ans.size();++k) sum+=ans[k][i][j];
                printf("%.8lf ",(double)((long double)ans[k][i][j]/N));
                //  cout<<g[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }*/


    map<pair<int,pair<int,int> >, double> ans;
    for(int i=0;i<20;++i){
        for(int j=0;j<21;++j){
            for(int k=0;k<20;++k){
                double c;
                cin>>c;
                ans[mp(i+1, mp(k-10, 20-j))]=c;
            }
        }
    }
    freopen("b3.txt", "r", stdin);

    int T=in();
//    cout<<T<<endl;
    for(int t=0;t<T;++t){
        double an=0;
        int a=in(), b=in(), c=in();
        if(ans.count(mp(a, mp(b,c)))==1){
            an=ans[mp(a, mp(b,c))]+1e-7+1e-7;
        }
        printf("Case #%d: %lf\n", t+1, an);
    }
    return 0;
}
