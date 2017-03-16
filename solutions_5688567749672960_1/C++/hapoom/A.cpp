#include<stdio.h>
#include<vector>
using namespace std;

long long int pow10(int x){
	long long int c=1;
	while(x--) c*=10;
	return c-1;
}

long long int rev(long long int x){
	long long int c=0;
	while(x != 0){
		c *= 10;
		c += x%10;
		x /= 10;
	}
	return c;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-output.txt","w",stdout);
	int T;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++){
		long long int N;
		scanf("%lld", &N);
		long long int ans=1;
		int len = 0;
		for(;ans<=N;len++)
			ans*=10;
		ans=0;
		while(N>=10){
			long long int l = N/(pow10((len)/2)+1), r = N%(pow10((len)/2)+1);
			if(r == 0){
				N--;
				ans++;
				if(rev(l) == 1)
					len--;
				continue;
			}
			ans += (r-1);
			if(len%2==1 && rev(l/10) == 1){
				ans++;
				N -= r;
				continue;
			}
			if(rev(l) != 1){
				ans++;
				N-=(r-1);
				N=rev(N);
				l = N%(pow10((len+1)/2)+1);
				ans += (l-1);
			}
			ans++;
			ans++;
			N = pow10(--len);
		}
		ans += N;
		printf("Case #%d: %lld\n", tc, ans);
	}
	return 0;
}