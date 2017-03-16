#include<stdio.h>
#include<queue>
#include<string>
#include<string.h>

using namespace std;

#define MAX 305
int px,py;

int mat[305][305];

struct point{
	int x,y;
}x1,x2;

int _r[]={0,0,1,-1};
int _c[]={1,-1,0,0};

string bfs(){
	int i;
	queue<point> Q;
	queue<string> Qs;
	x1.x=105;
	x1.y=105;
	string str="",s="NSEW";
	
	mat[x1.x][x1.y]=0;
	Q.push(x1);
	Qs.push(str);
	
	while(!Q.empty()){
		x1 = Q.front();
		Q.pop();
		
		str = Qs.front();
		//printf("%d %d %s\n",x1.x,x1.y,str.c_str());
		Qs.pop();
		if(x1.x==px && x1.y==py) return str;
		for(i=0;i<4;i++){
			x2.x = x1.x + _r[i]*(mat[x1.x][x1.y]+1);
			x2.y = x1.y + _c[i]*(mat[x1.x][x1.y]+1);
			if(x2.x>=MAX || x2.y>=MAX) continue;
			if(x2.x<0 || x2.y<0) continue;
			if(mat[x2.x][x2.y]!=-1) continue;
			mat[x2.x][x2.y]=mat[x1.x][x1.y]+1;
			Q.push(x2);
			Qs.push(str+s[i]);
		}
		
	}
		
}
int main(){
	int t,n,i,k=0;
	
	freopen("B-small-attempt1.in","r",stdin);
	freopen("output","w",stdout);
	scanf("%d",&t);
	string str;
	while(t--){
		scanf("%d%d",&px,&py);
		px+=105;
		py+=105;
		memset(mat,-1,sizeof(mat));
		
		str = bfs();
		printf("Case #%d: %s\n",++k,str.c_str());
	}
	return 0;	
}
