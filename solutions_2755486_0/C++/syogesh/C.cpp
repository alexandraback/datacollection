#include <climits>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <cassert>

using namespace std;

#define rep(i,a,b) for(typeof(a) i=(a);i<(b);i++)
#define ll unsigned long long int
#define ii pair<int,int>
#define gi(x) scanf("%d",&x)
#define gl(x) scanf("%lld",&x)
#define CLEAR(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()
#define MAX 15
#define MAX_OFF 5000


template <class T>inline string itos( T n ) {return (n)< 0?"-"+itos(-(n)):(n)<10?(string)("")+(char('0'+(n))):itos((n)/10)+itos((n)%10);}
typedef struct attack {
	int day_id , a_id , a_num;
	friend bool operator < ( const attack &A , const attack &B ) {
		return (A.day_id<B.day_id);
	} 
}attack;

typedef struct intv{
	int l , r , s;
}intv;


int D[MAX] , A[MAX] , W[MAX] , E[MAX] , S[MAX] , DD[MAX] , DP[MAX] , DS[MAX]; 
int Wall[MAX_OFF*2];

int process( vector<intv> v ) {
	int ret = 0;
	int sz = v.size();
	rep( i , 0 , sz ) {
		int L = 2*v[i].l+MAX_OFF , R = 2*v[i].r+MAX_OFF , S = v[i].s;
		bool succ = false;
		rep( j , L , R+1 ) if( Wall[j] < S ) succ = true;  
		ret += succ;
	}
	rep( i , 0 , sz ) {
		int L = 2*v[i].l+MAX_OFF , R = 2*v[i].r+MAX_OFF , S = v[i].s;	
		rep( j , L , R+1 ) Wall[j] = max( Wall[j] , S );
	}
	return ret;
}

void Solve() {
	int N; cin >> N;
	rep( i , 0 , N ) cin >> D[i] >> A[i] >> W[i] >> E[i] >> S[i] >> DD[i] >> DP[i] >> DS[i];
	priority_queue< attack > PQ;
	rep( i , 0 , N ) PQ.push((attack){ -D[i] , i , 1 });
	CLEAR( Wall , 0 );


	vector<intv> vintv; vintv.clear(); int prevday = -1; 

	int ans = 0;
	while( !PQ.empty() ) {
		attack a = PQ.top();PQ.pop();
		int at_id = a.a_id;
		int at_num = a.a_num;
		int at_day = -a.day_id;

		int L = W[at_id]+(at_num-1)*DP[at_id] , R = E[at_id]+(at_num-1)*DP[at_id];
		int Strength = S[at_id]+(at_num-1)*DS[at_id];


	//	cout << at_day << " " << L << " " << R << " " << Strength << "\n";

		if( at_day == prevday ) { vintv.push_back( (intv){ L , R, Strength } ); }
		else {
			ans += process( vintv );vintv.clear();
			vintv.push_back( (intv){ L , R, Strength } );
			prevday = at_day;
		}
		if( at_num < A[at_id] ) {
			int DNA = D[at_id]+(at_num*DD[at_id]);
			PQ.push((attack){ -DNA , at_id , at_num+1 } );
		}
	}
	if( vintv.size() > 0 ) ans += process(vintv);
	vintv.clear();


	cout << ans << "\n";
}
int main() {
	int T  , cs = 1;
	cin >> T;
	while( cs <= T ) {
		cout << "Case #" << cs++ <<": ";
		Solve();
	}
	return 0;
}