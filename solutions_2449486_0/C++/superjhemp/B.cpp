#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

bool solve(){
	int N, M, H[200], G[100][100];
	memset(H, 0, sizeof(H));
	cin>>N>>M;
	for (int r=0; r<N; r++)
		for (int c=0; c<M; c++){
			cin>>G[r][c];
			H[c+0] = max( H[c+0], G[r][c]);
			H[r+M] = max( H[r+M], G[r][c]);
		}
	for (int r=0; r<N; r++)
		for (int c=0; c<M; c++)
			if (G[r][c] != min(H[c+0],H[r+M]))
				return false;
	return true;
}

int main(){
	int T;
	cin>>T;
	for (int t=0; t<T; t++)
		printf("Case #%d: %s\n",t+1,solve()?"YES":"NO");
	return 0;
}
