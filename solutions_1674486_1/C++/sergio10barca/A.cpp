#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cstdio>
#define x first
#define y second
#define IN(x, n) (0 <= (x) && (x) < n)
#define MAX 2010
#define MOD 1000000007
#define EPS 0.0001
#define INF 9223372036854775807LL
using namespace std;

typedef long long int entero;
typedef pair<int, int> Point;

vector<int> v[MAX];
int entra[MAX], u[MAX];

void Dfs(int actual){
	int i;
	for(i = 0; i < v[actual].size(); i++){
		if(u[v[actual][i]] == 0){
			u[v[actual][i]]++;
			Dfs(v[actual][i]);
		}
		else
			u[v[actual][i]]++;
	}
	return;
}

int main(){
	int a, m, i, j, k, T, N, ini;
	bool band;
    cin >> T;
    for(k = 1; k <= T; k++){
		cin >> N;
		memset(entra, 0, sizeof(entra));
		band = false;
		for(i = 0; i < N; i++){
			scanf("%d", &m);
			for(j = 0; j < m; j++){
				scanf("%d", &a);
				v[i].push_back(a-1);
				entra[a-1]++;
			}
		}
		ini = 0;
		for(i = 0; i < N && !band; i++){
			if(entra[i] == 0){
				memset(u, 0, sizeof(u));
				ini = i;
				u[i] = 1;
				Dfs(i);
				for(j = 0; j < N; j++)
					if(u[j]>1){
						band = true;
						break;
					}
			}
		}
		if(band)
			printf("Case #%d: Yes\n", k);
		else
			printf("Case #%d: No\n", k);
		for(i = 0; i < N; i++)
			v[i].clear();
    }
    return 0;
}
