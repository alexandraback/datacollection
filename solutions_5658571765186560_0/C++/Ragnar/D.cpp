#include <iostream>
#include <numeric>
#include <iterator>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <stack>
#include <string>
#include <sstream>
#include <math.h>

#define REP(i,n) for(int i = 0; i<(n); i++)
#define ITER(i,v) for(auto i : v)
#define INF 1000000000
#define F(v) (v).begin(), (v).end()
#ifdef DEBUG
const bool DEBUG = true;
#else
const bool DEBUG = false;
#endif

using namespace std;

template <class T>
using priority_queue_asc =  priority_queue<T,vector<T>, greater<T> >;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<bool> vb;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int TC;
	cin >> TC;
	for(int tc=1;tc<=TC;tc++){
		int X,R,C; cin >> X >> R >> C;
		int win = -1;
		if(R>C) swap(R,C); // now R<=C

		if(X>=7) win = 1;
		else if((R*C)%X != 0)
			win = 1;
		if(win<0){
			switch(X){
			case 1:
				win = 0;
				break;
			case 2:
				win = 0; // already checked division
				break;
			case 3:
				win = R==1; // make an L-shape
				break;
			case 4:
				if(R==1)
					win =1; // 2*2 square
				else if(R==2)
					win = 1; // T shape
				else if(R==3)
					win = C<4 ? 1 : 0; // long bar to block
				else // R>=4
					win = 0; // no way to win :(
			}
		}

		cout << "Case #"<<tc<<": "<<(win ? "RICHARD" : "GABRIEL")<<"\n";
	}
	return 0;
}


