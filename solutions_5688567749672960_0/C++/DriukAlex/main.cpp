#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <valarray>
#include <ctime>
#include <set>
#include <sstream>
#include <stdarg.h>
#include <fstream>

using namespace std;

void solve(int t) {
    long long x;
    cin>>x;
    vector<bool> used(x+1);
    queue<pair<long long,int> > q;
    q.push(make_pair(0,0));
    used[0]=true;
    while (!q.empty()) {
        pair<long long,int> v=q.front();
        q.pop();
        if (v.first == x) {
            printf("Case #%d: %d\n",t,v.second);
            return;
        }
        if (!used[v.first+1]) {
            used[v.first+1]=true;
            q.push(make_pair(v.first+1, v.second+1));
        }
        string s="";
        long long copyv = v.first;
        while (copyv > 0) {
            int k=copyv%10;
            copyv/=10;
            char c='0'+k;
            s+=c;
        }
        long long now=atol(s.c_str());
        if (now<=x&&!used[now]) {
            used[now]=true;
            q.push(make_pair(now, v.second+1));
        }
    }
}

int main() {
    freopen("in.in","r",stdin);    
    freopen("out.out","w",stdout);    
    int T;
    cin>>T;
    for (int i=0;i<T;i++)
        solve(i+1);
    return 0;
}