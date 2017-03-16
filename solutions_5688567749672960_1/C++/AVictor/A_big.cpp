#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

typedef long long ll;

int len(ll a)
{
	int r = 0;
	while (a)
	{
		r++;
		a/=10;
	}
	return r;
}

ll rev(ll a)
{
	ll r = 0;
	while(a)
	{
		r = 10*r+a%10;
		a/=10;
	}
	return r;
}


ll work(ll N)
{
		ll ans = 1;
		ll cur = 1;
		int l = len(N);
		for(int i=2;i<l;i++)
		{
			ll t = 1;
			for(int j=0;j<(i-1)>>1;j++) t*=10;
			for(int j=0;j<(i>>1);j++) t = 10*t + 9;
			ans += t-cur + 1;
			cur = rev(t);
			//cout << t << " " << cur << " " <<ans<<endl;
		}
		ll ans1 = ans + N - cur;
		

			ll mn=1;
			for(int i=0;i<(l+1)>>1;i++) mn*=10;
		
			ll t = (N/mn)*mn+1;
			ll t_rev = rev(t);
			if (t_rev < N && t <= N)
			{
				ll ans2 = ans + 1 + N - t + t_rev - cur;
				ans1 = min(ans1, ans2);
			}
		
		return ans1;	
}

int main()
{
	int T;
	cin>>T;
	for(int test_num=1;test_num<=T;test_num++)
	{
		ll N;
		cin >> N;
		ll ans = work(N);
		if (N > 1) ans = min(ans, work(N-1)+1);
		
		printf("Case #%d: %d\n", test_num, ans);	
	}
	
	return 0;
}
