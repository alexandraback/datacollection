#include<iostream>
#include<math.h>
using namespace std;

//#define CYDONIA_DEBUG

//库

struct POINT{
	int x,y;
	POINT()
	{
		x=0;
		y=0;
	}
	POINT(int a,int b)
	{
		x=a;
		y=b;
	}
	POINT operator+(const POINT& p)
	{
		POINT ret;

		ret.x = x + p.x;
		ret.y = y + p.y;

		return ret;
	}
	POINT operator-(const POINT& p)
	{
		POINT ret;

		ret.x = x - p.x;
		ret.y = y - p.y;

		return ret;
	}
	POINT operator*(const int& c)
	{
		POINT ret(x,y);

		ret.x *= c;
		ret.y *= c;

		return ret;
	}
	bool operator == (const POINT& p)
	{
		return x == p.x && y == p.y;
	}
	bool operator != (const POINT& p)
	{
		return x!=p.x && y !=p.y;
	}
};

bool inDistance(const POINT&a, const POINT&b, const int& distance)
{
	int x = a.x-b.x;
	int y = a.y-b.y;
	return x*x+y*y <= distance*distance;
}

int gcd(int a,int b){
	int c;
	while(b){
		c=b;
		b=a%b;
		a=c;
	}
	return a;
}

// 问题变量

#define MAXW 100
#define MAXH 100
char space[MAXH][MAXW];
char world[MAXH][MAXW];
int T,W,H,D;
POINT myPosition, reflection, me;
int kx,ky;
int cx,cy;
double gridStep;

void findMyPosition()
{
	int i,j;
	for(i=0;i<H;++i)
	{
		for(j=0;j<W;++j)
		{
			if('X' == space[i][j]){
				myPosition.x = i;
				myPosition.y = j;
				return;
			}
		}
	}
}

POINT getRelativePoint(const POINT& p)
{
	POINT ret(p.x/kx, p.y/ky);
	return ret;
}

POINT getRelativePoint(int x, int y)
{
	POINT ret(x/kx, y/ky);
	return ret;
}

bool isOnEdge(const POINT&p)
{
	return 0==p.x || 0==p.y || H == p.x+1 || W==p.y+1;
}

bool isMirror(const POINT&p)
{
	return '#'==world[p.x][p.y];
}

int once_run(POINT direction, int d)
{
	int remainD = d;
	int c;
	POINT pos = me;
	POINT realp;
	POINT pp,px,py;
	bool ff,fx,fy;

	
	//cout<<"pos:"<<pos.x<<","<<pos.y<<endl;
	while(remainD>0){

		c = min(cx,cy);

		pos = pos + direction*c;
		remainD-=c;
		//cout<<"direction:"<<direction.x<<","<<direction.y<<endl;
		//cout<<remainD<<"!!!"<<pos.x<<" "<<pos.y<<"!!!"<<c<<"!!!"<<(direction*c).x<<endl;

		if(remainD && pos ==me) return 0;

		realp = getRelativePoint(pos);
		if(isOnEdge(realp)) return 0;

		cx-=c;
		cy-=c;

		if(0==cx) cx=kx;
		if(0==cy) cy=ky;

		//反射

		if(-1 == direction.x){
			if(-1 == direction.y){
				pp = pos + direction;
				px = pp; px.y += 1;
				py = pp; py.x += 1;
			}else{
				py = pos;
				pp = py; pp.x -= 1;
				px = pp; px.y -= 1;
			}
		}else{
			if(-1 == direction.y){
				px = pos;
				pp = px; pp.y -= 1;
				py = pp; py.x -= 1;
			}else{
				pp = pos;
				px = pp; px.y -= 1;
				py = pp; py.x -= 1;
			}
		}

		ff=isMirror(getRelativePoint(pp));
		if(ff){
			fx=isMirror(getRelativePoint(px));
			fy=isMirror(getRelativePoint(py));
			if(fx){
				if(fy){
					direction.x = -direction.x;
					direction.y = -direction.y;
				}else{
					direction.x = -direction.x;
				}
			}else{
				if(fy){
					direction.y = -direction.y;
				}else{
					return 0;
				}
			}
		}
	}

	if(pos == me) return 1;

	return 0;
}

int run_mult(POINT direction, int d)
{
	int ret=0;
	int remainD=d;

	POINT pos = myPosition;
	POINT judge;

	//cout<<"!!!"<<endl;
	while(remainD>0){
		
		pos = pos + direction;
		if(isOnEdge(pos)) break;
		//cout<<pos.x<<","<<pos.y<<endl;
		--remainD;
		if(pos == myPosition) return 1;

		if(direction.x){
			if(direction.x>0){
				judge = pos;
			}else{
				judge = pos + direction;
			}
		}else{
			if(direction.y>0){
				judge = pos;
			}else{
				judge = pos + direction;
			}
		}

		if(isMirror(judge)){
			direction.x = -direction.x;
			direction.y = -direction.y;
		}
	}

	return ret;
}

int run_light()
{
	POINT delta = reflection - myPosition;
	POINT direction;

	//init direction
	if(0 < delta.x) direction.x = 1;
	else if(delta.x < 0) direction.x = -1;
	else direction.x = 0;

	if(0 < delta.y) direction.y = 1;
	else if(delta.y < 0) direction.y = -1;
	else direction.y = 0;

	if(0 == delta.x){
		return 0;
	}
	if(0 == delta.y){
		return 0;
	}


	delta.x = abs(delta.x);
	delta.y = abs(delta.y);
	int g = gcd(delta.x, delta.y);

	kx = delta.y/g;
	ky = delta.x/g;
	cx = kx;
	cy = ky;

	me.x = myPosition.x*kx;
	me.y = myPosition.y*ky;

	double xx = 1.0/kx, yy = 1.0/ky;
	int d = delta.x*kx;
	//cout<<d<<"!!!!"<<delta.x<<" "<<delta.y<<endl;

	gridStep = sqrt(xx*xx + yy*yy);
	return once_run(direction, d);
}

void init_world()
{
	int i,j,i2,j2;
	for(i=0;i<H;++i)
	{
		for(j=0;j<W;++j)
		{
			i2=i*2; 
			j2=j*2;
			if('X' == space[i][j]){
				myPosition.x=i2+1;
				myPosition.y=j2+1;
			}
			
			world[i2][j2]=world[i2+1][j2]=world[i2][j2+1]=world[i2+1][j2+1]=space[i][j];
		}
	}
	H*=2;
	W*=2;
	D*=2;
}

int solve()
{
	init_world();
	int ret=0;
	const int ones[] = {-1,1};
	int i,j;
	POINT lp,rp,dir;
	lp.x = myPosition.x - D;
	lp.y = myPosition.y - D;
	rp.x = myPosition.x + D;
	rp.y = myPosition.y + D;

	ret+=run_mult(POINT(-1,0),D);
	ret+=run_mult(POINT(1,0),D);
	ret+=run_mult(POINT(0,-1),D);
	ret+=run_mult(POINT(0,1),D);

	//system("pause");

	for(reflection.x=lp.x;reflection.x<=rp.x;++reflection.x)
	{
		for(reflection.y=lp.y;reflection.y<=rp.y;++reflection.y)
		{
			if(reflection.x == myPosition.x || reflection.y == myPosition.y) continue;
			//cout<<"myPosition: "<<myPosition.x<<","<<myPosition.y<<endl;
			//cout<<"reflection: "<<reflection.x<<","<<reflection.y<<endl;
			if(myPosition!=reflection&&inDistance(myPosition, reflection, D))
			{
				if(run_light()){
					++ret;
					//cout<<"+1"<<endl;system("pause");
				}
			}
		}
	}

	return ret;
}

int main()
{
#ifndef CYDONIA_DEBUG
	freopen("D-small-attempt1.in", "r", stdin);
    freopen("D-small-attempt1.out", "w", stdout);
#endif
	int i,j;
	scanf("%d",&T);
	for(int ti=1;ti<=T;++ti)
	{
		scanf("%d%d%d\n",&H,&W,&D);
		for(i=0;i<H;++i)
		{
			scanf("%s",space[i]);
		}
		printf("Case #%d: %d\n",ti,solve());
	}
	
#ifdef CYDONIA_DEBUG
	//system("pause");
#endif
	return 0;
}