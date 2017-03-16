#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define X 10
#define T (1<<X)

typedef long long ll;

int adjMat[1005][1005];
int nPaths[1005][1005];
int visited[1005];
int a , b;
int n;

int noOfPaths(int u) {
    int ans = 0;
    if(u == b) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if(!visited[i] && adjMat[u][i]) {
                ans += noOfPaths(i);
        }
    }
    return ans;
}

void compute() {
    int i , j ,k;
    REP(k,n){
        REP(i,n) {
            REP(j,n) {
                    int ans = 0;
                    if(adjMat[i][k] == 1)
                        ans +=  nPaths[k][j];
                    nPaths[i][j] = ans;
            }
        }
    }
}

void main2(void){
    cin>>n;
    int i , j;
    REP(i , n) {
        int m;
        cin>>m;
        REP(j,m) {
            int t;
            cin>>t;
            t--;
            adjMat[i][t] = 1;
        }
    }
    int ok = false;
    REP(i,n) {
        REP(j,n) {
            b = j;
            memset(visited , 0 , sizeof(visited));
            int t = noOfPaths(i);
            if(t >= 2) {
                ok = true;
                break;
            }
        }
    }
    if(ok) cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    memset(adjMat , 0 , sizeof(adjMat));
    memset(visited , 0 , sizeof(visited));
}

int main(void){
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	int tc,t;
	cin >> tc;
	REP(t,tc){
		printf("Case #%d: ",t+1);
		main2();
	}
	return 0;
}
