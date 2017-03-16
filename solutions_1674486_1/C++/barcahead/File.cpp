#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

vector<vector<int> > l;
int v[1000];
bool flag;
void solve(int k) {
    if (v[k]>1) {
        flag = 1;
        return;
    }
    for (int i=0; i<l[k].size(); i++) {
        //if (!v[l[k][i]]) {
            v[l[k][i]]++;
            solve(l[k][i]);
        //}
    }
}

int main() {
    freopen("/Users/fengyelei/Desktop/in.in", "r", stdin);
    freopen("/Users/fengyelei/Desktop/out", "w", stdout);
    int T;scanf("%d",&T);
    for (int c=1; c<=T; c++) {
        int n, m, i, j, k;
        scanf("%d",&n);
        l.clear();
        l.resize(n);
        for (i=0; i<n; i++) {
            scanf("%d", &m);
            for (j=0; j<m; j++) {
                scanf("%d",&k);
                l[i].push_back(k-1);
            }
        }
        
//            for (i=0; i<n; i++) {
//                for (j=0; j<l[i].size();j++) cout<<l[i][j]<<" ";
//                cout<<endl;
//            }
        
        flag = 0;
        for (i=0; i<n; i++) {
            memset(v,0,sizeof(v));
            solve(i);
            if (flag) break;
        }
        printf("Case #%d: ", c);
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
}