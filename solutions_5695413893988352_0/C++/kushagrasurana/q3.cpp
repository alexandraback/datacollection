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

ll mm = INT_MAX, an1, an2;

void f(string &s1, string &s2)
{
	ll no1 = 0, no2 = 0, i, j, k, l, m, n, no11, no111, no22, no222;
	loop (i, 0, 10)
	{
		if (s1[0] == '?')
			no1 = 100 * i;
		else
			no1 = 100 * (s1[0] - '0');
		loop (j, 0, 10)
		{
			if (s1[1] == '?')
				no11 = no1 + 10 * j;
			else
				no11 = no1 + 10 * (s1[1] - '0');
			loop (k, 0, 10)
			{
				if (s1[2] == '?')
					no111 = no11 + k;
				else
					no111 = no11 + (s1[2] - '0');
				loop (l, 0, 10)
				{
					if (s2[0] == '?')
						no2 = 100 * l;
					else
						no2 = 100 * (s2[0] - '0');
					loop (m, 0, 10)
					{
						if (s2[1] == '?')
							no22 = no2 + 10 * m;
						else
							no22 = no2 + 10 * (s2[1] - '0');
						loop (n, 0, 10)
						{
							if (s2[2] == '?')
								no222 = no22 + n;
							else
								no222 = no22 + (s2[2] - '0');
							if (abs(no222 - no111) < mm)
							{
								mm = abs(no222 - no111);
								an1 = no111;
								an2 = no222;
							}
						}
					}
				}
			}
		}
	}
}

void f2(string &s1, string &s2)
{
	ll no1 = 0, no2 = 0, i, j, k, l, m, n, no11, no22;
	loop (i, 0, 10)
	{
		if (s1[0] == '?')
			no1 = 10 * i;
		else
			no1 = 10 * (s1[0] - '0');
		loop (j, 0, 10)
		{
			if (s1[1] == '?')
				no11 = no1 + 1 * j;
			else
				no11 = no1 + 1 * (s1[1] - '0');
			loop (l, 0, 10)
			{
				if (s2[0] == '?')
					no2 = 10 * l;
				else
					no2 = 10 * (s2[0] - '0');
				loop (m, 0, 10)
				{
					if (s2[1] == '?')
						no22 = no2 + 1 * m;
					else
						no22 = no2 + 1 * (s2[1] - '0');
					if (abs(no22 - no11) < mm)
					{
						mm = abs(no22 - no11);
						an1 = no11;
						an2 = no22;
					}
				}
			}
		}
	}
}

ll dig(ll n)
{
	if (n == 0)
		return 1;

	ll ret = 0;
	while (n)
	{
		n /= 10;
		ret++;
	}
	return ret;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t = rl(), caseno = 0;
	while (t--)
	{
		caseno++;
		string s1 = rs(), s2 = rs();
		mm = INT_MAX;
		an1 = 0;
		an2 = 0;
		if (s1.size() == 3)
		{
			f(s1, s2);
			cout << "Case #" << caseno << ": ";
			if (dig(an1) == 1)
				cout << "00";
			else if (dig(an1) == 2)
				cout << "0";
			cout << an1 << " ";
			if (dig(an2) == 1)
				cout << "00";
			else if (dig(an2) == 2)
				cout << "0";
			cout << an2 << endl;
		}
		if (s1.size() == 1)
		{
			if (s1[0] == '?' && s2[0] == '?')
			{
				an1 = 0;
				an2 = 0;
			}
			else
			{
				if (s1[0] == '?')
				{
					an1 = s2[0] - '0';
					an2 = an1;
				}
				else
				{
					if (s2[0] == '?')
					{
						an1 = s1[0] - '0';
						an2 = an1;
					}
					else
					{
						an1 = s1[0] - '0';
						an2 = s2[0] - '0';
					}
				}
			}
			cout << "Case #" << caseno << ": " << an1 << " " << an2 << endl;
		}
		if (s1.size() == 2)
		{
			f2(s1, s2);
			cout << "Case #" << caseno << ": ";
			if (dig(an1) == 1)
				cout << "0";
			cout << an1 << " ";
			if (dig(an2) == 1)
				cout << "0";
			cout << an2 << endl;
		}
	}
	return 0;
}