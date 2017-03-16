#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
 
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define _D(p) std::cout<<"L"<<__LINE__<<" : " #p " = "<<(p)<<std::endl;
#define _D2(p,q) std::cout<<"L"<<__LINE__<<" : " #p " = "<<(p) << ", " #q " = "<<(q)<<std::endl;
#define _DN(v) std::cout<<"L"<<__LINE__<<" : " #v " = ["; rep(i,(v).size()) {std::cout<<v[i]<<(i==v.size()-1?"":", ");}std::cout<<"]"<<std::endl;
#define _DNN(v) std::cout<<"L"<<__LINE__<<" : " #v " = [" << std::endl; rep(i,(v).size()) {std::cout<<"    [";rep(j,(v)[0].size()){std::cout<<v[i][j]<<(j==v[0].size()-1?"":", ");}std::cout<<"],"<<std::endl;}std::cout<<"]"<<std::endl;
 
using namespace std;
 
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
 
const int INF=1<<29;
const double EPS=1e-9;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    for (int tests = 0; tests < T; ++tests) {
        int N;
        cin >> N;
        vector<string> s1, s2;
        for (int i = 0; i < N; ++i) {
            string s1_, s2_;
            cin >> s1_ >> s2_;
            s1.push_back(s1_);
            s2.push_back(s2_);
        }
        int ans = 0;
        for (int i = 0; i < 1 << N; ++i) {
            int count = 0;
            for (int j = 0; j < N; ++j) {
                if (!(i >> j & 1)) continue; //1:fake
                bool flag = false;
                for (int k = 0; k < N; ++k) {
                    if (j == k) continue;
                    for (int l = 0; l < N; ++l) {
                        if (j == l) continue;
                        if (s1[j] == s1[k] && s2[j] == s2[l]) flag = true;
                        if (flag) break;
                    }
                    if (flag) break;
                }
                if (flag) {
                    count++;
                }
            }
            if (count == __builtin_popcount(i)) {
                ans = max(ans, count);
            }
        }
        cout << "Case #" << tests + 1 << ": " << ans << endl;
    }
    return 0;
}