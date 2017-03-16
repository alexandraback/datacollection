# include <bits/stdc++.h>

# define ff first
# define ss second
# define mp(x,y) make_pair(x,y)
# define tr(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

template<typename A, typename B> inline void amax(A &x, B y) {if(x < y) x = y;}
template<typename A, typename B> inline void amin(A &x, B y) {if(!(x < y)) x = y;}

typedef long long lld;

using namespace std;

map<lld,lld> dp;
lld pw[99];

lld rev(lld x){
	lld ret = 0;
	
	while(x){
		ret = ret * 10LL + x % 10LL;
		x /= 10LL;
	}
	
	return ret;
}

int main(){
	pw[0] = 1;
	
	for(int i=1; i<=15; i++)
		pw[i] = pw[i-1] * 10LL;
	
	dp[1] = 1;
	dp[10] = 10;
	
	lld san = 10;
	
	for(int i=2; i<=14; i++){
		san *= 10LL;
		dp[san] = dp[san/10] + pw[i/2 + (i%2)] + pw[i/2] - 1LL;
	}
	
	//for(int i=1; i<=14; i++)
		//printf("%d : %lld\n",i,dp[pw[i]]);
	
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	
	int t;
	lld n, gosh;
	lld ans;
	lld mx = 10000009, tmp, wah;
	lld best;
	
	scanf("%d",&t);
	
	for(int i=0; i<t; i++){
		gosh = 0;
		ans = 0;
		
		scanf("%lld",&n);
		
		if(n % 10LL == 0LL)
			n--, gosh++;
		
		int uz = 0;
		
		tmp = n;
		
		while(tmp){
			uz++;
			tmp /= 10LL;
		}
		
		uz--;
		
		if(n == pw[uz]){
			printf("Case #%d: 1\n",i+1,dp[pw[uz]]);
			continue;
		}
		
		ans = dp[pw[uz]];
		best = n - pw[uz];
		
		tmp = pw[uz];
		
		for(lld j=1; j<=mx; j++){
			tmp += j;
			
			if(tmp % 10LL == 0LL){
				tmp -= j;
				continue;
			}
			
			wah = rev(tmp);
			
			if(wah <= n  &&  best > (n - wah + 1LL + j)  &&  wah > tmp)
				best = (n - wah + 1LL + j);
			
			tmp -= j;
		}
		
		ans += best;
		
		printf("Case #%d: %lld\n",i+1,ans+gosh);
	}
}

