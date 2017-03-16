#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string c,j;

ll a;

ll m,n;

ll f,s;

int l;

ll po[19];

void dfs(ll x, ll y, int k)
{
	if (abs(x-y)<a) a = abs(x-y),m=x,n=y;
	else if (abs(x-y)==a && x<m) a = abs(x-y),m=x,n=y;
	else if (abs(x-y)==a && x==m && y<n) a = abs(x-y),m=x,n=y;

	if (k>=l) return;

	if (c[k]!='?' && j[k]!='?') dfs(x,y,k+1);
	else if (c[k] == j[k])
	{
		for (int xx=0; xx<10; xx++)
			for (int yy=0; yy<10; yy++)
				dfs(x+po[l-k-1]*xx,y+po[l-k-1]*yy,k+1);
		return;
	}

	if (c[k]=='?')
	{
		for (int xx=0; xx<10; xx++)
			dfs(x+po[l-k-1]*xx,y,k+1);
	} else if (j[k]=='?')
	{
		for (int xx=0; xx<10; xx++)
			dfs(x,y+po[l-k-1]*xx,k+1);
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	po[0]=1;
	for (int i=1; i<19; i++)
		po[i] = po[i-1]*10;

	int tst;
	cin>>tst;
	for (int ntst = 1; ntst<=tst; ntst++)
	{
		cout<<"Case #"<<ntst<<": ";

		cin>>c>>j;

		l = c.length();

		m=n=0;
		f=s=0;

		for (int i=0; i<l; i++)
			f*=10,f+=(c[i]!='?'?c[i]-'0':0);
		for (int i=0; i<l; i++)
			s*=10,s+=(j[i]!='?'?j[i]-'0':0);

		a = 1ll<<33;


		dfs(f,s,0);

		for (int i=0; i<l; i++)
			c[i] = m%10+'0', m/=10;

		for (int i=0; i<l; i++)
			j[i] = n%10+'0', n/=10;

		reverse(c.begin(),c.end());
		reverse(j.begin(),j.end());

		cout<<c<<' '<<j;

		cout<<'\n';
	}

    return 0;
}

