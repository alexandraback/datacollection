
#include <cmath>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct pt
{
	long x;
	long y;

	pt(){}
	pt(long x_,long y_):x(x_),y(y_){}
	long abs2(){return x*x+y*y;}

	pt operator+(const pt &p)const{return pt(x+p.x,y+p.y);}
	pt operator-(const pt &p)const{return pt(x-p.x,y-p.y);}
	bool operator==(const pt &p)const{return x==p.x && y==p.y;}

	bool operator<(const pt &p)const
	{
		if(x<p.x)return true;
		if(x>p.x)return false;
		if(y<p.y)return true;
		if(y>p.y)return false;
		return false;
	}
};

bool samesign(long a, long b)
{
	if(a>0 && b>0)return true;
	if(a<0 && b<0)return true;
	return false;
}

double pow2(double x)
{
	return x*x;
}

int sgn(long a)
{
	if(a<0)return -1;
	if(a>0)return 1;
	return 0;
}

// index:(x-1)+(y-1)*50 1<=x,y<=50
vector<pt> simplifytable;

pt simplify0(pt p)
{
	int mx=max(abs(p.x),abs(p.y));
	for(int i=mx;i>=2;--i)
	{
		if(p.x%i==0 && p.y%i==0)
		{
			p.x/=i;
			p.y/=i;
		}
	}

	return p;
}

void gensimplifytable()
{
	simplifytable.resize(50*50);
	for(int y=1;y<=50;++y)
	{
		for(int x=1;x<=50;++x)
		{
			if(y>x)
				continue;
			int idx=(x-1)+(y-1)*50;
			simplifytable[idx]=simplify0(pt(x,y));
		}
	}
}

pt simplify(pt p)
{
	if(p.x==0 && p.y==0)
		return p;
	if(p.x==0)
		return pt(0,sgn(p.y));
	if(p.y==0)
		return pt(sgn(p.x),0);

	int ax=abs(p.x);
	int ay=abs(p.y);
	if(ax>50 || ay>50)
		return simplify0(p);

	int sgx=sgn(p.x);
	int sgy=sgn(p.y);

	if(simplifytable.empty())
		gensimplifytable();

	pt q;
	if(ay>ax)
	{
		q=simplifytable[(ay-1)+(ax-1)*50];
		swap(q.x,q.y);
	}
	else
	{
		q=simplifytable[(ax-1)+(ay-1)*50];
	}
	return pt(q.x*sgx, q.y*sgy);
}

bool samedir(const pt &a, const pt &b)
{
	if(a.x==0 && b.x==0)
		return samesign(a.y,b.y);
	if(a.y==0 && b.y==0)
		return samesign(a.x,b.x);
	if(!samesign(a.x,b.x) || !samesign(a.y,b.y))
		return false;

	return simplify(a) == simplify(b);
}

vector< vector<int> > field;
pt player;
int dist;

void loadfield()
{
	field.clear();

	int w,h;
	cin>>h>>w>>dist;

	field.resize(h);
	for(int y=0;y<h;++y)
	{
		field[y].resize(w);
		for(int x=0;x<w;++x)
		{
			char c;
			cin>>c;
			field[y][x] = (c=='#')?1:0;
			if(c=='X')
			{
				player.x=x;
				player.y=y;
			}
		}
	}
}

bool at(pt p)
{
	return field[p.y][p.x];
}

void adddir(vector<pt> &ps, pt &p)
{
	for(int i=0;i<ps.size();++i)
	{
		if(samedir(ps[i],p))
		{
			if(ps[i].abs2()<p.abs2())
				ps[i]=p;
			return;
		}
	}
	ps.push_back(p);
}

vector<pt> dirs;

void gendirs(int dst)
{
	dirs.clear();
	int dst2=dst*dst;
	for(int x=1;x<=dst;++x)
	{
		for(int y=1;y<=dst;++y)
		{
			pt p(x,y);
			if(p.abs2() > dst2)
				continue;

			adddir(dirs,p);
		}
	}

	int sz=dirs.size();

	dirs.reserve(sz*4+4);

	// clone every dir
	pt pts[]={pt(-1,1),pt(-1,-1),pt(1,-1)};
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<sz;++j)
		{
			dirs.push_back(pt(dirs[j].x*pts[i].x, dirs[j].y*pts[i].y));
		}
	}

	dirs.push_back(pt(dst,0));
	dirs.push_back(pt(-dst,0));
	dirs.push_back(pt(0,dst));
	dirs.push_back(pt(0,-dst));
}

pt reflect(pt p, pt dir, bool xref, bool yref)
{
	if(!xref && !yref)
		return dir;

	if(xref && yref)
	{
		pt dn( (dir.x<0)?-1:0, (dir.y<0)?-1:0);
		pt dx( -1-dn.x, dn.y);
		pt dy( dn.x, -1-dn.y);
		bool an=at(p+dn);
		bool ax=at(p+dx);
		bool ay=at(p+dy);
		if(!an)
		{
			return dir;
		}
		if(!ax && !ay)
		{
			return pt(0,0); // destroy
		}
		if(ax && ay)
		{
			return pt(-dir.x, -dir.y);// ref both
		}
		if(ax)
		{
			return pt(dir.x, -dir.y);//ref y
		}
		//else
		{
			return pt(-dir.x, dir.y); // ref x
		}
	}
	if(xref)
	{
		if(at(p)||at(p+pt(-1,0)))
		{
			return pt(-dir.x, dir.y);
		}
		return dir;
	}
	//yref
	{
		if(at(p)||at(p+pt(0,-1)))
		{
			return pt(dir.x,-dir.y);
		}
		return dir;
	}
}

bool run(pt dir)
{
	pt sdir=simplify(dir);

	// enh coord
	long xa=max(abs(sdir.y),1l);
	long ya=max(abs(sdir.x),1l);

	pt cur;
	cur.x=(player.x*2+1)*xa;
	cur.y=(player.y*2+1)*ya;

	long xdiv=xa*2;
	long ydiv=ya*2;

	pt org=cur;

	pt curdir(sgn(dir.x), sgn(dir.y));

	long maxstep=max(abs(dir.x*xdiv), abs(dir.y*ydiv));

	for(int i=0;i<maxstep;++i)
	{
		cur=cur+curdir;

		if(cur == org)
		{
			return true;// reached image of player
		}

		bool xref=cur.x%xdiv==0;
		bool yref=cur.y%ydiv==0;
		if(xref||yref)
		{
			curdir = reflect( pt(cur.x/xdiv, cur.y/ydiv), curdir, xref, yref);
			if(curdir==pt(0,0))
			{
				return false;//destroyed
			}
		}
	}

	return false;
}

void dbg()
{
	cout<<"player"<<endl;
	cout<<player.x<<" "<<player.y<<endl;
	cout<<"dirs"<<endl;
	for(int i=0;i<dirs.size();++i)
	{
		cout<<dirs[i].x<<" "<<dirs[i].y<<endl;
	}
}

int solve()
{
	loadfield();
	gendirs(dist);

	int img=0;
	for(int i=0;i<dirs.size();++i)
	{
		bool ok = run(dirs[i]);
		if(ok)
		{
			++img;
		}
	}

	return img;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cout<<"Case #"<<i+1<<": "<<solve()<<endl;
	}

	return 0;
}
