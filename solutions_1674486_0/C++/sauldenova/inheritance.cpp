//inheritance.cpp
//By λKT345

#include<cstdio>

const int MAX_N=1002;

int graph[MAX_N][MAX_N];
bool visited[MAX_N];

bool search(int value) {
	if(visited[value]) {
		return true;
	}
	visited[value]=true;
	for(int i=1; i<=graph[value][0]; i++) {
		if(search(graph[value][i])) {
			return true;
		}
	}
	return false;
}

int main() {
	int T, N, tempSize, inheritance;
	scanf("%d", &T);
	for(int t=1; t<=T; t++) {
		for(int i=0; i<MAX_N; i++) {
			graph[i][0]=0;
		}

		scanf("%d", &N);
		for(int i=1; i<=N; i++) {
			scanf("%d", &tempSize);
			for(int j=1; j<=tempSize; j++) {
				scanf("%d", &inheritance);
				graph[inheritance][++graph[inheritance][0]]=i;
			}
		}
		
		bool possible=false;
		for(int k=1; k<=N; k++) {
			for(int i=0; i<MAX_N; i++) {
				visited[i]=false;
			}
			if(search(k)) {
				possible=true;
				break;
			}
		}
		
		printf("Case #%d: %s\n", t, (possible?"Yes":"No"));
	}
	return 0;
}

