#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <set>
using namespace std;

int foo(vector<pair<int,int> > &v) {
    int star = 0;
    int cnt;
    int a[1003] = {0,};
    int aa = 0;
    bool f;

    sort(v.begin(), v.end(), greater<pair<int,int> >());
    for(cnt=0;;cnt++) {
        f = false;
        // find level-2
        for(int i=0;i<v.size();i++) {
            if(a[i]<2 && star >= v[i].second) {
                star += (a[i] ? 1 : 2);
                a[i] = 2;
                aa++;
                if(aa == v.size()) return cnt+1;
                f = true;
                break;
            }
        }

        if(f==true) continue;

        f = false;
        for(int i=0;i<v.size();i++) {
            if(a[i]==0  && star >= v[i].first) {
                star += 1;
                a[i] = 1;
                f = true;
                break;
            }
        }

        if(f==false) return -1;
    }

    return cnt;
}

int main() {
    int T;

    cin >> T;
    for(int cs=1;cs<=T;cs++) {
        int N;
        cin >> N;
        vector<pair<int,int> > v(N);
        for(int i=0;i<N;i++) cin >> v[i].first >> v[i].second;

        int ret = foo(v);
        if(ret < 0) printf("Case #%d: Too Bad\n", cs);
        else printf("Case #%d: %d\n", cs, ret);
    }

    return 0;
}
