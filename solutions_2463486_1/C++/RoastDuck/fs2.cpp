#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

int T;
ll A,B,ans,ANS[10000005];
char s[100], t[100];

inline bool pal(ll x)
{
	int len(0);
	while (x) t[++len]=(x%10)-48, x/=10;
	for (int i=1;i<=len;i++) s[len-i+1]=t[i];
	for (int i=1,j=len;i<=j;i++,j--) if (s[i]!=s[j]) return false;
	return true;
}

int main()
{
	freopen("fs2.in","r",stdin);
	freopen("fs2.out","w",stdout);
	ans=0;
	for (ll i=1;i<=10000000;i++)
	{
		ll i2(i*i);
		//if (i2<A || i2>B) continue;
		if (pal(i) && pal(i2))
			ans++;
		ANS[i]=ans;
	}
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		cin>>A>>B;
		cout<<ANS[int(sqrt(B))]-ANS[int(ceil(sqrt(A))-1)]<<endl;
	}
	return 0;
}

