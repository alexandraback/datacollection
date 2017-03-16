#include <iostream>
#include <string>
#include <map>
#include <set>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define sz(s) (int)(s).size()
using namespace std;
map<char, char> m;

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	string fs = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
	string sc = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";
	forn(i, sz(fs))
		m[fs[i]] = sc[i];
	m['z'] = 'q';
	m['q'] = 'z';
	set<char> s1;
	for(char c = 'a'; c <= 'z'; c++)
		if(m.count(c))
			s1.insert(m[c]);
	int t;
	scanf("%d\n", &t);
	m[' ' ] = ' ';
	forn(i, t){
		string s;
		getline(cin, s);
		forn(j, sz(s))
			s[j] = m[s[j]];
		printf("Case #%d: %s\n", i + 1, s.c_str());
	}
	return 0;
}