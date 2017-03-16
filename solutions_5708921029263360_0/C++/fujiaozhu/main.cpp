#include <set>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <vector>
#include <string>
#include <cstdio>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define SIZE(x) (int)x.size()
#define MP(x,y) make_pair(x,y)
#define ALL(t) (t).begin(),(t).end()
#define CLR(x,y) memset(x,y,sizeof(x))
#define FOR(i,n,m) for (int i = n; i <= m; i++)
#define ROF(i,n,m) for (int i = n; i >= m; i--)

#define RI(x) scanf ("%d", &(x))
#define RII(x,y) RI(x),RI(y)
#define RIII(x,y,z) RI(x),RI(y),RI(z)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const ll mod = 1e9 + 7;
const int seed = 105;
const double eps = 1e-8;

/***********************END OF DEFINE******************************/

int t, J, P, S, K;

struct node {
    int x, y, z;
    node () {}
    node (int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("data.out", "w", stdout);
    RI (t);
    FOR (cas, 1, t) {
        RIII (J, P, S); RI (K);
        cout << "Case #" << cas << ": ";
        vector<node> res;
        FOR (i, 1, J) FOR (j, 1, P) FOR (k, 1, S) res.push_back(node(i, j, k));

        while ( K < max(S, max(J, P))) {
            if (S == max(S, max(J, P))) {
                for (int i = 0; i < res.size(); i++) if (res[i].z == S) res[i].x = res[i].y = res[i].z = 0;
                S --;
            }
            else if (P == max(S, max(J, P))) {
                for (int i = 0; i < res.size(); i++) if (res[i].z == P) res[i].x = res[i].y = res[i].z = 0;
                P --;
            }
            else {
                for (int i = 0; i < res.size(); i++) if (res[i].z == J) res[i].x = res[i].y = res[i].z = 0;
                J --;
            }
        }
        int sum = 0;
        for (auto n : res) if (n.x) sum ++;
        cout << sum << endl;
        for (auto n : res) if (n.x) cout << n.x << " " << n.y << " " << n.z << endl;
    }
    return 0;
}

/* B
int mat[51][51];

int main(){
    freopen("B-large.in", "r", stdin);
    freopen("data.out", "w", stdout);
	int T;
	scanf("%d",&T);
	FOR (cas, 1, T){
		int n;
		long long m;
		cin>>n>>m;
		cout << "Case #" << cas << ": ";
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)mat[i][j]=0;
		for(int i=0;i<n-1;i++)for(int j=i+1;j<n-1;j++)mat[i][j]=1;
		if((1LL<<(n-2))>=m){
			printf("POSSIBLE\n");
			mat[0][n-1]=1;
			m=m-1;
			for(int i=1;i<n-1;i++){
				if(m%2==1)mat[i][n-1]=1;
				m=m/2;
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					printf("%d",mat[i][j]);
				}
				printf("\n");
			}
		}else{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
*/



/* A
int t, n;
int a[26];

bool judge() {
    int Mx = -1, sum = 0;
    FOR (i, 0, n - 1) {
        Mx = max(Mx, a[i]);
        if (sum >= 0)
            sum += Mx;
    }
    return sum >= 2 * Mx;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("data.out", "w", stdout);
    RI (t);
    FOR (i, 1, t) {
        RI (n);
        CLR (a, 0);
        FOR (j, 0, n - 1) RI (a[j]);
        cout << "Case #" << i << ": ";
        bool flag = false;
        while (true) {
            int sum = 0;
            FOR (j, 0, n - 1) sum += a[j];
            if (sum <= 0) break;
            int Mx = -1, Mx2 = -1, idx = 0, idx2 = 0;
            FOR (j, 0, n - 1) {
                if (a[j] > Mx) {
                    Mx = a[j];
                    idx = j;
                }
            }
            a[idx] --;
            if (judge()) {
                if (flag)
                    cout << " " << (char)(idx + 'A');
                else {
                    cout << (char)(idx + 'A');
                    flag = true;
                }
                continue;
            }
            FOR (j, 0, n - 1) {
                if (a[j] > Mx2) {
                    Mx2 = a[j];
                    idx2 = j;
                }
            }
            a[idx2] --;
            if (flag)
                cout << " " << (char)(idx + 'A') << (char)(idx2 + 'A');
            else {
                cout << (char)(idx + 'A') << (char)(idx2 + 'A');
                flag = true;
            }
        }
        cout << endl;
    }
    return 0;
}
*/
