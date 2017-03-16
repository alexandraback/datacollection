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
    int n;
    cin >> n;
    vector<double> naomi(n,0), ken(n,0);
    
    for (int i=0;i<n;i++){
        cin >> naomi[i];
    }
    for (int i=0;i<n;i++){
        cin >> ken[i];
    }
    
    sort(naomi.begin(), naomi.end());
    sort(ken.begin(), ken.end());
    
    int dec_point = 0;
    for (int i=0; i < n ; i++){
        if (naomi[i] > ken[dec_point]) {
            dec_point++;
        }
    }
    
    int war_point = 0;
    for (int i=n-1; i >= 0; i--){
        if (naomi[i] < ken[n-1-war_point]) {
            war_point++;
        }
    }
    cout << dec_point << " " << (n-war_point);
    return 0;
}

int main(){

    init();
    
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ": ";
        solve(i);
        cout << "\n";
    }
    
    return 0;
}
