#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long ll;

int T;
ll A,B,ans;
char s[100], t[100];

bool pal(ll x)
{
	int len(0);
	while (x) t[++len]=(x%10)-48, x/=10;
	for (int i=1;i<=len;i++) s[len-i+1]=t[i];
	for (int i=1,j=len;i<=j;i++,j--) if (s[i]!=s[j]) return false;
	return true;
}

int main()
{
	freopen("fs.in","r",stdin);
	freopen("fs.out","w",stdout);
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		cin>>A>>B;
		ans=0;
		for (ll i=1;i<=10000000;i++)
		{
			ll i2(i*i);
			if (i2<A || i2>B) continue;
			if (pal(i) && pal(i2))
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

