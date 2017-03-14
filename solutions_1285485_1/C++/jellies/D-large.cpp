#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<complex>
#define EPS (1e-9)
#define PI (3.141592653589793238)
#define MP make_pair
typedef long long ll;
using namespace std;

int xx,yy;
int d;
int sx,sy;
char board[100][100];

int fx[4]={1,0,0,-1};
int fy[4]={0,1,-1,0};

int ex[4]={1,1,-1,-1};
int ey[4]={1,-1,1,-1};

int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int myround(double x){
	return (int)round(x);
}

int main(void){
	int casenum;
	scanf("%d",&casenum);
	for(int casecnt=1;casecnt<=casenum;casecnt++){

		scanf("%d %d %d",&yy,&xx,&d);
		for(int j=0;j<yy;j++){
			char ch[100];
			scanf("%s",ch);
			for(int i=0;i<xx;i++){
				if(ch[i]=='X'){
					sx=i;
					sy=j;
					ch[i]='.';
				}
				board[i][j]=ch[i];
			}
		}

		int ans=0;
		for(int k=0;k<4;k++){
			int dx=fx[k];
			int dy=fy[k];
			int nx=sx;
			int ny=sy;
			int walk=-1;
			while(1){
				nx+=dx;
				ny+=dy;
				walk++;
				if(board[nx][ny]=='#'){
					dx*=-1;
					dy*=-1;
				}
				if(nx==sx && ny==sy)break;
			}
			if(walk<=d)ans++;
		}

		for(int k=0;k<4;k++){
			vector<vector<bool> > check(60,vector<bool>(60));
			for(int p=1;p<=60;p++){
				for(int q=1;q<=60;q++){
					if(p*p+q*q>d*d)continue;
					{
						int g=gcd(p,q);
						int kp=p/g;
						int kq=q/g;
						bool ok=true;
						for(int i=1;i<=g;i++){
							if(check[kp*i][kq*i]){ok=false;break;}
						}
						if(!ok)continue;
					}
					
					vector<int> root;
					{
						double prey=0;
						double grad=(double)q/p;
						for(int i=0;i<=p;i++){
							double nowy;
							if(i==p){
								nowy=grad*(i);
							}else{
								nowy=grad*(i+0.5);
							}
							int py=myround(prey+EPS);
							int ny=myround(nowy-EPS);
							for(int j=py;j<ny;j++){
								root.push_back(1);
							}
							if(i<p){
								if(fabs(nowy-ny-0.5)<EPS){
									root.push_back(2);
								}else{
									root.push_back(0);
								}
							}
							prey=nowy;
						}
					}

					{
						bool ok=true;
						int px=sx;
						int py=sy;
						int dx=ex[k];
						int dy=ey[k];
						for(int i=0;i<root.size();i++){
							int r=root[i];
							int nx=px;
							int ny=py;
							if(r==0){nx+=dx;}
							if(r==1){ny+=dy;}
							if(r==2){nx+=dx;ny+=dy;}
							if(r==2){
								if(board[nx][ny]=='#'){
									if(board[px][ny]=='.' && board[nx][py]=='.'){
										ok=false;
										nx=px;
										ny=py;
										dx*=-1;
										dy*=-1;
									}else if(board[px][ny]=='#' && board[nx][py]=='#'){
										nx=px;
										ny=py;
										dx*=-1;
										dy*=-1;
									}else if(board[px][ny]=='#' && board[nx][py]=='.'){
										ny=py;
										dy*=-1;
									}else if(board[px][ny]=='.' && board[nx][py]=='#'){
										nx=px;
										dx*=-1;
									}
								}
							}else{
								if(board[nx][ny]=='#'){
									nx=px;
									ny=py;
									if(r==0)dx*=-1;
									if(r==1)dy*=-1;
								}
							}
							px=nx;
							py=ny;
						}
						if(ok && (px==sx && py==sy)){
							ans++;
							check[p][q]=true;
							//printf("[%d](%d,%d)\n",k,p,q);
						}
					}
				}
			}
		}

		printf("Case #%d: %d\n",casecnt,ans);
		fflush(stdout);
	}
	return 0;
}
