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
#include <iomanip>
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)

int S[500];

int main()
{
	int T;
	cin >> T;
	REP(t,T)
	{
		int N;
		cin >> N;

		int X = 0;
		REP(i,N) { cin >> S[i]; X += S[i]; }

		//sort(S,S+N);

		cout << "Case #" << (t+1) << ":";

		REP(i,N)
		{
			double l=0, r=1;
			while( r-l > 0.0000000001 )
			{
				double m = (r+l)/2.0;
				double s = 0;
				REP(j,N)
				{
					double v = ((X*m + S[i]) - S[j]) / (double)X;
					if(v > 0)
					s += v;
				}

				if(s > 1)
					r = m;
				else
					l = m;
			}

			cout << " " << setprecision(10) <<  l * 100.0;
		}
		cout << endl;		
	}
	return 0;
}