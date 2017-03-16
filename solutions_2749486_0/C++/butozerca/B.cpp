#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define F first
#define S second
#define MP make_pair
using namespace std;

char map[300][300];


int BFS(int x, int y){
	queue<pair<pair<int,int>,int> > q;
	q.push(MP(MP(100,100),1));
	char moves[501];
	while(!q.empty()){
		pair<pair<int,int>, int > a = q.front();
		if(a.F.F==x && a.F.S==y)return a.S-1;
		if(a.S>500)break;
		q.pop();
		
		if(a.F.S+a.S<=200 && map[a.F.F][a.F.S+a.S]==0){
			map[a.F.F][a.F.S+a.S] = 'N';
			q.push(MP(MP(a.F.F,a.F.S+a.S),a.S+1) );
		}
		if(a.F.S-a.S>=0 && map[a.F.F][a.F.S-a.S]==0){
			map[a.F.F][a.F.S-a.S] = 'S';
			q.push(MP(MP(a.F.F,a.F.S-a.S),a.S+1) );
		}
		if(a.F.F+a.S<=200 && map[a.F.F+a.S][a.F.S]==0){
			map[a.F.F+a.S][a.F.S] = 'E';
			q.push(MP(MP(a.F.F+a.S,a.F.S),a.S+1) );
		}
		if(a.F.F-a.S >=0 && map[a.F.F-a.S][a.F.S]==0){
			map[a.F.F-a.S][a.F.S] = 'W';
			q.push(MP(MP(a.F.F-a.S,a.F.S),a.S+1) );
		}
	}
}


int main(){
	int Z;
	scanf("%d",&Z);
	for(int q = 1; q <= Z; ++q){
		for(int i = 0; i<210; ++i)for(int j = 0; j<210; ++j)map[i][j] = 0;
		int x, y;
		scanf("%d %d", &x, &y);
		x+=100; y+=100;
		int r;
		char moves[501];
		r = BFS(x,y);
		int x1 = x, y1 = y;
		while(r!=0){
//			printf("%d %d %d\n",r,x1,y1);
			moves[r-1] = map[x1][y1];
			if(moves[r-1]=='N')y1-=r;
			if(moves[r-1]=='S')y1+=r;
			if(moves[r-1]=='E')x1-=r;
			if(moves[r-1]=='W')x1+=r;
			r--;
		}
		printf("Case #%d: %s\n",q, moves);
		for(int i = 0; i < 501; ++i)moves[i] = 0;
	}
	return 0;
}

