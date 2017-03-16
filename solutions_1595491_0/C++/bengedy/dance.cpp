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

int N,T,S,P,v;
int main()
{
	cin >> T;
	REP(t,T) {
		int max=0;
		cin >> N >> S >> P;
		REP(i,N) {
			cin >> v;
			if(v >= P+2*std::max(0,P-1)) ++max;
			else if(S && v>=P+2*std::max(0,P-2)) --S, ++max;
		}
		cout << "Case #" << (t+1) << ": " << max << endl;
	}
}