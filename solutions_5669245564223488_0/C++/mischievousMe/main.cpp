#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <valarray>
#include <algorithm>
#include <queue>
#include <cstdio>
#include<stack>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include<climits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define pi 2.0*acos(0.0)

# define mod 1000000007
ll perm[11];


int main() {
    //freopen("/Users/shalini/Downloads/B.txt","r",stdin);
    //freopen("/Users/shalini/Downloads/B1.txt","w",stdout);
    int t,n;
    cin>>t;
    int x = 0;
    int perm[11];
    perm[1]=perm[0]=1;
    for(int i = 2;i<=10;++i) {
        perm[i]=perm[i-1]*i;
    }
    while(t--) {
        ++x;
        cin>>n;
        vector<string>v;
        string s;
        for(int i = 0;i < n;++i) {
            cin>>s;
            v.pb(s);
        }
        int cnt[256];
        ll ans = 1;
        int w[256][256];
        memset(w, 0, sizeof(w));
        int exist[256];
        memset(exist, 0, sizeof(exist));
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0;i < n;++i) {
            int m = (int)v[i].size();
            int fl = 1;
            char last = v[i][0];
            for(int j = 0;j < m;++j) {
                exist[v[i][j]] = 1;
                if(v[i][j]!=v[i][0]) {
                    fl = 0;
                }
                if(v[i][j] != last) {
                    w[last][v[i][j]]++;
                }
                last = v[i][j];
            }
            if(fl) {
                cnt[v[i][0]]++;
            }
        }
        int comp =0;
        for(int i = 0;i < 256;++i) {
            if(exist[i]) {
                int fl = 0;
                for(int j = 0;j<256;++j) {
                    if(w[j][i]) {
                        fl = 1;
                    }
                    if(w[j][i] > 1) {
                        ans = 0;
                    }
                    else if(w[j][i] && w[i][j]) {
                        ans = 0;
                    }
                }
                if(!fl) {
                    ++comp;
                }
            }
        }
        
        ans = (ans*perm[comp])%mod;
        for(int i = 0;i < 256;++i) {
            ans = (ans*perm[cnt[i]])%mod;
        }
        cout<<"Case #"<<x<<": "<<ans<<"\n";
    }
    return 0;
}