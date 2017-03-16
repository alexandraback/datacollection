//Karol Kaszuba

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef double D;
typedef long double LD;
typedef vector<PII> VII;
typedef unordered_set<int> USI;
typedef unordered_set<LL> USLL;

#define FOR(i,x,y) for(auto i=(x);i<=(y);++i)
#define REP(i,x) FOR(i,0,(x)-1)
#define FORD(i,x,y) for(auto i=(x);i>=(y);--i)
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
#define FREOPEN(f) freopen(f, "r", stdin),freopen(f, "w", stdout)

int hehe[1000][1000];
LD pp[102][102], ev[102][102], prawd[1000];

LD jebaj()
{
	FOR(i, 0, 500) prawd[i] = 0;
	FOR(i, 0, 100) FOR(j, 0, 100)
	{
		pp[i][j] = 0;
		ev[i][j] = 0;
	}
	
	int k, l, n;
	cin >> k >> l >> n;
	VI ile(300);
	string klaw; cin >> klaw; 
	
	unordered_set<char> literki;
	
	for(auto a : klaw) 
	{
		literki.IN(a);
		ile[a]++;
	}
	string target; cin >> target;
	
	for(auto a : target) if(ile[a] == 0) return 0;
	
	set<string> prefiksy;
	
	string pref_t;
	prefiksy.IN(pref_t);
	for(auto a : target)
	{
		pref_t.PB(a);
		prefiksy.IN(pref_t);
	}
	
	for(auto literka : literki)
	{
		prawd[literka] = ile[literka];
		prawd[literka] /= ((LD)k);
	}
	
	
	for(auto pref : prefiksy)
	{
		for(auto literka: literki)
		{
			string act = pref; act.PB(literka);
			int wyn_act = 0;
			string bla;
			FORD(i, SIZE(act) - 1, 0)
			{
				bla.PB(act[i]);
				reverse(ALL(bla));
				if(prefiksy.find(bla) != prefiksy.end()) wyn_act = max(wyn_act, SIZE(act) - i);
				reverse(ALL(bla));
			}
			
			hehe[SIZE(pref)][literka] = wyn_act;
		}
	}
	
	string longest_prefsuf;
	string tmp;
	FORD(i, SIZE(target) - 1, 1)
	{
		tmp.PB(target[i]);
		reverse(ALL(tmp));
		if(prefiksy.find(tmp) != prefiksy.end()) longest_prefsuf = tmp;
		reverse(ALL(tmp));
	}
	
	int ps_len = SIZE(longest_prefsuf);
	
	int ile_bananow = 1 + (n - l) / (l - ps_len);
	
	
	pp[0][0] = 1;
	ev[0][0] = 0;
	
	FOR(i, 1, n)
	{	
		FOR(pop_ps, 0, l)
		{
			for(auto literka : literki)
			{
				int len = hehe[pop_ps][literka];
				//cout << pop_ps << " " << literka << " " << len << "\n";
				pp[i][len] += prawd[literka] * pp[i - 1][pop_ps];
				ev[i][len] += prawd[literka] * ev[i - 1][pop_ps];
			}
		}
		ev[i][l] += pp[i][l];
		
	}
	
	LD res = 0;
	FOR(i, 0, l)
	{
		//cout << ev[n][i] * pp[n][i] << " "; cout << "\n";
		res += ev[n][i];// * pp[n][i];
	}
	
	res = ile_bananow - res;
	
	return res;
}

int main()
{
	IOSYNC;
	int t = 1;
	cin >> t;
	
	REP(i, t)
	{
		cout << "Case #" << i + 1 << ": ";
		cout << fixed << setprecision(8) << jebaj() << "\n";;
	}
}
