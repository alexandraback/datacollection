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
#include <list>
#include <cassert>
#include <conio.h>
using namespace std; 

#define PB push_back 
#define MP make_pair 
#define SZ(v) ((int)(v).size()) 
#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define REP(i,n) FOR(i,0,n) 
#define FORE(i,a,b) for(int i=(a);i<=(b);++i) 
#define REPE(i,n) FORE(i,0,n) 
#define FORSZ(i,a,v) FOR(i,a,SZ(v)) 
#define REPSZ(i,v) REP(i,SZ(v)) 
typedef long long ll; 

/*
struct Node
{
	vector<int> next;
};
*/
bool res;
vector<int> nodes[1001];
int C[1001][1001];
bool visited[1001];

void force(int n)
{
	if (res) return;
	visited[n] = true;
	

	REP(i, nodes[n].size())
		if (visited[nodes[n][i]])
		{
			res = true;
			return;
		}
		else force(nodes[n][i]);

}


int main() {
	freopen("..\\..\\IO Files\\A-large.in", "r", stdin);
	freopen("..\\..\\IO Files\\A-large.out", "w", stdout);

	int T, N;	

	cin >> T;
	REP(i, T)
	{
		cin >> N;
		res = false;
		
		REP(i, 1001) nodes[i].clear();

		//for each node
		REP(k, N)
		{
			int M;
			cin >> M;
			int prev = 0;
			REP(j, M)
			{	
				int ci;
				cin >> ci;
				nodes[k+1].push_back(ci);
			}
		}

		
		memset(C, 0, sizeof(int)*1001*1001);
		REP(i, N)
			REP(j, nodes[i+1].size())
				C[i+1][nodes[i+1][j]] = 1;

		REP(i, N) 
		{
			res = false;
			memset(visited, 0, sizeof(bool)*1001);
			force(i+1);
			if (res) break;
		}
	
		/*
		REP(i, N)
		{
			REP(j, N) cout << C[i+1][j+1] << ' ';
			cout << endl;
		}
		cout << endl;

		REP(i, N)
		{
			REP(j, nodes[i].size())
				cout << "node " << i << ": " << nodes[i][j] << endl;
			
		}
		cout<< endl;
		*/
		
		cout << "Case #" << i+1 << ": ";
		if (res) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	//getch();
	return 0;
}