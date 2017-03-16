#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>
#include <sstream>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long ll;
typedef unsigned int uint;

inline int toi(string s){int v; istringstream iss(s);iss>>v;return v;}
template<class T> inline string tos(T x){ostringstream oss;oss<<x;return oss.str();}

#define All(a)  (a).begin(),(a).end()
#define Rall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define exist(s,e) ((s).find(e)!=(s).end())

#define Forall(i,v)   for(int i=0;i<(int)v.size();++i)
#define For(i,a,b)    for(int i=(a);i<(b);++i)
#define ForD(i,a,b)   for(int i=(a);i>(b);--i)
#define Step(i,a,b,s) for(int i=(a);i<(b);i+=(s))
#define Rep(i,n)      for(int i=0;i<(n);++i)
#define Each(i,c)     for(typeof((c).begin()) i=(c).begin();i!=(c).end();++i)

#define Fill(a,b)   memset(a,b,sizeof(a))
#define Clear(a)    memset((a),0,sizeof(a))
#define Sort(c)     sort((c).begin(),(c).end())

#define MinOf(x)    *min_element(All(x))
#define MaxOf(x)    *max_element(All(x))

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

struct Attack{
	int d;
	int w;
	int e;
	int s;
};
bool operator<(const Attack& lhs, const Attack& rhs){
	return lhs.d > rhs.d;
}

void main2(void){
	int N;
	cin >> N;
	priority_queue<Attack> q;
	Rep(i,N){
		int d,n,w,e,s,dd,dp,ds;
		cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
		Rep(j,n){
			Attack a;
			a.d = d;
			a.w = w;
			a.e = e;
			a.s = s;
			q.push(a);
			d += dd;
			w += dp;
			e += dp;
			s += ds;
		}
	}
	VI wall(1000,0);
	VI::iterator zero = wall.begin()+500;
	map<int,int> build;
	int c = 0;
	//cout << endl;
	int pd = -1;
	while(!q.empty()){
		Attack a = q.top();
		if(pd<a.d){
			foreach(build,b){
				*(zero+b->first) = b->second;
			}
			build.clear();
			pd = a.d;
		}
		q.pop();
		bool suc = false;
		for(int p = a.w; p<a.e; p++){
	//		cout << "Day" << a.d << ": Attack [" << p << "] s=" << a.s << " vs h=" << (*(zero+p)) << " => " << (*(zero+p) < a.s) << endl; 
			if(*(zero+p) < a.s){
				suc = true;
				build.insert(mp(p,a.s));
			}
		}
		if(suc) c++;
	}
	cout << " " << c << endl;
}

int main(void){
	int T,t;
	cin >> T;
	REP(t,T){
		printf("Case #%d:",t+1);
		main2();
	}
	return 0;
}
