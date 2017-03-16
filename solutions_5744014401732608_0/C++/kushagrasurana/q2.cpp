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

ll mat[50][50];

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t = rl(), caseno = 0;
	while (t--)
	{
		caseno++;
		ll b = rl(), m = rl(), i, j, k, maxx = 0;
		
		loop (i, 0, 50)
			loop (j, 0, 50)
				mat[i][j] = 0;
		maxx = 1LL << (b - 2);
		cout << "Case #" << caseno << ": ";
		if (maxx < m)
			cout << "IMPOSSIBLE" << endl;
		else
		{
			cout << "POSSIBLE" << endl;
			k = 1;
			loop (i, 1, b - 1)
				loop (j, i + 1, b)
					mat[i][j] = 1;
			// for first row now.
			maxx /= 2;
			if (maxx == 0)
			{
				maxx = 1;
				k--;
			}
			j = 1;
			while (m)
			{
				if (maxx <= m)
				{
					mat[0][j] = 1;
					m -= maxx;
				}
				maxx /= 2;
				if (maxx == 0 && k)
				{
					maxx = 1;
					k = 0;
				}
				j++;
			//	cout << "maxx= " << maxx << "m=" << m << endl;
			}
			
			loop (i, 0, b)
			{
				loop (j, 0, b)
					cout << mat[i][j];
				cout << endl;
			}
		}
	}
	return 0;
}