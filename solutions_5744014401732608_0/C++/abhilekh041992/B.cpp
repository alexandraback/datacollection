#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<iomanip> 
#include<utility> 
#include<climits>
#include<climits>
#include<cmath>
#include<algorithm>


using namespace std;


#define LL long long int
#define sc1(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define sc3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define pr1(x) printf("%d\n", x)
#define FOR(i, a, n) for(int i=a;i<n;i++)
#define pp pair<int, int>
#define pb push_back 

#define MAX 1000001
#define MOD 1000000007LL

int mat[100][100];



bool func(int b, int n, LL m) {
	LL limit = 1LL << (b-2);
	if(m > limit) {
		return false;
	}

	if(m == limit) {
		FOR(i, 0, b) {
			FOR(j, i+1, b) {
				mat[i][j] = 1;
			}
		}
		return true;
	}


	LL half = 1LL << (b-3);

	if(m >= half) {
		FOR(i, 0, b) {
			FOR(j, i+1, b-1) {
				if((i != 1) && (j != 1)) {
					mat[i][j] = 1;
				}
			}
			if((i != 1) && (i < (b-1))) mat[i][n-1] = 1;
		}
		if(half == m) return true;

		LL left = m - half - 1;
		mat[0][1] = 1;
		mat[1][n-1] = 1;

		FOR(i, 0, b-2) {
			if(left & (1LL<<i)) {
				mat[i+2][1] = 1;
			}
		}
		return true;
	} else {
		return func(b-1, n, m);
	}
}

int main() {

	int t, b;
	LL m;

	cin>>t;
	FOR(i, 1, t+1) {
		cin>>b>>m;

		memset(mat, 0, sizeof(mat));
		cout<<"Case #"<<i<<":";
		
		if(func(b, b, m)) {
			cout<<" POSSIBLE"<<endl;
			FOR(i, 0, b) {
				FOR(j, 0, b) {
					cout<<mat[i][j];
				}
				cout<<endl;
			}
		} else {
			cout<<" IMPOSSIBLE"<<endl;
		}

		
	}
	return 0;
}













