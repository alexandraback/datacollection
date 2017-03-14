#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define mp make_pair

const	double eps=1e-9;

struct jilu {
	int x,y;
}que[200000];

int		n,m,d,res,stx,sty;
int		dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
set < pair<int,int> > hash,hash2;
char	s[110][110];
bool	Map[1024][1024];

int	gcd(int a,int b)
{	return	!b ? a:gcd(b,a%b);	}

inline double Dist(int x,int y,int xx,int yy)
{	return	sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));	}

inline void Bfs(int sx,int sy){
	int head=0,tail=1,x,y,fx,fy,dx,dy,G;
	que[1].x=sx;
	que[1].y=sy;
	hash.insert(mp(sx,sy));
	int dx1=(sx-1)*2+1,dx2=(n-sx)*2+1;
	int	dy1=(sy-1)*2+1,dy2=(m-sy)*2+1;
	
	while (head++<tail){
		x=que[head].x;
		y=que[head].y;
		
		for (int i=0;i<4;i++){
			int XX=abs(x-sx),YY=abs(y-sy);
			
			if (!i){
				if ((XX%(2*n))==0)
					fx=x-dx1;
				else
					fx=x-dx2;
				fy=y;
			}
			if (i==1){
				if ((XX%(2*n))==0)
					fx=x+dx2;
				else
					fx=x+dx1;
				fy=y;
			}
			if (i==2){
				fx=x;
				if ((YY%(2*m))==0)
					fy=y-dy1;
				else
					fy=y-dy2;
			}
			if (i==3){
				fx=x;
				if ((YY%(2*m))==0)
					fy=y+dy2;
				else
					fy=y+dy1;
			}
			if (abs(fx-sx)>d || abs(fy-sy)>d)
				continue;
			if (hash.find(mp(fx,fy))!=hash.end())
				continue;
			else{
				++tail;
				que[tail].x=fx;
				que[tail].y=fy;
				dx=fx-sx;
				dy=fy-sy;
				G=gcd(abs(dx),abs(dy));
				dx/=G,dy/=G;
				hash.insert(mp(fx,fy));
				if (Dist(sx,sy,fx,fy)<d+eps){
					if (hash2.find(mp(dx,dy))!=hash2.end())
						continue;
					else{
						res++;
						// printf("%d %d\n",dx,dy);
						hash2.insert(mp(dx,dy));				
					}
				}
			}
		}		
	}
}

int main(){
	freopen("s.in","r",stdin);
	freopen("s.out","w",stdout);
	
	int test,t=0;
	
	for (scanf("%d",&test);test--;){
		t++;
		scanf("%d%d%d",&n,&m,&d);
		
		for (int i=1;i<=n;i++)
			scanf("%s",s[i]);
		
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		if (s[i][j-1]=='X'){
			stx=i-1;
			sty=j-1;
			break;
		}
		n-=2,m-=2;
		res=0;
		hash.clear();
		hash2.clear();
		Bfs(stx,sty);
		printf("Case #%d: %d\n",t,res);
	}
	
	return 0;
}
