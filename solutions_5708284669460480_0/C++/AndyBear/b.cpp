#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#pragma comment(linker, "/STACK:1024000000,1024000000")

#define     IT              iterator
#define     PB(x)           push_back(x)
#define     CLR(a,b)        memset(a,b,sizeof(a))

using namespace std;

typedef     long long               ll;
typedef     unsigned long long      ull;
typedef     vector<int>             vint;
typedef     vector<ll>              vll;
typedef     vector<ull>             vull;
typedef     set<int>                sint;
typedef     set<ull>                sull;

int cnt;
int maxcnt;
string p,tt;
int k,l,s;

void dfs(int pos,string ans) {
    //cout<<ans<<" "<<pos<<endl;
    if (pos == s) {
        int tmpcnt = 0;
        while (ans.find(tt) != string::npos) {
            tmpcnt++;
            cnt++;
            int tmppos = ans.find(tt);
            ans[tmppos] = '#';
        }
        maxcnt = max(maxcnt,tmpcnt);
    }
    else
        for (int i = 0; i < p.length(); i++) {
            string tmp = ans;
            tmp += p[i];
            dfs(pos+1,tmp);
        }
}

int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
    int T;
    cin>>T;
    for (int t = 1; t <= T; t++) {
        cin>>k>>l>>s>>p>>tt;
        cnt = maxcnt = 0;
        string tmp = "";
        dfs(0,tmp);
        int totcnt = 1;
        for (int i = 1; i <= s; i++) totcnt *= k;
        double prob = cnt * 1.0 / totcnt;
        printf("Case #%d: %.6f\n",t,maxcnt - prob);
    }
}
