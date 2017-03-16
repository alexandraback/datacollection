#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstring>

using namespace std;

int reverse(int x){
	int num;

	num = 0;

	while(x){
		num *= 10;
		num += (x%10);
		x /= 10;
	}

	return num;
}


int Q[10000010];
int H,T;
int visited[10000010];
int dist[10000010];

int bfs(int n){
	memset(visited,0,sizeof(visited));
	H = T = 0;
	Q[T++] = 1;
	visited[1] = 1;
	dist[1] = 1;
	int v;

	while(H < T){
		v = Q[H++];

		if(v == n) return dist[v];

		if(!visited[v+1] && v+1 < (1e7)){
			visited[v+1] = 1;
			Q[T++] = v+1;
			dist[v+1] = dist[v]+1;
		}

		int r = reverse(v);

		if(!visited[r]){
			visited[r] = 1;
			Q[T++] = r;
			dist[r] = dist[v]+1;
		}
	}

	return dist[n];
}

int main(){

	int n;
	int t,t2;

	cin >> t2;

	for(t = 1; t <= t2; ++t){

		cin >> n;
		cout << "Case #" << t << ": " << bfs(n) << "\n";
	}

	return 0;
}
