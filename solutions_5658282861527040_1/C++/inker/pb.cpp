#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int t, h1, n;
string s;

typedef long long ll;
// bit, a, b, k
ll dp[33][2][2][2];
bool done[33][2][2][2];
ll ans;

void upt(int fh1, int fh2, int fh3, int fh4, ll w){
	if(fh1 == -1){
		if(fh2 == 0 && fh3 == 0 && fh4 == 0)
			ans += w;
		return ;
	}
	if(!done[fh1][fh2][fh3][fh4]){
		done[fh1][fh2][fh3][fh4] = 1;
		dp[fh1][fh2][fh3][fh4] = 0;
	}
	dp[fh1][fh2][fh3][fh4] += w;
}

int main(){
	scanf("%d", &t);
	for(int cc = 1 ; cc <= t ; cc ++){
		int a,b,k;
		scanf("%d %d %d", &a, &b, &k);
		printf("Case #%d: ", cc);
		ans = 0;
		memset(done, 0, sizeof(done));
		upt(31, 1, 1, 1, 1);
		for(h1 = 31 ; h1 >= 0 ; h1 --){
			bool ba = (a & (1<<h1)), bb = (b & (1<<h1)), bk = (k & (1<<h1));
			for(int pba = 0 ; pba < 2 ; pba ++){
				for( int pbb = 0 ; pbb < 2 ; pbb ++){
					for(int pbk = 0 ; pbk < 2 ; pbk ++){
						if(done[h1][pba][pbb][pbk]){
							for(int nba = 0 ; nba <= (pba?ba:1) ; nba ++){
								for(int nbb = 0 ; nbb <= (pbb?bb:1) ; nbb ++){
									bool res = (nba&nbb);
									if(!pbk || ( res <= bk )){
										upt(h1-1, pba&&(nba==ba), pbb&&(nbb==bb), pbk&&(res==bk), dp[h1][pba][pbb][pbk]);
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
