#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define REPP(i,s,e) for(int i=s; i<=e; i++)
#define PB(a) push_back(a)
#define MP(i,s) make_pair(i,s)
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(), (a).end()
#define PRT(a) cerr << #a << " = " << (a) << endl
#define PRT2(a,b) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << endl
#define PRT3(a,b,c) cerr << (a) << ", " << (b) << ", " << (c) << endl

typedef long long lint;
typedef pair<lint,lint> pll;
typedef pair<double,int> pdi;

int n;
double nv[111];
double kv[111];

int playDecWar() {
    deque<double> nao;
    deque<double> ken;
    REP(i,n) {
        nao.push_back(nv[i]);
        ken.push_back(kv[i]);
    }
    sort(ALL(nao));
    sort(ALL(ken));

    int score = 0;
    REP(i,n) {
        double w_nao = nao.front();
        double w_ken = ken.front();
        if(w_nao > w_ken) {
            nao.pop_front();
            ken.pop_front();
            score++;
        } else {
            nao.pop_front();
            ken.pop_back();
        }
    }
    return score;
}

int playWar() {
    vector<pdi> vec;
    REP(i,n) {
        vec.push_back(pdi(nv[i], 0));
        vec.push_back(pdi(kv[i], 1));
    }
    sort(ALL(vec), std::greater<pdi>());

    int k_it, n_it;
    while(!vec.empty()) {
        bool k_ok = false;
        for(k_it=0; k_it+1<vec.size(); k_it++) {
            if(vec[k_it].second == 1 && vec[k_it+1].second == 0) {
                k_ok = true;
                break;
            }
        }
        
        for(n_it = k_it+1; n_it+1<vec.size(); n_it++) {
            if(vec[n_it].second == 0 && vec[n_it+1].second == 1) {
                break;
            }
        }

        if(k_ok) {
            vec.erase(vec.begin() + k_it);
            vec.erase(vec.begin() + n_it - 1);
        } else {
            break;
        }
    }

    int score = vec.size() / 2;
    return score;
}

void solve() {
    int s_dec = playDecWar();
    int s_war = playWar();
    printf("%d %d\n", s_dec, s_war);
}

void coding() {
    int T;
    while(cin>>T) {
        REP(t,T) {
            printf("Case #%d: ", t+1);
            cin>>n;
            REP(i,n) cin>>nv[i];
            REP(i,n) cin>>kv[i];
            solve();
        }
    }
}

// #define _LOCAL_TEST

int main() {
#ifdef _LOCAL_TEST
	clock_t startTime = clock();
	freopen("d.in", "r", stdin);
#endif

	coding();

#ifdef _LOCAL_TEST
	clock_t elapsedTime = clock() - startTime;
	cout << endl;
	cout << (elapsedTime / 1000.0) << " sec elapsed." << endl;
	cout << "This is local test" << endl;
	cout << "Do not forget to comment out _LOCAL_TEST" << endl << endl;
#endif
}
