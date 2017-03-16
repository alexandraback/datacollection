# include <bits/stdc++.h>

using namespace std;

int rev( int a){
	int b = 0;
	while(a){
		b = b*10 + a%10;
		a = a/10;
	}
	return b;
}

int mark[1000003] = {0};
int final;

void bfs(){
	queue < pair < int, int > > q;
	q.push(make_pair(1,1));
	while(!q.empty()){
		pair < int, int > x = q.front();
		q.pop();
		if( x.first == final ){
			printf("%d\n",x.second);
			return;
		}
		if( mark[x.first + 1] == 0 ){
			mark[x.first + 1] = 1;
			q.push(make_pair(x.first + 1, x.second + 1));
		}
		if( mark[rev(x.first)] == 0 ){
			mark[rev(x.first)] = 1;
			q.push(make_pair(rev(x.first), x.second + 1));
		}
	}
}

void init(){
	for( int i = 0; i <= 1000000; i++){
		mark[i] = 0;
	}
}
int main(){
	freopen("read.txt", "r", stdin);
	freopen("write.txt", "w", stdout);
	int t;
	scanf("%d\n",&t);
	for( int kr = 1; kr <= t; kr++ ){
		init();
		printf("Case #%d: ",kr);
		int n;
		scanf("%d",&n);
		final = n;
		bfs();
	}
	return 0;
}