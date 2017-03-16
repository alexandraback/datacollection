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

#define MAXN 20
#define MAXV 10000

int V[MAXN];
int C[MAXV*MAXN+1];
int P[MAXV*MAXN+1][MAXN+1];

int main()
{
	int T;
	cin >> T;
	REP(t,T)
	{
		int N;
		cin >> N;
		REP(i,N) cin >> V[i];

		REP(i,MAXV*MAXN+1) C[i] = 0;

		C[0] = 1;
		P[0][0] = 0;

		REP(i,N)
		{
			for(int v=MAXV*MAXN; v>0; --v)
			{
				if(v - V[i] >= 0 && C[v-V[i]])
				{
					P[v][C[v]]=V[i];
					C[v]++;
				}
			}
		}

		set<int> a, b;
		FOR(v,1,MAXV*MAXN+1)
		{
			if(C[v] < 2) continue;
			
			int rem = v-P[v][0];
			a.insert(P[v][0]);		
			while(rem > 0)
			{
				a.insert(P[rem][0]);
				rem -= P[rem][0];
			}
				
			rem = v-P[v][1];
			b.insert(P[v][1]);		
			while(rem > 0)
			{
				b.insert(P[rem][0]);
				rem -= P[rem][0];
			}
			break;
		}

		for(auto it=a.begin(); it!=a.end(); ++it)
		{
			if(b.count(*it)) b.erase(*it);
		}

		for(auto it=b.begin(); it!=b.end(); ++it)
		{
			if(a.count(*it)) a.erase(*it);
		}
		
		cout << "Case #" << (t+1) << ":" << endl;
		if(a.size() && b.size())
		{
			for(auto it=a.begin(); it!=a.end(); ++it)
				cout << *it << " ";
			cout << endl;
			for(auto it=b.begin(); it!=b.end(); ++it)
				cout << *it << " ";
			cout << endl;
		}
		else
		{
			cout << "Impossible" << endl;
		}
	}
	return 0;
}