#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <cstdlib>

using namespace std;

const int tmax = (int)1e3 + 100;

#define pb push_back
#define mp make_pair

int matrix[tmax][tmax];

int maxvC[tmax];
int maxvL[tmax];
int n,m;

void getMax(){
	for( int i = 0; i < n; i++){
		maxvL[i] = 0;	
		for( int j = 0; j < m; j++)
			maxvL[i] = max(maxvL[i],matrix[i][j]);		
	}
	for( int j = 0; j < m; j++){
		maxvC[j] = 0;
		for( int i = 0; i < n; i++)
			maxvC[j] = max(maxvC[j], matrix[i][j]);		
	}
}

int main()
{
	/*freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-outp-small.out", "w", stdout);*/
	int t, tt = 1;
	scanf("%d", &t);
	while(t--){
		
		scanf("%d %d",&n, &m);
		for( int i = 0; i < n; i++)
			for( int j = 0; j < m; j++)
				scanf("%d", &matrix[i][j]);
		getMax();
		bool flag = true;
		printf("Case #%d: ", tt++);
		for( int i = 0; i < n; i++)
			for( int j = 0; j < m; j++){
				int va = matrix[i][j];
				if( maxvL[i] > va && maxvC[j] > va ) flag = false;
			}
		if(flag) printf("YES\n");
		else printf("NO\n");
	
	}
	
	return 0;
}

