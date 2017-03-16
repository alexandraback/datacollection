#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 

using namespace std; 


#define PI acos(-1)
#define CLEAR(A) memset(A,0,sizeof(A))
#define SETMAX(A) memset(A,0x7f,sizeof(A))
#define SETM1(A) memset(A,-1,sizeof(A))
#define SQ(A) (A)*(A)

int T;
int N;
int edges[1002][11];
int M[1002];
int seen[1002];


int dfs(int i) {
	seen[i]++;
	if(seen[i] > 1) return 0;
	for(int j=0;j<M[i];j++) {
		dfs(edges[i][j]);
	}
}

bool f() {
	for(int i=1;i<=N;i++) {
		CLEAR(seen);
		dfs(i);
		for(int j=1;j<=N;j++) if(seen[j] > 1) return true;
	}
	return false;
}

int main()
{
	cout << setprecision(9) ;
	cin >> T;
	for(int i=1;i<=T;i++) {
		cin >> N;
		for(int j=1;j<=N;j++) {
			cin >> M[j];
			for(int k=0;k<M[j];k++) {
				cin >> edges[j][k];
			}
		}
		if(f()) {
			cout << "Case #" << i << ": " << "Yes" << endl;
		} else {
			cout << "Case #" << i << ": " << "No" << endl;
		}
	}
	return 0;
}


