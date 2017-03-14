#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;
const int N=35,D=51;

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
struct Frac{
	int n,d;
	Frac(int _n=0,int _d=1):n(_n),d(_d){
		if (d<0){
			n=-n;
			d=-d;
		}
		int g=gcd(abs(n),d);
		n/=g;
		d/=g;
	}
	double todouble(){
		return double(n)/d;
	}
};
Frac operator +(Frac a,Frac b){
	return Frac(a.n*b.d+a.d*b.n,a.d*b.d);
}
Frac operator -(Frac a,Frac b){
	return Frac(a.n*b.d-a.d*b.n,a.d*b.d);
}
Frac operator *(Frac a,Frac b){
	return Frac(a.n*b.n,a.d*b.d);
}
Frac operator /(Frac a,Frac b){
	return Frac(a.n*b.d,a.d*b.n);
}
bool operator <(Frac a,Frac b){
	return a.n*b.d < a.d*b.n;
}
bool operator >=(Frac a,Frac b){
	return a.n*b.d >= a.d*b.n;
}
bool operator ==(Frac a,Frac b){
	return a.n*b.d == a.d*b.n;
}
int floor(Frac a){
	return a.n/a.d;
};
int ceil(Frac a){
	return (a.n+a.d-1)/a.d;
}
int sgn(int a){
	if (a > 0)
		return 1;
	if (a < 0)
		return -1;
	return 0;
}
Frac sooner(Frac a,Frac b){
	if (a.d == 0)
		return b;
	if (b.d == 0)
		return a;
	return std::min(a,b);
}
struct point{
	Frac x,y;
	point(){}
	point(Frac _x,Frac _y):x(_x),y(_y){}
};
double Dis(point a,point b){
	double cx=a.x.todouble()-b.x.todouble();
	double cy=a.y.todouble()-b.y.todouble();
	return sqrt(cx*cx+cy*cy);
}
char map[N][N];
int w,h,d;
Frac sx,sy;
point touchgrid(point s,int dx,int dy){
	int fx,cx,fy,cy,tx,ty;
	Frac t;
	fx=floor(s.x);
	cx=ceil(s.x);
	fy=floor(s.y);
	cy=ceil(s.y);
	if (fx==cx)	tx=fx+sgn(dx);else tx=dx>0?cx:fx;
	if (fy==cy)	ty=fy+sgn(dy);else ty=dy>0?cy:fy;
	t=sooner((Frac(tx)-s.x)/Frac(dx),(Frac(ty)-s.y)/Frac(dy));
	return point(s.x+Frac(dx)*t,s.y+Frac(dy)*t);
}
void reflect(point s,int &dx,int &dy){
	int fx,cx,fy,cy,tx,ty;
	fx=floor(s.x);
	cx=ceil(s.x);
	fy=floor(s.y);
	cy=ceil(s.y);
	if (fx==cx)	tx=dx>0?fx:fx-1;  else tx=fx;
	if (fy == cy)	ty=dy>0?fy:fy-1;else ty=fy;
	if (map[tx][ty]=='#'){
		if (fx==cx && fy!=cy)	dx=-dx;	
			else if (fx!=cx && fy==cy) dy=-dy;
				else if (fx == cx && fy == cy){
					if (map[tx-sgn(dx)][ty] == '#' && map[tx][ty-sgn(dy)] == '#'){
						dx=-dx;
						dy=-dy;
					}	else if (map[tx-sgn(dx)][ty] == '#')	dy=-dy;
						else if (map[tx][ty-sgn(dy)] == '#')  dx=-dx;	else{
							dx=0;
							dy=0;
						}
				}
	}
}
bool orign(point s,int dx,int dy,double dis){
	int fx,cx,fy,cy,tx,ty;
	fx=floor(s.x);
	cx=ceil(s.x);
	fy=floor(s.y);
	cy=ceil(s.y);
	if (fx==cx)	tx=dx>0?fx:fx-1; else	tx=fx;
	if (fy==cy)	ty=dy>0?fy:fy-1; else	ty=fy;
	if (map[tx][ty]=='X')	{
		if (sx==s.x && dx==0 && (sy-s.y)/Frac(dy)>=0)	return 1;
		if (sy==s.y && dy==0 && (sx-s.x)/Frac(dx)>=0)	return 1;
		if ((sx-s.x)/Frac(dx)==(sy-s.y)/Frac(dy) && (sx-s.x)/Frac(dx)>=0)
		if (Dis(point(sx,sy),s)+dis<=d) return 1;
	}
	return 0;
}
bool simulate(point s,int dx,int dy){
	double dis=0;
	point t;
	while (1){
		t=touchgrid(s,dx,dy);
		dis+=Dis(s,t);
		s=t;
		reflect(s,dx,dy);
		if (dis>d || (dx==0 && dy==0))return 0;
		if (orign(s,dx,dy,dis))	return 1;
	}
}
int main(){
	int T,c,i,j,ans;
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	scanf("%d",&T);
	for (c=1;c<=T;c++){
		ans=0;
		scanf("%d%d%d",&h,&w,&d);
		for (i=0;i<h;i++)
			for (j=0; j < w; j++){
				scanf("\n%c",&map[i][j]);
				if (map[i][j] == 'X'){
					sx=Frac(i)+Frac(1,2);
					sy=Frac(j)+Frac(1,2);
				}
			}
		for (i=-2*d; i <= 2*d; i++)
			for (j=-2*d; j <= 2*d; j++)	if (gcd(abs(i),abs(j))==1){
				if (simulate(point(sx,sy),i,j)) ans++;
			}
		printf("Case #%d: %d\n",c,ans);
	}
	return 0;
}
