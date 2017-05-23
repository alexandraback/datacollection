#include<cstdio>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

long long int reverse(long long int n){
	long long int rev =0;
	while(n){
		rev*=10;
		rev+=(n%10);
		n/=10;
	}
	return rev;
}
long long int bfs(int n){
	queue<long long int> cola;
	map<long long int, long long int> dist;
	cola.push(1); dist[1] = 1;
	while(!cola.empty()){
		long long int front = cola.front(); cola.pop();
		if(front==n) return dist[front];
		long long int rev = reverse(front);
		if(dist.count(rev)==0){
			dist[rev] = dist[front]+1;
			cola.push(rev);
		}
		if(dist.count(front+1)==0){
			dist[front+1] = dist[front]+1;
			cola.push(front+1);
		}
	}	
	return dist[n];
}
int main(){
	int t;
	long long int n;
	//FILE *pFile;
	//pFile = fopen("output small a.txt","w");
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%lld",&n);
		printf("Case #%d: %d\n",i,bfs(n));
		//fprintf(pFile,"Case #%d: %d\n",i,bfs(n));
	}
	//fclose(pFile);
	return 0;
}
