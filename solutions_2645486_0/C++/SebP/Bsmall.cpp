///SACAR FREOPEN.
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<list>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<map>
#include<sstream>

using namespace std;

#define all(c) (c).begin(),(c).end()
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define formn(i,m,n) for(int i=m;i<(int)n;i++)
#define dformn(i,m,n) for(int i=n-1;i>=m;i--)
#define mp make_pair
#define pb push_back

const double PI=acos(-1.0);

typedef long long tint;
typedef pair<int,int> pint;

int main(){
freopen("BsmallInput.txt","r",stdin);
freopen("BsmallOutput.txt","w",stdout);
	int TC;cin>>TC;
	formn(tc,1,TC+1){
		int E,r,n;cin>>E>>r>>n;
		vector<int> v(n); forn(i,n) cin>>v[i];
		int dp[n+1][E+1];
		///dp[d][e] = maximo putaje al empezar el dia d con energia e.
		///res = max (dp[d+1][e]) sobre todo 0<= e <= E.
		forn(i,n+1) forn(j,E+1) dp[i][j] = -1;
		dp[0][E] = 0;/// putaje al empezar el dia 0 con E energia.
		for(int d = 0; d < n; d++){
			///para  el dia d+1.
			for(int e = 0; e <= E; e++){
				///con energia e
				///si vengo de dp[d][e'] tras gastar k y recuperar r.
				///dp[d + 1][e] = max( dp[d][e'] + k * v_d : k <= e' && min(e' - k + r , E) = e)
				for(int e2 = 0; e2 <= E; e2++){
					for(int k = 0; k <= E; k++){
						if(k <= e2 && (min(e2 - k + r, E)==e)){
							dp[d + 1][e] = max(dp[d+1][e] , dp[d][e2] + v[d] * k);
						}
					}
				}
			}
		}
		int best = -1;
		for(int e = 0; e <= E; e++){
			best = max(best,dp[n][e]);
		}
		cout<<"Case #"<<tc<<": "<<best<<endl;
	}
    return 0;
}
