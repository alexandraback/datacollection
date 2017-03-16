#include <cstdio>

bool p[401][401]={};
int pos[401][401];
struct Queue{
	int x,y,d,from;
	char step;
} Q[166000];
int move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool in(int x,int y){
	return x>=-200&&x<=200&&y>=-200&&y<=200&&(!p[x+200][y+200]);
}
char OAO[10]={"ENWS"};
void init(){
	int l=0,r=0;
	Q[r].x=0,Q[r].y=0,Q[r].d=0,Q[r].from=-1,r++;
	p[200][200]=true;
	pos[200][200]=0;
	while (l<r){
		int x=Q[l].x,y=Q[l].y,d=Q[l].d+1;
		//printf("%d %d %d\n",x,y,d);
		//getchar();
		l++;
		for (int i=0;i<4;i++){
			int xx=x+move[i][0]*d,yy=y+move[i][1]*d;
			if (in(xx,yy)){
				p[xx+200][yy+200]=true;
				pos[xx+200][yy+200]=r;
				//putchar(OAO[i]);
				Q[r].x=xx,Q[r].y=yy,Q[r].d=d,Q[r].from=l-1,Q[r].step=OAO[i],r++;
			}
		}
	}
}
char ans[166001];
int main()
{
	init();
	int cases,x,y;
	scanf("%d",&cases);
	for (int t=1;t<=cases;t++){
		scanf("%d %d",&x,&y);
		int tmp=pos[x+200][y+200];
		int num=Q[tmp].d;
		//printf("%d %d\n",num,tmp);
		ans[num]='\0';
		x+=200,y+=200;
		for (int i=0;i<num;i++){
			ans[num-i-1]=Q[tmp].step;
			tmp=Q[tmp].from;
		}
		printf("Case #%d: %s\n",t,ans);
	}
}
