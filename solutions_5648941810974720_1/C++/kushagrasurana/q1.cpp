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
		string s = rs(), ans = "";
		vl a;
		ll cnt[26] = {0}, i, j, k;
		loop (i, 0, s.size())
		{
			cnt[s[i] - 'A']++;
		}
		while (cnt['Z' - 'A'])
		{
			a.pb(0);
			cnt['Z' - 'A']--;
			cnt['E' - 'A']--;
			cnt['R' - 'A']--;
			cnt['O' - 'A']--;
		}
		while (cnt['W' - 'A'])
		{
			a.pb(2);
			cnt['T' - 'A']--;
			cnt['W' - 'A']--;
			cnt['O' - 'A']--;
		}
		while (cnt['X' - 'A'])
		{
			a.pb(6);
			cnt['S' - 'A']--;
			cnt['I' - 'A']--;
			cnt['X' - 'A']--;
		}
		while (cnt['S' - 'A'])
		{
			a.pb(7);
			cnt['S' - 'A']--;
			cnt['E' - 'A']--;
			cnt['V' - 'A']--;
			cnt['E' - 'A']--;
			cnt['N' - 'A']--;
		}
		while (cnt['G' - 'A'])
		{
			a.pb(8);
			cnt['E' - 'A']--;
			cnt['I' - 'A']--;
			cnt['G' - 'A']--;
			cnt['H' - 'A']--;
			cnt['T' - 'A']--;
		}
		while (cnt['U' - 'A'])
		{
			a.pb(4);
			cnt['F' - 'A']--;
			cnt['O' - 'A']--;
			cnt['U' - 'A']--;
			cnt['R' - 'A']--;
		}
		while (cnt['R' - 'A'])
		{
			a.pb(3);
			cnt['T' - 'A']--;
			cnt['H' - 'A']--;
			cnt['R' - 'A']--;
			cnt['E' - 'A']--;
		}
		while (cnt['V' - 'A'])
		{
			a.pb(5);
			cnt['F' - 'A']--;
			cnt['I' - 'A']--;
			cnt['V' - 'A']--;
			cnt['E' - 'A']--;
		}
		while (cnt['O' - 'A'])
		{
			a.pb(1);
			cnt['O' - 'A']--;
			cnt['N' - 'A']--;
			cnt['E' - 'A']--;
		}
		while (cnt['I' - 'A'])
		{
			a.pb(9);
			cnt['I' - 'A']--;
		}
		sort(all(a));
		cout << "Case #" << caseno << ": ";
		loop (i, 0, a.size())
			cout << a[i];
		cout << endl;
	}
	return 0;
}