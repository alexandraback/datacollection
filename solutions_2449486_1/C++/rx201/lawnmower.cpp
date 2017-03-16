#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

bool solve(int N, int M, int a[100][100]) {
	bool cut[100][100];
	memset(cut, 0 ,sizeof(cut));
	
	for(int i=0 ;i<N; i++)
		for(int j=0; j<M; j++) {
			// verify a[i][j]
			//verify column
			int good = 2;
			for(int k=0; k<N; k++)
				if (a[k][j] > a[i][j]) {
					good--;
					break;
				}
			//verify row
			for(int k=0; k<M; k++)
				if (a[i][k] > a[i][j]) {
					good--;
					break;
				}
			if (good == 0)
				return false;
		}
	return true;
}

int main(int argc, char* argv[]) {
	int T;
	setbuf(stdout, NULL);
	
	//FILE* f = fopen(argv[1], "rt");
	//fscanf(f, "%d\n", &T);
	scanf("%d\n", &T);
	int N, M;
	int a[100][100];
	
	for(int t=0; t<T; t++) {
		//fscanf(f, "%d", &N);
		scanf("%d %d", &N, &M);
		
		for(int i=0; i<N; i++) 
			for(int j=0; j<M; j++)
				scanf("%d", &a[i][j]);
				
		printf("Case #%d: %s\n", t+1, solve(N, M, a) ? "YES": "NO");

	}
	//fclose(f);
	return 0;
}
