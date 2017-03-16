//Grzegorz Prusak
#include <cstdio>
#include <cstring>

#define REP(i,n)    for(int i=0; i<(n); ++i)
#define FOR(i,p,k)  for(int i=(p); i<=(k); ++i)
#define FORD(i,p,k) for(int i=(p); i>=(k); --i)

template<typename T> struct Point
{
	Point(){} Point(T _x, T _y) : x(_x), y(_y) {} T x,y;
	Point & operator+=(const Point &b){ x+=b.x; y+=b.y; return *this; }
	Point & operator-=(const Point &b){ x-=b.x; y-=b.y; return *this; }
	Point & operator*=(T f){ x*=f; y*=f; return *this; }
	Point & operator/=(T f){ x/=f; y/=f; return *this; }
	Point operator+(const Point &b) const { return Point(x+b.x,y+b.y); } 
	Point operator-(const Point &b) const { return Point(x-b.x,y-b.y); }
	Point operator*(T f) const { return Point(x*f,y*f); }
	Point operator/(T f) const { return Point(x/f,y/f); }
	friend Point operator*(T f, const Point &p){ return Point(f*p.x,f*p.y); }
	T operator*(const Point &b) const { return x*b.x+y*b.y; }
	T vec_mult(const Point &b) const { return x*b.y-y*b.x; }
	
	T sqr() const { return x*x+y*y; }
	Point operator-() const { return Point(-x,-y); }
	bool operator==(const Point &b) const { return x==b.x && y==b.y; }
};

enum { h_max = 100, w_max = 100 };

char B[w_max][h_max];

typedef Point<int> Pi;

int gcd(int a, int b)
{ while(b){ int c=a%b; a=b; b=c; } return a; }

bool valid(int vx, int vy, int ix, int iy)
{
	if(!vx) return !ix && iy && vy==1;
	if(!vy) return !iy && ix && vx==1;
	return ix && iy && gcd(vx,vy)==1;
}

int main()
{
	int T; scanf("%d",&T);
	FOR(_,1,T)
	{
		int H,W,D; scanf("%d%d%d",&H,&W,&D);
		Pi me;
		memset(B,0,sizeof(B));
		REP(y,H) REP(x,W)
		{
			char c; scanf(" %c",&c);
			FOR(xx,2*x+1,2*x+2) FOR(yy,2*y+1,2*y+2) B[xx][yy] = (c=='#');
			if(c=='X') me = Pi(2*x+2,2*y+2);
		}
		H = 2*H+2; W = 2*W+2; D *= 2;
		//REP(y,H){ REP(x,W) printf("%c",B[x][y] ? '#' : '.'); puts(""); }
		//printf("(%d;%d)\n",me.x,me.y);

		int res = 0;
		FOR(_ix,-1,1) FOR(_iy,-1,1)
			REP(vx,D+1) REP(vy,D+1) if(valid(vx,vy,_ix,_iy))
		{
			int ix = _ix, iy = _iy;
			Pi pos = me;
			int dx = 0, dy = 0;
			REP(i,2*D+1)
			{
				if(pos.x<=1 || pos.x>= W-1 || pos.y<=1 || pos.y>=H-1) break;
				int tx = (dx+1)*vy, ty = (dy+1)*vx;
				bool b11 = B[pos.x-(ix<0)+ix][pos.y-(iy<0)+iy];
				bool b10 = B[pos.x-(ix<0)+ix][pos.y-(iy<0)];
				bool b01 = B[pos.x-(ix<0)][pos.y-(iy<0)+iy];
				if(tx<=ty){ dx++; pos.x += ix; if(b10 && (tx!=ty || b11)) ix = -ix; }
				if(tx>=ty){ dy++; pos.y += iy; if(b01 && (tx!=ty || b11)) iy = -iy; }
				if(tx==ty && b11 && !b01 && !b10) break;
				if((tx==ty || !vx || !vy) && pos==me)
				{
					if(dx*dx+dy*dy<=D*D)
					{
						//printf("[%d %d] %d %d\n",vx*_ix,vy*_iy,dx,dy);
						//puts("HIT");
						res++;
					}
					break;
				}
			}
		}
		printf("Case #%d: %d\n",_,res);
	}

	return 0;
}

