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
string grid[10];
int checkRow(int r,char c)
{
     FOR(i,4)
     {
        if(grid[r][i]!=c && grid[r][i]!='T')return 0;
     }
     return 1;
}
int checkCol(int r,char c)
{
     FOR(i,4)
     {
        if(grid[i][r]!=c && grid[i][r]!='T')return 0;
     }
     return 1;
}
int checkDia1(char c)
{
     FOR(i,4)
     {
        if(grid[i][i]!=c && grid[i][i]!='T')return 0;
     }
     return 1;
}
int checkDia2(char c)
{
     FOR(i,4)
     {
        if(grid[3-i][i]!=c && grid[3-i][i]!='T')return 0;
     }
     return 1;
}
int main()
{
	RFILE("input_cj_1.txt");
	WFILE("output_cj_1_large.txt");
	int t,cn=1;
	cin>>t;
	while(t--)
	{
        FOR(i,4)cin>>grid[i];
        int x=0,o=0,d=1;
        cout<<"Case #"<<cn++<<": ";
        FOR(i,4)
        {
            if(checkRow(i,'X')||checkCol(i,'X'))
            {
                x=1;
                break;
            }
        }
        if(checkDia1('X')||checkDia2('X'))x=1;

        FOR(i,4)
        {
            if(checkRow(i,'O')||checkCol(i,'O'))
            {
                o=1;
                break;
            }
        }
        if(checkDia1('O')||checkDia2('O'))o=1;
        FOR(i,4)FOR(j,4)
        {
            if(grid[i][j]=='.')d=0;
        }

        if(x==1)cout<<"X won";
        else if(o==1)cout<<"O won";
        else if(d==1)cout<<"Draw";
        else cout<<"Game has not completed";
        cout<<endl;

    }


	return 0;
}

