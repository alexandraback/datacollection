#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

int K,L,S;
string s1,s2;
map<char,int> c_cnt;
int maxi;

int cnt(const string& s) {
    int ret=0;
    rep(i,s.size()) {
        string t=s.substr(i,s2.size());
        if(t==s2) ret++;
    }

    maxi=max(maxi,ret);
    return ret;
}

double dfs(string s) {
    if(S == s.size()) {
        //cout<<s<<","<<cnt(s)<<endl;
        return cnt(s);
    }
    double ret=0.0;

    rep(i,s1.size()) {
        //cout<<s1[i]<<","<<c_cnt[s1[i]]<<","<<1.0*c_cnt[s1[i]]/s1.size()<<endl;
        ret += dfs(s+s1[i])*1.0/s1.size();
    }

    return ret;
}

void solve() {
    maxi=0;
    cin>>K>>L>>S;
    cin>>s1>>s2;

    rep(i,s1.size()) c_cnt[s1[i]]++;

    double ans=dfs("");
    ans=maxi-ans;
    printf("%.8f\n",ans);
}

int main() {
    int t;
    cin>>t;
    rep(i,t) {
        printf("Case #%d: ",i+1);
        solve();
    }
    return 0;
}

