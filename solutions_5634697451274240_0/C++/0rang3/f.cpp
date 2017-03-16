#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
#include <ctime>
#include <stack>
#include <list>
#include <cassert>
#include <iomanip>
#include <deque>
#include <sstream>
#include <fstream>
typedef pair<int,int> pii;
#define rep(i,j,n) for(i=j;i<n;i++)
#define pb push_back
#define ff first
#define ss second 
#define lli long long int
#define get getchar

inline int scan() {
    int n=0,s=1;
    char p=get();
    if(p=='-')  s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
    if(p=='-') s=-1,p=get();
    while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
    return n*s;
}
int getNum(string s) {
    int r = 0;
    int a = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+') r += a;
        a *= 2;
    }
    return r;
}
int main() {
        
    ios::sync_with_stdio(false);
    
    //clock_t start = std::clock();
    freopen ("inp.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    //cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

    int t,ca = 1;
    cin >> t;

    while (t--) {
        cout << "Case #" << ca << ": ";
        ca++;
        string s;
        cin >> s;
        int dp[(1<<10)+100];
        memset(dp,-1,sizeof(dp));
        int tmp = getNum(s);
        queue <pair <string,int> > gg;
        gg.push({s,0});
        while (!gg.empty()) {
            pair<string,int> pair = gg.front();
            string tt = pair.ff;
            gg.pop();
            int val = getNum(tt);
            if (dp[val] != -1) {
                continue;
            }
            dp[val] = pair.ss;
            for (int i = 0; i < tt.length(); i++) {
                string aug = "";
                for (int j = 0; j <= i; j++) {
                    if (tt[i-j] == '+')
                        aug.push_back('-');
                    else
                        aug.push_back('+');
                }
                for (int j = i+1; j < tt.length(); j++) {
                    aug.push_back(tt[j]);
                }
                gg.push({aug,dp[val] + 1});
            }
        }
        int n = s.length();
        cout << dp[(1<<n) - 1] << endl;
    }
    
    return 0;
        
}