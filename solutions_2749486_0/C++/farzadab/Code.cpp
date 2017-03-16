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

const int MAX = 2450;
const int INF = 1<<29;
const ll D = 1000*1000*1000+7;
const int J = 4;
const string JS[J] = { "S" , "W" , "E" , "N" };
const int X[J] = { 0 , -1 , 1 , 0 };
const int Y[J] = { -1 , 0 , 0 , 1 };
int x,y;
int n;

int abs(int a) { return ( a<0 ? -a : a ); }
bool is_in(int x,int y,int sum)
{
	if( ((x+y)&1) != (sum&1) )
		return false;
	return ( abs(x) + abs(y) <= sum );
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int tt=0; tt<t; tt++)
	{
		string out = "";
		cin >> x >> y;
		int sum = 0;
		int level;
		for(level = 1; level<MAX; level++)
		{
			sum += level;
			if( is_in(x,y,sum) )
				break;
		}
		while( level > 0 )
		{
			sum -= level;
			for(int j=0; j<J; j++)
				if( is_in( x-X[j]*level , y-Y[j]*level , sum ) )
				{
					x -= X[j]*level;
					y -= Y[j]*level;
					out += JS[j];
					break;
				}
			level--;
		}
		reverse( out.begin() , out.end() );
		cout << "Case #" << tt+1 << ": " << out << endl;
	}
	//cerr << "Time :  " << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}













