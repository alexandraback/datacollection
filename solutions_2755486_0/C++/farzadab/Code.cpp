#include<iostream>
#include<algorithm>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<ctime>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> PII;
typedef pair<ld,ld> PDD;

#define U adj[v][i]
#define N(x) ((int)adj[x].size())
#define all(x) x.begin() , x.end()
#define F first
#define S second
#define X first
#define Y second
#define show(x) cerr << #x << " " << x << " " << endl;
#define Heap(x) priority_queue<x,vector<x>,greater<x> >

template<class P,class Q> void mins(P& a,Q b) { a = min( a , (P)b ); }
template<class P,class Q> void maxs(P& a,Q b) { a = max( a , (P)b ); }

const int MAXA = 200;
const int MAXS = 600;
const int INF = 1<<29;
const ll D = 1000*1000*1000+7;
struct Attack{
	int w,e,s,d;
	Attack(int _w=0,int _e=0,int _s=0,int _d=0) : w(_w), e(_e), s(_s), d(_d) {}
	friend bool operator<(Attack a,Attack b) { return a.d < b.d; }
}a[MAXA+10];
int head;
int tmps[MAXS+10];
int* s = &tmps[MAXS/2];
int n;

int find_min(int b,int e)
{
	int ret = INF;
	for(int i=b; i<e; i++)
		mins( ret , s[i] );
	return ret;
}

void set_min(int b,int e,int str)
{
	for(int i=b; i<e; i++)
		maxs( s[i] , str );
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int tt=0; tt<t; tt++)
	{
		cin >> n;
		memset( tmps , 0 , sizeof tmps );
		head = 0;
		for(int i=0; i<n; i++)
		{
			int day,num,w,e,str,dday,ddis,dstr;
			cin >> day >> num >> w >> e >> str >> dday >> ddis >> dstr;
			for(int j=0; j<num; j++)
			{
				a[head++] = Attack(w,e,str,day);
				w += ddis;
				e += ddis;
				str += dstr;
				day += dday;
			}
		}
		sort( a , a+head );
		int p = 0;
		int cnt = 0;
		while( p < head )
		{
			int p2 = p+1;
			while( p2 < head && a[p2].d == a[p].d )
				p2++;
			for(int i=p; i<p2; i++)
				if( find_min(a[i].w,a[i].e) < a[i].s )
					cnt++;
			for(int i=p; i<p2; i++)
				set_min(a[i].w,a[i].e,a[i].s);
			p = p2;
		}
		cout << "Case #" << tt+1 << ": " << cnt << endl;
	}
	//cerr << "Time :  " << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}













