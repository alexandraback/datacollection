#include <bits/stdc++.h>


using namespace std;


#define fr(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
#define MAX 400
int t;
struct no{
	int r,c,n;
	no(){}
	no(int R, int C, int N){r = R, c = C, n = N; }
};


bool mk[MAX][MAX][500];
pii prv[MAX][MAX][500];
no fila[MAX*MAX*500+1000];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
bool valid(int a, int b){
	return a >= 0 && a < MAX && b >= 0 && b < MAX;
}




int main(){
	scanf("%d",&t);
	mk[MAX/2][MAX/2][0] = true;
	prv[MAX/2][MAX/2][0] = pii(-1,-1);
	int in =0, fi = 0;
	fila[fi++] = no(MAX/2,MAX/2,0);
	while(in < fi){
		no now = fila[in++];
		fr(i,0,4){
			int nx = now.r + dx[i]*(now.n+1), ny = now.c + dy[i] * (now.n+1);
			if(valid(nx,ny) && now.n != 500 && mk[nx][ny][now.n+1] == false){
				mk[nx][ny][now.n+1] = true;
				prv[nx][ny][now.n+1] = pii(now.r,now.c);
				fila[fi++] = no(nx,ny,now.n+1);
			}
		}
	}
	fr(cas,1,t+1){
		int x,y;
		scanf("%d %d",&x,&y);
		x += MAX/2, y += MAX/2;
		printf("Case #%d: ",cas);
		int n = 0;
		while(!mk[x][y][n]) n++;
		stack<char> s;
		while(n){
			pii aux = prv[x][y][n];
			if(aux.F > x) s.push('W');//printf("E");
			else if(aux.F < x) s.push('E');//printf("W");
			else if(aux.S > y) s.push('S');//printf("N");
			else s.push('N');//printf("S");
			x = aux.F, y = aux.S;
			n--;
		}
		while(!s.empty()){
			char aux = s.top(); s.pop();
			printf("%c",aux);
		}
		puts("");
	}
	return 0;
}






























