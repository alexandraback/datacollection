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

const int MAX = 100*1000;
const int INF = 1<<29;
const ll D = 1000*1000*1000+7;
const string Vowels = "aeoiu";
string s;
int n;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int tt=0; tt<t; tt++)
	{
		cin >> s >> n;
		ll cnt = 0;
		int a = 0;
		int best = -1;
		for(int i=0; i<(int)s.size(); i++)
		{
			if( Vowels.find(s[i]) >= Vowels.size() )
				a++;
			else
				a = 0;
			if( a >= n )
				best = i-n+1;
			cnt += best+1;
		}
		cout << "Case #" << tt+1 << ": " << cnt << endl;
	}
	//cerr << "Time :  " << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}













