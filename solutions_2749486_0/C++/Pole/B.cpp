#include <cstdio>
#include <algorithm>
#include <queue>
#include <bitset>

using namespace std;

const int MAXX=2100000,MAXD=2100;

const int voisins[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const char mvt[]="EWNS";

bitset<MAXD> vu[MAXX];
int dist[MAXX];

void bfs(){
	queue<pair<int,int> > aTraiter;
	aTraiter.push(make_pair(0,0));
	vu[0][0]=true;
	while(!aTraiter.empty()){
		pair<int,int> nouv=aTraiter.front();
		aTraiter.pop();
		int d=1+nouv.second,x=nouv.first;
		for (int i=0;i<2;i++){
			unsigned nx=abs(x+d*voisins[i][0]);
			if (nx<MAXX && !vu[nx][d] && d<MAXD){
				vu[nx][d]=true;
//				printf("%d %d\n",nx,d);
				aTraiter.push(make_pair(nx,d));
			}
		}
	}
	for (int x=0;x<MAXX;x++){
		int d;
		for (d=0;d<MAXD && !vu[x][d];d++) ;
		dist[x]=d;
	}
	dist[0]=0;
}

void resoud(){
	int X,Y;
	scanf("%d%d",&X,&Y);
	vector<char> chaine;
	int d=dist[abs(X)+abs(Y)];
	while (X!=0 || Y!=0){
//		printf("%d,%d : %d\n",X,Y,d);
		for (int i=0;i<4;i++){
			int nx=X+d*voisins[i][0],ny=Y+d*voisins[i][1];
//			printf("test %d,%d : %d\n",nx,ny,dist[abs(ny)+abs(nx)]);
			if (abs(nx)+abs(ny)<MAXX && vu[abs(nx)+abs(ny)][d-1]){
				X=nx;Y=ny;
				chaine.push_back(mvt[i]);
				break;
			}
		}
		d--;
	}
	while(!chaine.empty()){
		printf("%c",chaine.back());
		chaine.pop_back();
	}
	puts("");
}

int main(){
	bfs();
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		printf("Case #%d: ",i+1);
		resoud();
	}
	return 0;
}
