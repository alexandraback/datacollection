#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef unsigned long long ull;

#define rloop(i,a,b) for(i=a-1;i>=b;i--)
#define loop(i,a,b) for(i=a;i<b;i++)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define gc getchar   
#define rz resize
#define all(x) x.begin(),x.end()
#define sz size

double rd()
{
	double ret = 0.0;
	char c = gc();
	while( (c<'0' || c>'9') && c!='.') 
		c = gc();
	while(c>='0' && c<='9') 
	{
		ret = 10 * ret + c - 48;
		c = gc();
	}
	if (c=='.')
	{
		c = gc();
		ll ten = 10;
		while(c>='0' && c<='9') 
		{
		  ret += (double)(c-48)/(ten*1.0);
		  ten *= 10;
		  c = gc();
		}	
	}
	return ret;
}

int ri()
{
	char c = gc();
	while((c<'0' || c>'9') && c!='-')
		c = gc();
	int ret = 0, neg = 1;
	if(c == '-')
	{
		neg = -1;
		c = gc();
	}
	while(c>='0' && c<='9')
	{
		ret = 10 * ret + c - 48;
		c = gc();
	}
	return ret * neg;
}

ll rl()
{
	char c = gc();
	while((c<'0' || c>'9') && c!='-')
		c = gc();
	ll ret = 0, neg = 1;
	if(c == '-')
	{
		neg = -1;
		c = gc();
	}
	while(c>='0' && c<='9')
	{
		ret = 10 * ret + c - 48;
		c = gc();
	}
	return ret * neg;		
}

string rs()
{
	char c = gc();
	while(c=='\n' || c==' ')
		c=gc();
	string ret="";
	while(c!=10 && c!=' ')
	{
		ret+=c;
		c=gc();
	}
	return ret;
}

char rc()
{
	char c = gc();
	while(c=='\n' || c==' ')
		c=gc();
	return c;
}


int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t = rl(), caseno = 0;
	while (t--)
	{
		caseno++;
		ll n = rl(), i, j = 1, k = 1, two, minr = INT_MAX, f = 0, bits = 0;
		map <string, ll> m1, m2;
		map <ll, ll> m3, m4;
		vector <pair <ll, ll> > a;
		string s1, s2;
		loop (i, 0, n)
		{
			s1 = rs(); s2 = rs();
			if (m1[s1] == 0)
				m1[s1] = j++;
			if (m2[s2] == 0)
				m2[s2] = k++;
			a.pb(mp(m1[s1], m2[s2]));
		}

		two = (1LL << n);
		loop (i, 0, two)
		{
			//cout << "i = " << i << endl;
			bits = 0;
			m3.clear(); m4.clear();
			j = 0;
			while (j < n)
			{
				if (i & (1LL << j))
				{
					m3[a[j].f] = 1;
					m4[a[j].s] = 1;
					bits++;
				}
				j++;
			}
			j = 0;
			f = 0;
			while (j < n)
			{
				if (! (i & (1LL << j)))
				{
					if (m3[a[j].f] == 0)
					{
						f = 1;
						break;
					}
					if (m4[a[j].s] == 0)
					{
						f = 1;
						break;
					}
				}
				j++;
			}
			if (!f)
				minr = min(minr, bits);
		}
		cout << "Case #" << caseno <<": " << n - minr << endl;
	}
	return 0;
}