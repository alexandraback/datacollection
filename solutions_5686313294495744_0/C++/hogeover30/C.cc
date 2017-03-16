#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cstring>
using namespace std;

int memo[16][1<<16];
int x[100000];

int func(vector<int>& f, vector<int>& s, int i, int mask, int n)
{
    if (i==n) return 0;
    int& res=memo[i][mask];
    if (~res) return res;
    res=0;
    for(int j=0; j<n; ++j) {
        if (mask&(1<<j)) continue;
        int t=!x[f[i]*100+s[j]];
        //x[f[i]*100+s[j]]++;
        res=max(res, t+func(f, s, i+1, mask|(1<<j), n));
        //x[f[i]*100+s[j]]--;
    }
    return res;
}

int main()
{
    int T; cin>>T;
    for(int t=1; t<=T; ++t) {
        memset(memo, -1, sizeof(memo));
        int n; cin>>n;
        map<string, int> m;
        vector<int> f(n), s(n);
        int k=0;
        for(int i=0; i<n; ++i) {
            string a, b; cin>>a>>b;
            if (!m.count(a)) m[a]=k++;
            if (!m.count(b)) m[b]=k++;
            f[i]=m[a];
            s[i]=m[b];
            x[f[i]*100+s[i]]++;
            x[f[i]*100+f[i]]++;
        }
        for(int i=0; i<n; ++i) {
            x[s[i]*100+s[i]]++;
            for(int j=0; j<n; ++j) {
                x[s[i]*100+f[j]]++;
            }
        }
        cout<<"Case #"<<t<<": "<<func(f, s, 0, 0, n)<<endl;
    }
}
