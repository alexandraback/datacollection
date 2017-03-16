#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
int data[11] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int m, a, b;
set<int> st;
int cal(int n){
    int res = 0;
    int t = n;
    st.clear();
    for(int i=0;i<m-1;i++){
        t = t % data[m] * 10 + t / data[m];
        if(t > n && t <= b){
            st.insert(t);
        }
    }
    return st.size();
}
int main(){
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int _ca=1;_ca<=t;_ca++){
        scanf("%d%d", &a, &b);
        for(m=2;m<10;m++){
            if(a < data[m]) break;
        }
        --m;
        int res = 0;
        for(int i=a;i<=b;i++){
            res += cal(i);
        }
        printf("Case #%d: %d\n", _ca, res);
    }
    return 0;
}
