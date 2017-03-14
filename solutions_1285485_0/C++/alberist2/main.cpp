#include <cstdio>
#include <vector>
#include <deque>
#include <cstdlib>
#include <set>
#include <algorithm>

using namespace std;

int h,w,d,xc,yc;
char s[50][50];

int gcd(int a,int b)
{
	while(a!=0)
	{
		b = b%a;
		swap(a,b);
	}
	return abs(b);
}

void rotate(int &x,int &start_x,int &new_x,int cx)
{
	if (x>=start_x)
	{
		x = 2*new_x-x-1;
		start_x = 2*new_x-start_x-1;
	}
	else
	{
		x = 2*new_x-x+1;
		start_x = 2*new_x-start_x+1;
	}
	new_x = cx;
}

bool check(int &x,int &y,int &start_x,int &start_y,int cx,int cy,int &new_x,int &new_y)
{
	if (s[new_x][new_y]!='#')
		return false;
	if (new_x!=cx && new_y!=cy)
	{
		if (s[new_x][cy]!='#' && s[cx][new_y]!='#')
			return true;
		if (s[new_x][cy]=='#' && s[cx][new_y]=='#')
		{
			rotate(x,start_x,new_x,cx);
			rotate(y,start_y,new_y,cy);
		}
		else if (s[new_x][cy]!='#')
			rotate(y,start_y,new_y,cy);
		else
			rotate(x,start_x,new_x,cx);
	}
	else if (new_x == cx)
		rotate(y,start_y,new_y,cy);
	else
		rotate(x,start_x,new_x,cx);
	return false;
}

int ii,jj;

bool move(int x,int y)
{
	int cx = xc, cy = yc;
	int start_x = xc,start_y = yc;
	for(;;)
	{
		int new_x=cx,new_y=cy;
		if (x==cx)
		{
			if (y>cy)
				new_y++;
			else
				new_y--;
		}
		else if (y==cy)
		{
			if (x>cx)
				new_x++;
			else
				new_x--;
		}
		else
		{
			/*if (x>cx)
				new_x++;
			else
				new_x--;
			new_y = (y-start_y)*(new_x-start_x)/(x-start_x)+start_y;
			if (abs(new_x-cx)+abs(new_y-cy)>1)*/
			{
				int tx1 = cx,ty1 = cy;
				if (x>cx)
					tx1++;
				else
					tx1--;
				int tx2 = cx,ty2 = cy;
				if (y>cy)
					ty2++;
				else
					ty2--;
				int dist1 = abs((tx1-x)*(start_y-y)-(ty1-y)*(start_x-x));
				int dist2 = abs((tx2-x)*(start_y-y)-(ty2-y)*(start_x-x));
				if (dist1<dist2)
				{
					new_x = tx1;
					new_y = ty1;
				}
				else if (dist1>dist2)
				{
					new_x = tx2;
					new_y = ty2;
				}
				else
				{
					new_x = tx1;
					new_y = ty2;
				}
			}
		}
		if (check(x,y,start_x,start_y,cx,cy,new_x,new_y))
			return 0;
		cx = new_x;
		cy = new_y;

		if (cx==x && cy==y)
		{
			if (x==xc && y==yc)
				return 1;
			else
				return 0;
		}
		if (cx==xc && cy==yc)
			if (x==start_x || ((y-start_y)*(cx-start_x)/(x-start_x)+start_y==cy) && ((y-start_y)*(cx-start_x))%(x-start_x)==0)
			{
				//printf("%d %d\n",ii-xc,jj-yc);
				return 1;
			}
	}
}

void solve(int t)
{
	int ans=0;
	scanf("%d%d%d",&h,&w,&d);
	set<pair<int,int> > ss;
	for (int i=0;i<h;++i)
	{
		scanf("%s",s[i]);
		for (int j=0;j<w;++j)
			if (s[i][j]=='X')
				xc = i, yc = j;
	}
	for (int i=xc-d;i<=xc+d;i++)
		for (int j=yc-d;j<=yc+d;++j)
			if ((xc-i)*(xc-i)+(yc-j)*(yc-j)<=d*d && (xc!=i || yc!=j))
			{
				ii = i;
				jj = j;
				int dim = gcd(xc-i,yc-j);
				pair<int,int> o = make_pair((xc-i)/dim,(yc-j)/dim);
				if (ss.count(o)==1)
					continue;
				if (move(i,j))
				{
					ss.insert(o);
					ans++;
				};
			}
	printf("Case #%d: %d\n",t,ans);
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for (int t=0;t<T;++t)
		solve(t+1);
	return 0;
}
