#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)>(b)?(b):(a))
#define N 100
using namespace std;

int mp[N + 10][N + 10];
int clo[N + 10];
int row[N + 10];
int main ()
{
	int n, m;
	int t, cases = 1;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &mp[i][j]);
		memset(clo, -1, sizeof(clo));
		memset(row, -1, sizeof(row));
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				clo[j] = MAX(clo[j], mp[i][j]);
				row[i] = MAX(row[i], mp[i][j]);
			}
		}
		int flag = 0;
		for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			if(mp[i][j] < clo[j] && mp[i][j] < row[i]){
				flag = 1;
				goto out;
			}
		}
		out:;
		if(flag == 1){
			printf("Case #%d: NO\n", cases++);
		}else{
			printf("Case #%d: YES\n", cases++);
		}
	}
    return 0;
}
