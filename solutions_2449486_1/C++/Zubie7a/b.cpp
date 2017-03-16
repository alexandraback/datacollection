/*Santiago Zubieta*/
#include <iostream>
#include <numeric>
#include <fstream>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <iterator>
#include <algorithm>  
#define MAXN 107
using namespace std;

int mat[MAXN][MAXN];
int maxr[MAXN];
int maxc[MAXN];
bool state;
int main(){
	int nCases, n, m;
	cin >> nCases;
	for(int i = 1; i <= nCases; ++i){
		cin >> n >> m;
		state = true;
		for(int j = 0; j < n; ++j){
			maxc[j] = 0; 
		}
		for(int k = 0; k < m; ++k){
			maxr[k] = 0; 
		}
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < m; ++k){
				cin >> mat[j][k];
				maxr[k] = max(mat[j][k], maxr[k]);
				maxc[j] = max(mat[j][k], maxc[j]);
			}
		}
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < m; ++k){
				if(mat[j][k] != maxr[k] && mat[j][k] != maxc[j]){
					state = false;
				}
			}
		}
		printf("Case #%d: %s\n", i, state? "YES" : "NO");
	}
}