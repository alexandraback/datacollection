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

vi v[110];
int type[110],keycnt[210],inikey[210],K,n,open[100],nowKey[210];
bool vis[1<<21],mem[1<<21];
bool solve(int msk)
{
    if(((1<<n)-1)==msk)return true;
    if(vis[msk]==true)return mem[msk];
    vis[msk]=true;
    bool &ret=mem[msk];
    ret=false;
    int keycnt[210];
    ms(keycnt,0);
    FOR(i,K)
    {
        keycnt[inikey[i]]++;
    }
    FOR(i,n)
    {
        if(GETBIT(msk,i))
        {
            FOR(j,sz(v[i]))keycnt[v[i][j]]++;
            keycnt[type[i]]--;
        }
    }
    FOR(i,n)
    {
        if(!GETBIT(msk,i))if(keycnt[type[i]]>0)
        {
            if(solve(msk|(1<<i)))return ret=true;
        }
    }
    return ret;
}
char str[10000];
int main()
{
	RFILE("input_cj_1.txt");
	WFILE("output_cj_4_small_1.txt");
	int t,cn=1;
	gets(str);
	sscanf(str,"%d",&t);
	while(t--)
	{
        gets(str);
        sscanf(str,"%d%d",&K,&n);
        gets(str);
        stringstream ss(str);
        ms(nowKey,0);
        ms(vis,false);

        FOR(i,K)
        {
            ss>>inikey[i];
            nowKey[inikey[i]]++;
        }

        //cout<<"HERE"<<endl;
        FOR(i,n)
        {
            v[i].clear();
            gets(str);
            //cout<<"HERE1 "<<i<<endl;
            stringstream ss(str);
            ss>>type[i];
            //cout<<type[i]<<endl;
            int nx,x;
            ss>>nx;
            FOR(j,nx)
            {
                ss>>x;
                v[i].pb(x);
              //  cout<<"ss "<<x<<endl;
            }

        }
        //cout<<"HERE"<<endl;
        vi ans;
        int msk=0;
        ms(open,0);
        while(sz(ans)<n)
        {
            //cout<<"HELLO "<<sz(ans)<<endl;
            int x=sz(ans);
            FOR(i,n)
            {
         //       cout<<i<<" "<<open[i]<<" "<<type[i]<<" "<<nowKey[type[i]]<<endl;
                if(!open[i] && nowKey[type[i]]>0)
                {
                    //cout<<"HELLO "<<i<<endl;
                    if(solve(msk|(1<<i)))
                    {
                        //cout<<"ggg"<<endl;
                        nowKey[type[i]]--;
                        FOR(j,sz(v[i]))
                        {
                            nowKey[v[i][j]]++;
                        }
                        open[i]=1;
                        ans.pb(i+1);
                        msk|=1<<i;
                        break;
                    }

                }

            }
            if(x==sz(ans))break;
        }
        cout<<"Case #"<<cn++<<":";
        if(sz(ans)<n)cout<<" IMPOSSIBLE";
        else FOR(i,n)cout<<" "<<ans[i];
        cout<<endl;

    }


	return 0;
}
