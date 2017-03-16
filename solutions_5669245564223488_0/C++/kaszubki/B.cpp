//Karol Kaszuba
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double D;
typedef long double LD;
typedef vector<PII> VII;

#define FOR(i,x,y) for(int i=(x);i<=(y);++i)
#define REP(i,x) FOR(i,0,(x)-1)
#define FORD(i,x,y) for(int i=(x);i>=(y);--i)
#define VAR(i,c) __typeof(c) i=(c)
#define FORE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)

#define SIZE(c) (int)((c).size())
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define IN insert
#define ER erase
#define MP make_pair
#define ST first
#define ND second
#define IOSYNC ios_base::sync_with_stdio(0)

const LL MOD = 1000000007;
LL silnia[105];

string make_simpler(string s)
{
	string res = "";
	int i = 0, n = SIZE(s);
	while(i < n)
	{
		int j = -1;
		while(i + j + 1 < n && s[i + j + 1] == s[i]) j++;
		res.PB(s[i]);
		i = i + j + 1;
	}
	return res;
}
struct lit
{
	int pocz, kon, mid;
};

lit tab[26];

struct dfds
{
	int prev,next,kolor;
};
dfds graf[105];

int maluj(int m)
{
	int kolorek = 0, a;
	REP(i, m)
	{
		if(!graf[i].kolor)
		{
			kolorek++;
			graf[i].kolor = kolorek;
			
			a = i;
			
			while(graf[a].prev != -1)
			{
				a = graf[a].prev;
				if(graf[a].kolor) return -100000;
				graf[a].kolor = kolorek;
			}
			
			a = i;
			
			while(graf[a].next != -1)
			{
				a = graf[a].next;
				if(graf[a].kolor) return -100000;
				graf[a].kolor = kolorek;
			}
		}
	}
	return kolorek;
}

LL jebaj()
{
	LL res = 1;
	int n;
	int addon[26]; REP(i, 26) addon[i] = 0;
	
	string s;
	vector <string> v;
	cin >> n;
	
	REP(i, n)
	{
		cin >> s;
		s = make_simpler(s);
		if(SIZE(s) == 1)
		{
			addon[s[0] - 'a']++;
		}
		else
		{
			v.PB(s);
		}
	}
	
	REP(i, 26)
	{
		tab[i].pocz = -1;
		tab[i].kon = -1;
		tab[i].mid = -1;
	}
	
	REP(i, 26)
	{
		REP(j, SIZE(v))
		{
			if(v[j][0] - 'a' == i)
			{
				if(tab[i].pocz != -1 || tab[i].mid != -1) return 0;
				tab[i].pocz = j;
			}
			if(v[j][SIZE(v[j]) - 1] - 'a' == i)
			{
				if(tab[i].kon != -1 || tab[i].mid != -1) return 0;
				tab[i].kon = j;
			}
			FOR(k, 1, SIZE(v[j]) - 2)
			{
				if(v[j][k] - 'a' == i)
				{
					if(tab[i].pocz != -1 || tab[i].kon != -1 || tab[i].mid != -1) return 0;
					tab[i].mid = j;
				}
			}
		}
	}
	
	REP(i, 26)
		if(tab[i].mid != -1 && addon[i]) return 0;
	
	REP(i, 26)
	{
		if(tab[i].pocz >= 0 || tab[i].kon >= 0)
		{
			res = (res * silnia[addon[i]]) % MOD;
			addon[i] = 0;
		}
	}
	int ile_rzeczy = 0;
	REP(i, 26)
	{
		if(addon[i])
		{
			res = (res * silnia[addon[i]]) % MOD;
			ile_rzeczy++;
		}
	}
	
	int m = SIZE(v);
	REP(i, m)
	{
		graf[i].prev = tab[v[i][0] - 'a'].kon;
		graf[i].next = tab[v[i][SIZE(v[i]) - 1] - 'a'].pocz;
		graf[i].kolor = 0;
	}
	
	ile_rzeczy += maluj(m);
	if(ile_rzeczy < 0) return 0;
	res = (res * silnia[ile_rzeczy]) % MOD;
	return res;
}

void prepro()
{
	silnia[0] = 1;
	FOR(i, 1, 100)
	{
		silnia[i] = silnia[i - 1] * i;
		silnia[i] = silnia[i] % MOD;
	}
}

int main()
{
	IOSYNC;
	int t;
	//t = 1;
	cin >> t;
	
	prepro();
	REP(i, t) 
	{
		cout << "Case #" << i + 1 << ": ";
		cout << jebaj() << "\n";
	}
}
