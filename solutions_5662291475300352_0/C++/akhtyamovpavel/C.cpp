#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <complex>
#include <iomanip>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<vector<int> > graph;
const int INF = 1000000000;
const ll MOD = 1000000009;
#define FILEIN "C.in"
#define FILEOUT "C.out"

const double eps = 1e-7;


int main(){
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);
    int tests;
    cin >> tests;
    for (int _ = 1; _ <= tests; ++_){
    	int N;
        cin >> N;
        vector<pair<int,int> > data;

        for (int i = 0; i < N; ++i) {
            int ang;
            cin >> ang;
            int val;
            cin >> val;
            int sp;
            cin >> sp;
            for(int j = 0; j < val; ++j) {
                data.pb(mp(ang, sp + j)); 
            }
        }
        int ans = 0;
        if (data.size() == 0) {
            ans = 0;
        } else if (data.size() == 1) {
            ans = 0;
        } else {
            ans = 2;
            if (data[0].second == data[1].second) {
                ans = 0;
            } else {
                if (data[0].first > data[1].first) {
                    swap(data[0], data[1]);
                } else if (data[0].first == data[1].first && data[0].second < data[1].second) {
                    swap(data[0], data[1]);
                }
                double v1 = 360.0/data[0].second;
                double v2 = 360.0/data[1].second;
                // cout << v1 << " " << v2 << endl;
                if (v2 > v1) {
                    // cout << 360.0 - (data[1].first - data[0].first) << endl;
                    double T1 = double(360.0 - (data[1].first - data[0].first))/(v2 - v1);
                    double meet_point = data[0].first + v1*T1;
                    // cout << "SECOND" << endl;
                    // cout << meet_point << endl;
                    // cout << T1 << endl;
                    if (meet_point <= 360.0 + eps) {
                        ans = 1;
                    } else {
                        ans = 0;
                    }
                } else {
                    double T1 = double((data[1].first - data[0].first))/(v1 - v2);
                    double meet_point = data[0].first + v1 * T1;
                    // cout << "FIRST" << endl;
                    // cout << meet_point << endl;
                    // cout << T1 << endl;
                    if (meet_point >= 360.0) {
                        ans = 0;
                    }
                    else {
                        double T2 = 360.0/(v1-v2);
                        double meet_point_2 = data[1].first + v2*(T1+T2);
                        // cout << meet_point_2 << endl;
                        if (meet_point_2 <= 360.0 + eps) {
                            ans = 1;
                        } else {
                            ans = 0;
                        }
                    }
                }
            }
        }
        

        cout << "Case #" << _ << ": ";
        //Output answer 
        cout << ans;
        
        cout << "\n";
    }
    return 0;
}