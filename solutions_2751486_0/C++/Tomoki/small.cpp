#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <complex>
#include <string>
#include <sstream>

using namespace std;

#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define mp(a,b) make_pair((a),(b))
#define eq ==

typedef long long ll;
typedef complex<double> point;
typedef pair<int,int> pii;

// →↑←↓
const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};


const double EPS = 1e-9;

bool isvowel(char c){
    return (c=='a' or c == 'i' or c == 'u' or c == 'e' or c == 'o');
}

ll solve(const string &s,int n){
    // [i,j)
    ll ret = 0;
    for(int i=0;i<s.length();i++){
        for(int j=i+n;j<=s.length();j++){
            int cnt = 0;
            int now = 0;
            int nv = true;
            for(int k=i;k<j;k++){
                if(not isvowel(s[k])){
                    now++;
                }else{
                    cnt = max(cnt,now);
                    now = 0;
                }
            }
            cnt = max(cnt,now);
            if(cnt >= n) ret++;
        }
    }
    return ret;
}

int main(){
    int T;
    cin >> T;
    for(int testcase=1;testcase<=T;testcase++){
        string s;
        int n;
        cin >> s >> n;
        // Case #1: 4
        cout << "Case #" << testcase << ":" << " " << solve(s,n) << endl;
    }
    return 0;
}
