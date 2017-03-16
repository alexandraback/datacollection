#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;

int solve() 
{
    vector<int> vec;
    int c, d, v;
    int i, j, k, tmp;
    cin>>c>>d>>v;
    for(i=0; i<d; i++) {
        cin>>tmp;
        vec.push_back(tmp);
    }
    int ans = 0;
    for (i=0; i<d; i++) {
        if (vec[i] == 1)
            break;
    }
    if (i == d)ans++;
    if (v == 1) return ans;

    for (i=0; i<d; i++) {
        if (vec[i] == 2)
            break;
    }
    if (i == d)ans++;
    if (v <= 3) return ans;

    vector<int> mark(100, 0);
    mark[0] = mark[1] = mark[2] = mark[3] = 1;
    for (i=0; i<d; i++) {
        if (vec[i] == 1 || vec[i] == 2)
            continue;
        for (j=0; j<vec[i]; j++) {
            if (mark[j] == 0) {
                for (k = v; k>=0; k--) {
                    if (mark[k]==1)
                        mark[k+j]=1;
                }
                ans++;
            }
        }
        for (k = v; k>=0; k--) {
            if (mark[k]==1)
                mark[k+vec[i]]=1;
        }
    }
    for (j=0; j<=v; j++) {
        if (mark[j] == 0) {
            for (k = v; k>=0; k--) {
                if (mark[k]==1)
                    mark[k+j]=1;
            }
            ans++;
        }
    }
    return ans;
}

int main() {
    int nc, tc;
    tc = 1;
    cin>>nc;
    while (tc<=nc) {
        cout<<"Case #"<<tc<<": ";
        int ans = solve();
        cout<<ans<<endl;
        tc++;
    }
    return 0;
}
