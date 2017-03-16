#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iterator>
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)

int main()
{
	const char* s[] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi"
				 ,"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
				 ,"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	
	const char* t[] = {"our language is impossible to understand"
				 ,"there are twenty six factorial possibilities"
				 ,"so it is okay if you want to just give up"};

	map<char,char> m;
	set<char> rt;	
	m['q']='z'; rt.insert('z');
	REP(i,3) REP(j,strlen(s[i])) { m[s[i][j]]=t[i][j]; rt.insert(t[i][j]); }
	FOR(c,'a','z'+1) FOR(d,'a','z'+1) if(m.count(c) == 0 && rt.count(d) == 0) m[c]=d;

	string A;
	int T;
	cin >> T;
	T=1;
	while(getline(cin,A))
	{
		if(sz(A)==0) continue;
		REP(i,sz(A)) A[i] = m[A[i]];
		cout << "Case #" << T++ << ": " << A << endl;
	}
	return 0;
}