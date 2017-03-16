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

class debu{
	public:
	template<class someClass>
	debu & operator,(someClass arg){
		cerr << arg << " ";
		return *this;
	}
} debug;

#define eps 1e-9

void init(){
    cout << setprecision(8)<< fixed;
}

void solve(int testnr){
    int N,min1,min2;
    double s=0,sum=0;
    cin >> N;
    vector<int> p(N),q;
    for(int i=0;i<N;i++){
        cin >> p[i];
        s+=p[i];
    }
    q.assign(all(p));
    sort(all(q));
    double at=q[0];
    sum=s;
    for(int i=1;i<N;i++){
        if ((q[i]-at)*i>sum){
            at+=sum/i;
            sum=0;
        }
        else{
            sum-=(q[i]-at)*i;
            at=q[i];
        }
    }
    if (sum>0) at+=sum/N;
    for(int i=0;i<N;i++){
        if (p[i]>=at-eps) cout << " " << 0.0;
        else cout << " " << 100.0*(at-p[i])/s;
    }
    return;
}

int main(){

    init();
    
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ":";
        solve(i);
        cout << "\n";
    }
    
    return 0;
}
