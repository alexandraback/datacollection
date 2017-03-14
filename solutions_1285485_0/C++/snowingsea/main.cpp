#include <stdio.h>
#include <math.h>
#include <queue>
#include <set>
using namespace std;
#define eps 1e-7
struct point{
	double x,y;
	point(){}
	point(double x, double y):x(x),y(y){}

	bool operator < (const point& p) const {
		if(x == p.x) return y < p.y;
		return x < p.x;
	}
	point operator -(const point& p){ return point(x-p.x,y-p.y); }
	double len(){ return sqrt(x*x+y*y); }
};
set<point> s;
double a[100000];
queue<point> q;
char board[40][40];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,h,w,d;
	int cas=1,i,j;
	scanf("%d",&t);
	while (t--)
	{
		s.clear();
		while(!q.empty()) q.pop();
		scanf("%d%d%d",&h,&w,&d);
		for(i = 0;i < h;i++)
			scanf("%s",board[i]);
		//board[5][5] = 'X';
		for (i = 0;i < h;i++)
			for(j = 0;j < w;j++)
				if(board[i][j] == 'X')
					q.push(point(j+0.5,i+0.5));

		point p = q.front();
		s.insert(p);
		while (!q.empty())
		{
			double x = q.front().x;
			double y = q.front().y;
			q.pop();
			point pp = point(x,2-y);
			if((pp-p).len() < d+eps && s.find(pp) == s.end()){
				s.insert(pp);
				q.push(pp);
			}
			pp = point(2-x,y);
			if((pp-p).len() < d+eps && s.find(pp) == s.end()){
				s.insert(pp);
				q.push(pp);
			}
			pp = point(x,2*h-2-y);
			if((pp-p).len() < d+eps && s.find(pp) == s.end()){
				s.insert(pp);
				q.push(pp);
			}
			pp = point(2*w-2-x,y);
			if((pp-p).len() < d+eps && s.find(pp) == s.end()){
				s.insert(pp);
				q.push(pp);
			}
		}
		s.erase(p);
		int n = 0;
		for (set<point>::iterator it = s.begin();it != s.end();it++)
		{
			point pp = (*it) - p;
			a[n++] = atan2(pp.y,pp.x);
		}
		sort(a,a+n);
		int k = 1;
		for(i = 1;i < n;i++)
			if(a[i] - a[k-1] > eps)
				a[k++] = a[i];
		printf("Case #%d: %d\n",cas++,min(k,n));
	}


	return 0;
}