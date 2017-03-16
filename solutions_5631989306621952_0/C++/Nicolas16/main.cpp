#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
#define REP(i, a, b) for(int i = int(a); i <= int(b); i++)
#define LOOP(i, v) for(int i = 0; i < v.size(); i++)
#define EPS 1e-9
#define INF 1e12
#define debug(x) cerr << "DEBUG : " << (#x) << " => " << (x) << endl

int main()
{
	int T;
	string s;
	
	scanf("%d\n", &T);
	
	REP(t, 1, T)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d: ", t);
		
		getline(cin, s);
		
		int a = s.size();
		int oudebut = 0;
		int oufin = a-1;
		string rep;
		rep.resize(a);
		
		while(a > 0)
		{
			char best = 0;
			int x = -1;
			for(int i = a-1; i >= 0; i--)
			{
				if(s[i] > best)
				{
					best = s[i];
					x = i;
				}
			}
			rep[oudebut] = s[x];
			oudebut++;
			for(int j = a-1; j > x; j--)
			{
				rep[oufin] = s[j];
				oufin--;
			}
			a = x;
		}
		
		cout << rep << endl;
		
	}

  return 0;
}
