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
#define __eXYZ__
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
	void nl() { out << endl; start(); }
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
map<pii,pii>last;
void bfs(){
    queue<pii>q;
    queue<int>step;
    map<pii,int>vis;

    q.push(pii(0,0));
    step.push(1);
    vis[pii(0,0)]=1;
    last[pii(0,0)]=pii(0,0);
    while(!q.empty()){

        pii p=q.front(); int s=step.front();
       // if(s==100)cout<<p.px<<" "<<p.py<<endl;
        int i;
        //cin>>i;
        q.pop(); step.pop();
        if(s==500)break;

        int dx[]={0,0,-s,s};
        int dy[]={-s,s,0,0};
        FOR(i,4){
            int nx=dx[i]+p.px;
            int ny=dy[i]+p.py;
            if(vis[pii(nx,ny)]==1)continue;
            if(abs(p.px)>100 || abs(p.py)>100 )continue;
            q.push(pii(nx,ny));
            step.push(s+1);
            vis[pii(nx,ny)]=1;
            last[pii(nx,ny)]=p;
        }
    }

}
int main()
{
	RFILE("input.txt");
	WFILE("op_1c_2_small_1.txt");
	int t,cn=1,n;
	bfs();
	cin>>t;
	while(t--){
	    int x,y;
        cin>>x>>y;
        string str;
        while(last[pii(x,y)]!=pii(x,y)){
            pii p=last[pii(x,y)];

            if(p.px==x&&p.py>y){
                str+="S";
            }
            else if(p.px==x&&p.py<y){
                str+="N";
            }
            else if(p.py==y&&p.px>x){
                str+="W";
            }
            else if(p.py==y&&p.px<x){
                str+="E";
            }
            x=p.px;y=p.py;
        }
        reverse(all(str));
//        cout<<str<<endl;

        cout<<"Case #"<<cn++<<": "<<str<<endl;
	}

	return 0;
}

