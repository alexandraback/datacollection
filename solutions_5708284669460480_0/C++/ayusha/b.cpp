#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,n)        for(int i=0;i<n;++i)
int cnt,temp,mx;
string a,b,x;
int k,l,s;
ll power(ll b, ll p)
{ if (!p) return 1;
 ll sq = power(b, p / 2); sq *= sq; 
 if (p % 2) sq *= b; 
 return sq;
}
void rec()
{
 
	if (x.length() == s)
	{
		temp = 0;
		loop(i, s)
		{
			if (x.substr(i, l) == b)++cnt,++temp;
		}
		mx = max(mx, temp);
		return;
	}
	loop(i, k)
	{
		x += a[i];
		rec();
		x.pop_back();
	}
}
int main()
{
	int t;
	cin >> t;
	loop(i, t)
	{
		cin >> k >> l >> s>>a>>b;
		cnt =0;
		mx = 0;
		int tot = power(k,s);
		rec();
		printf("Case #%d: ", i + 1);
		cout <<fixed<<setprecision(12)<<mx-double(cnt)/tot<<endl;
	}
}
