/***********************************************\
 |Author: YMC
 |Created Time: 2015/5/10 17:23:01
 |File Name: b.cpp
 |Description: 
\***********************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define mset(l,n) memset(l,n,sizeof(l))
#define rep(i,n) for(int i=0;i<n;++i)
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
char key[105];
char tar[105];
double dp[105][105];
int ma[256];
double poi[256];
int K, L, S;
int main() {
	freopen("B-large.in","r",stdin); 
	//freopen("input.txt","r",stdin); 
    freopen("out.txt","w",stdout);
    int T;
    int cas = 1;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d %d",&K,&L,&S);
        //cout<<K<<" "<<L<<" "<<S<<endl;
        scanf("%s",key); 
        for(int i=0;i<256;++i) ma[i] = 0;
        memset(ma,0,sizeof(ma));
        memset(poi,0,sizeof(poi));
        rep(i,K) {
            ma[key[i] - 'A'] ++;
            poi[key[i] - 'A'] = ma[key[i] - 'A']*1.0 / K;
        }
        scanf("%s",tar);
        //memset(dp,0,sizeof(dp));
        for(int i=0;i<=L;++i) dp[0][i] = 0;
        dp[0][0] = 1;
        for(int i=0;i<=S;++i) dp[i][0] = 1;
        for(int i=1;i<=S;++i) {
            //dp[i][0] = dp[i-1][0] * (1 - poi[tar[0] - 'A']);
            for(int j=1;j<=L;++j) {
                //cout<<"     "<<poi[key[j-1] - 'A']<<"    "<<key[j-1]<<endl;
                dp[i][j] = dp[i-1][j-1] * poi[tar[j-1] - 'A'];
                //dp[i][0] += dp[i-1][j-1] * (1- tar[key[j-1] - 'A']);
            }
        }
        /*for(int i=1;i<=S;++i) {
            for(int j=1;j<=L;++j) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        double all = 0;
        for(int i=1;i<=S;++i) all += dp[i][L];
        int want = L;
        for(int i=1;i<L;++i) {
            bool fg = true;
            int t1 = i;
            for(int j=0;j<L;++j) {
                if(tar[t1] != tar[j]) {
                    fg = false;
                    break;
                } else t1++;
                if(t1 == L) break;
            }
            if(fg) {
                want = L - (L - i);
                break;
            }
        }
        int maxx = (S - L) / want + 1;
        bool ff = true;
        for(int i=0;i<L;++i) {
            if(ma[tar[i] - 'A'] == 0) {
                ff = false;
                break;
            }
        }
        if(!ff) maxx = 0;
        //cout<<"want == "<<want<<endl;
        //cout<<"maxx == "<<maxx<<endl;
        //cout<<"all  == "<<all<<endl;
        printf("Case #%d: %.7lf\n",cas ++, maxx - all);
    }
	return 0;
}

