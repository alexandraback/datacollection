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
	int T,A,B,P[10]={1};
	cin >> T;
	FOR(i,1,10) P[i]=10*P[i-1];
	REP(t,T)
	{
		int S=0;
		cin >> A >> B;
		FOR(x,A,B+1)
		{
			int d=1;
			while(x / P[d]) ++d;
			
			set<int> s;
			FOR(i,1,d)
			{
				int y=x/P[i] + (x%P[i])*P[d-i];
				if(x!=y && y<=B && y>x) s.insert(y);
			}
			S += sz(s);
		}
		cout << "Case #" << (t+1) << ": " << S << endl;
	}
	return 0;
}