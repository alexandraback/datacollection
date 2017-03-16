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


void putans(int testcase, string s) {
    cout << "Case #" << (testcase + 1) << ": " << s << endl;
}

int main() {
    int testnum;
    cin >> testnum;
    for (int testcase = 0; testcase < testnum; ++testcase) {
        string s;
        cin >> s;

        if (s.size() == 1) {
            putans(testcase, s);
            continue;
        }
        string ans(1, s[0]);
        for (int i = 1; i < s.size(); ++i) {
            string temp(1, s[i]);
            if (ans[0] <= s[i]) {
                //cout << "a" << endl;
                ans = temp + ans;
            } else {
                //cout << "b" << endl;
                ans = ans + temp;
            }
        }
        putans(testcase, ans);
    }
    return 0;
}