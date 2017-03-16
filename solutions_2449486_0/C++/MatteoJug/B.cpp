#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define abs(X) ((X)<0?-(X):(X))
#define rst(X) memset(X,0,sizeof(X))
#define pb push_back
#define mp make_pair
#define sz(X) ((int)X.size())
#define ff first
#define ss second

int MX[105][105];

int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		int N, M;
		scanf("%d%d", &N, &M);
		for (int j = 0; j < N; j++)
			for (int z = 0; z < M; z++)
				scanf("%d", &MX[j][z]);
		int tot = 0;
		for (int j = 0; j < N; j++)
			for (int z = 0; z < M; z++){
				bool doable = false;
				int mn = -1;
				for (int a = 0; a < M; a++)
					mn = max(mn, MX[j][a]);
				if (MX[j][z]==mn)
					doable = true;
				mn = -1;
				for (int a = 0; a < N; a++)
					mn = max(mn, MX[a][z]);
				if (MX[j][z]==mn)
					doable = true;
				if (doable)
					tot++;
			}
		//~ cout<<tot<<endl;
		printf("Case #%d: ", i+1);
		if (tot==N*M)
			printf("YES");
		else
			printf("NO");
		printf("\n");
	}
	return 0;
}
