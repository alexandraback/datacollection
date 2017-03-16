#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstdlib>

using namespace std;

int solve() {
    int result=0;
    int n,maxX=0;
    bool done[1111][2];
    cin >> n;
    vector<pair<int,int> > x=vector<pair<int,int> >(n,pair<int,int>(0,0));
    for (int i=0;i<n;++i) {
        done[i][0]=false;
        done[i][1]=false;
    }
    for (int i=0;i<n;i++) {
        cin >> x[i].first >> x[i].second;
        maxX=max(maxX,max(x[i].first,x[i].second));
    }
    sort(x.begin(),x.end());
    if (maxX>2*n) return -1;
    for (int p=0;p<maxX;) {
        bool changed=false;
        for (int i=0;i<n;++i) if (x[i].second<=p&&!done[i][0]&&!done[i][1]) {
            done[i][0]=true;
            done[i][1]=true;
            ++result;
            p+=2;
            changed=true;
        }
        for (int i=0;i<n;++i) {
            if (x[i].second<=p&&!done[i][1]&&done[i][0]) {
                done[i][1]=true;
                p++;
                ++result;
                changed=true;
            }
        }
        if (!changed) {
            int maxP=-1,bestI=-1;
            for (int i=0;i<n;++i) {
                if (x[i].second>maxP&&!done[i][0]&&x[i].first<=p) {
                    maxP=x[i].second;
                    bestI=i;
                }
            }
            if (maxP==-1) return -1;
            ++result;
            ++p;
            done[bestI][0]=true;
        }
    }
    for (int i=0;i<n;++i) result+=!done[i][1];
    return result;
}

int main()
{
    freopen("in","r",stdin);
    int t;
    cin >> t;
    for (int i=1;i<=t;++i) {
        int t=solve();
        if (t>-1) cout << "Case #" << i << ": " << t << endl;
        else cout << "Case #" << i << ": Too Bad" << endl;
    }
    return 0;
}
