#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

long long solve(int l, int r, int ml, int mr, int n) {
    long long ans = 0;
    if( r-l+1>=n )ans += (long long)(r-l+1-n+1)*(r-l+2-n+1) / 2;
    if( r-l+1>=n )ans += (long long)(l-ml+1)*(mr-r+1)-1;
    if( r-l+1>=n )ans += (long long)(mr-r)*(r-l-n+1);
    if( r-l+1>=n )ans += (long long)(l-ml)*(r-l-n+1);
    return ans;
}

int main() {
    int T, c;
    freopen("A-large.in", "r", stdin);
    freopen("out2.txt", "w", stdout);
    scanf("%d", &T);
    for (c = 1; c <= T; ++c) {
        int i, n;
        char name[1001000];
        vector <pair<int, int> > V;
        scanf("%s%d", name, &n);
        int l = strlen(name), pre = -1;
        long long ans = 0;
        for (i = 0; i < l; ++i) {
            if (name[i] == 'a' || name[i] == 'o' || name[i] == 'i' || name[i] == 'u' || name[i] == 'e') {
                int k = i - pre - 1;
                if (k >= n)
                {
                    V.push_back(make_pair(pre+1, i-1));
                    //ans += (long long)(k-n+2)*(k-n+1)/2;
                }
                pre = i;
            }
        }
        if (pre < i) {
            int k = i - pre - 1;
            if (k >= n)
                V.push_back(make_pair(pre+1, i-1));
            //ans += (long long)(k-n+2)*(k-n+1)/2;
        }
        //cout << V.size() << V[0].first << V[0].second << endl;
        if (V.size() > 0)sort(V.begin(), V.end());
        for (int i = 0;  i < V.size();++i) {
            int left = 0;
            if (i > 0) left = V[i-1].second-n+2;
            ans += solve(V[i].first, V[i].second, left, l-1, n);
        }
        printf("Case #%d: %lld\n", c, ans);
    }
    return 0;
}
