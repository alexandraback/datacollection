#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<cassert>
using namespace std;
#define X first
#define Y second
#define RED 0
#define GREEN 1
#define BLUE 2
typedef long long LL;
//typedef __int128_t VL;
typedef long double LD;

int N, M;
int a[103][103];

bool possible_one(int x, int y){
	int maxx = 0;
	for(int i = 0; i < N; i++)
		maxx = max(a[i][y], maxx);
	if(a[x][y] == maxx)
		return true;
	maxx = 0;
	for(int j = 0; j < M; j++)
		maxx = max(a[x][j], maxx);
	if(a[x][y] == maxx)
		return true;
	return false;
}

bool possible(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(!possible_one(i, j))
				return false;
	return true;
}

int main(){
	int testy;
	scanf("%d", &testy);
	for(int t = 1; t <= testy; t++){
		scanf("%d %d", &N, &M);
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				scanf("%d", &a[i][j]);
		printf("Case #%d: ", t);
		if(possible())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
