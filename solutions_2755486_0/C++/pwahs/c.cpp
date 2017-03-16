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


class wall{
    public:
        int from, to;
        bool div;
        int height;
        wall *lc, *rc;
        
        wall(int f,int t, int h): from(f), to(t), div(false), lc(NULL), rc(NULL), height(h){}
        
        bool attackc(int left, int right, int strength){
            if (right<=from || left>=to) return false;
            if (!div){
                if (left<=from && right>=to) {
                    if (height>=strength) return false;
                    return true;
                }
                div = true;
                lc = new wall(from, (from+to)/2, height);
                rc = new wall((from+to)/2, to, height);                
            }
            bool result = false;
            result = lc->attackc(left,right,strength) || result;
            result = rc->attackc(left,right,strength) || result;
            return result;
        }
        
        bool attack(int left, int right, int strength){
            if (right<=from || left>=to) return false;
            if (!div){
                if (left<=from && right>=to) {
                    if (height>=strength) return false;
                    height = strength;
                    return true;
                }
                div = true;
                lc = new wall(from, (from+to)/2, height);
                rc = new wall((from+to)/2, to, height);                
            }
            bool result = false;
            result = lc->attack(left,right,strength) || result;
            result = rc->attack(left,right,strength) || result;
            return result;
        }
        
        ~wall(){
            delete lc;
            delete rc;
        }
};

void init(){
    cout << setprecision(8)<< fixed;
}

int solve(int testnr){
    int leftm = 0, rightm = 0;
    int N;
    cin >> N;
    
    vector<int> d(N), n(N), w(N), e(N), s(N), dd(N), dp(N), ds(N);
    
    set<tiii> days;
    
    for(int i=0;i<N;i++){
        cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
        leftm = min(min(leftm,w[i]),w[i] + (n[i]-1) * dp[i]);
        rightm = max(max(rightm,e[i] + 1),e[i] + (n[i]-1) * dp[i] + 1);
        days.insert(mt(d[i],i,0));
    }
    
    wall *greatwall = new wall(leftm,rightm,0);
    
    int count = 0;
    
    while (!days.empty()){
        set<tiii>::iterator it;
        for(it=days.begin();T1(*it)==T1(*(days.begin()));it++){
            int i = T2(*it);
            if (greatwall->attackc(w[i] + (T3(*it)) * dp[i], e[i] + (T3(*it)) * dp[i], s[i] + (T3(*it)) * ds[i])) count++;
        }
        for(it=days.begin();T1(*it)==T1(*(days.begin()));it++){
            int i = T2(*it);
            greatwall->attack(w[i] + (T3(*it)) * dp[i], e[i] + (T3(*it)) * dp[i], s[i] + (T3(*it)) * ds[i]);
            if (T3(*it)+1 < n[i]){
               days.insert(mt(T1(*it) + dd[i],i,T3(*it) + 1));
            }
        }
        days.erase(days.begin(), it);
    }
    
    delete greatwall;
    
    return count;
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
