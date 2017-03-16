#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long get(vector <pair<int, int> > &v, int x)
{
    int i;
    long long t = 0, ans = 0;
    
    if (x == 0) return v.size();
    
    for (i = 0; i < v.size(); i++) {
        if ((x >> i) & 1) t = max(t, (long long)v[i].second * (360 - v[i].first));
    }
    
    for (i = 0; i < v.size(); i++) {
        if ((x >> i) & 1) {
            if ((long long)v[i].second * (720 - v[i].first) <= t) return 1e18;
        } else {
            ans += t / v[i].second / 360 + 1;
        }
    }
    
    return ans;
}

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, j, k;
        long long ans = 1e18;
        vector <pair<int, int> > v;
        
        scanf("%d", &n);
        
        for (j = 0; j < n; j++) {
            int x, y, z;
            
            scanf("%d %d %d", &x, &y, &z);
            
            for (k = 0; k < y; k++) v.push_back(make_pair(x, z + k));
        }
        
        for (j = 0; j < (1 << v.size()); j++) ans = min(ans, get(v, j));
        
        printf("Case #%d: %lld\n", i + 1, ans);
    }
    
    return 0;
}
