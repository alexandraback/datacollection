/*
AUTHOR : VUAcoder
LANGUAGE : C++
PROBLEM :
*/
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
#include<set>
#include<fstream>
#include<cfloat>
using namespace std;
#define PI (2.*acos(0.))
#define EPS 1e-9
#define ZERO(x)     (fabs(x) < EPS)
#define EQ(a,b)     (ZERO((a)-(b)))
#define LESSER(a,b) (!EQ(a,b) && (a)<(b))
#define GREATER(a,b)(!EQ(a,b) && (a)>(b))
#define GETBIT(x,i) (x&(1<<i))
#define SETBIT(x,i) (x|(1<<i))
#define FORab(i,a,b) for(typeof(b) i=(a);i<=(b);i++)
#define FOR(i,n) FORab(i,0,(n)-1)
#define FOR1(i,n) FORab(i,1,n)
#define FORit(it,a) for( typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define all(a) (a).begin(),(a).end()
#define ms(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define sz(a) (int)a.size()
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define px first
#define py second
//#define __eXYZ__
#ifdef __eXYZ__
//USE THESE FOR DEBUG
#define RFILE(a)    freopen(a, "r", stdin)
#define WFILE(a)    freopen(a, "w", stdout)
#define _r(arg) {dbg,arg; dbg.start(); }
#define _n(arg...) {_r(#arg " ==> ");dbg,arg; }
#define _(arg...) { _n(arg); dbg.nl(); }
#else
#define RFILE(a)
#define WFILE(a)
#define _n(arg) {}
#define _n(arg...) {}
#define _(arg...) {}
#endif


typedef long long  LL;
typedef vector<int>   vi;
typedef pair<int,int>  pii;

template<class A, class B> ostream &operator<<(ostream& o, pair<A,B>& p) { //pair print
	return o << "("<<p.first<<", "<<p.second<<")";
}

template<class T> ostream& operator<<(ostream& o, const vector<T>& v) { //vector print
	o << "{";FORit(it, v) o << *it << ", "; return o << "}";
}

struct debugger
{
	ostream &out; bool first;
	void start() { first = true; }
	debugger(ostream& out):out(out) {start();}
	void nl() { out << '\n'; start(); }
	// Taken from rudradevbasak
	template<class T> debugger& operator,(T& v) {
		if(first) first = false; else out << ", ";
		out << v; return *this;
	}
	template<class T> debugger& operator,(pair<T*,int> arr) { //array print
		out << "{";
			FOR(i, arr.second) { out << arr.first[i] << ", "; }
		out << "}";
		return *this;
	}
} dbg(cerr);
int dist(int x1,int y1,int x2,int y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int ABS(int a)
{
	if(a>=0)return a;
	return -a;
}
map<pii,int>mp;
int inmap(int x1,int y1,int x2,int y2)
{
	int dx=x1-x2,dx1;
	int dy=y1-y2,dy1;
/*	if(dx==0)dy/=ABS(dy);
	else if(dy==0)dx/=ABS(dx);
	else*/
	{
		dx1=dx/__gcd(ABS(dx),ABS(dy));
		dy1=dy/__gcd(ABS(dx),ABS(dy));
	}
	if(mp[pii(dx1,dy1)])return 1;
	//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<dx<<" "<<dy<<" ";
	//cout<<dx1<<" "<<dy1<<endl;
	mp[pii(dx1,dy1)]=1;
	return 0;
}
char gr[1000][1000];
int main()
{
	ios_base::sync_with_stdio(0);
	RFILE("input.txt");
	WFILE("output2.txt");
	string grid[100];
	int cn=1,r,c,d,n,m,t,xa,ya;
	cin>>t;
	while(t--)
	{
		cin>>r>>c>>d;
		mp.clear();
		FOR(i,r)
		{
			cin>>grid[i];
		}

		FOR(i,r)
			FOR(j,c)
			{
				if(grid[i][j]=='X')
				{
					xa=i-1;
					ya=j-1;
				}
			}
		n=2*(r-2);
		m=2*(c-2);
		int x[5],y[5];
		x[0]=xa*2+1;
		y[0]=ya*2+1;

		x[2]=x[0];
		y[2]=m-y[0];

		x[1]=n-x[0];
		y[1]=y[0];

		x[3]=n-x[0];
		y[3]=m-y[0];
		d*=2;
		//_(n,m);;
		//_(x[0],y[0],x[1],y[1],x[2],y[2],x[3],y[3]);
		int c=0;
		/*for(int i=-d*n;i<=(d+1)*n;i++)
				for(int j=-d*m;j<=(d+1)*m;j++)
					{
						gr[i+d*n][j+d*m]='.';
					}
		gr[x[0]+d*n][y[0]+d*m]='X';*/
		for(int i=-d;i<=d+1;i++)
			for(int j=-d;j<=d+1;j++)
			{
				int ind=(abs(j)%2)*2+(abs(i)%2);
				int tx=i*n+x[ind];
				int ty=j*m+y[ind];
				if(tx==x[0]&&ty==y[0])continue;
				//cout<<i<<" "<<j<<" "
				if(dist(tx,ty,x[0],y[0])<=d*d)
					{
						if(!inmap(tx,ty,x[0],y[0]))
						{
							c++;
							//gr[tx+d*n][ty+d*m]='#';
//							cout<<tx<<" "<<ty<<" "<<tx-x[0]<<" "<<ty-y[0]<<" "<<ABS(tx-x[0])<<" "<<ABS(ty-y[0])<<" "<<__gcd(ABS(tx-x[0]),ABS(ty-y[0]))<<" ";
	//						cout<<(tx-x[0])/__gcd(ABS(tx-x[0]),ABS(ty-y[0]))<<" "<<(ty-y[0])/__gcd(ABS(tx-x[0]),ABS(ty-y[0]))<<endl;

						}
					}

			}
		/*for(int i=-d*n;i<=(d+1)*n;i++)
				{
					for(int j=-d*m;j<=(d+1)*m;j++)
						{
								//cout<<gr[i+d*n][j+d*m];
						}
						//cout<<endl;
				}*/
		cout<<"Case #"<<cn++<<": "<<c<<endl;
	}

	return 0;
}









//--This portion is kept intentionally blank :p









//end of code
