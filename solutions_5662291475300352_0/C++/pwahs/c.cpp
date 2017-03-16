#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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

using namespace std;

#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define dbg(args...) {debug,args; cerr << endl;}

#define mp make_pair
#define mt(a,b,c) mp(a,mp(b,c))
#define P1(a) (a).first
#define P2(a) (a).second
#define T1(a) (a).first
#define T2(a) (a).second.first
#define T3(a) (a).second.second
#define INF 1e20
#define EPS 1e-8

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> tiii;

class debu{
	public:
	template<class someClass>
	debu & operator,(someClass arg){
		cerr << arg << " ";
		return *this;
	}
} debug;


void init(){
    cout << setprecision(8)<< fixed;
}

int solve(int testnr){
    int N;
    cin >> N;
    vector<int> D(N), H(N), M(N);
    vector<int> d, m;
    for(int i=0;i<N;i++){
        cin >> D[i] >> H[i] >> M[i];
        for(int j=0;j<H[i];j++) {
            d.push_back(D[i]);
            m.push_back(M[i] + j);
        }
    }
    double longest = 0;
    for (int i=0;i<d.size();i++){ 
        double time = m[i] / 360.0 * (360.0 - d[i]);
        longest = max(longest, time);
    }
    int take_over = 0;
    for (int i=0;i<d.size();i++){
        double time = m[i] / 360.0 * (720.0 - d[i]);
        if (time <= longest) take_over++;
    }
    return min(take_over, 1);
}

int main(){

    init();
    
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ": " << solve(i) << "\n";
    }
    
    return 0;
}
