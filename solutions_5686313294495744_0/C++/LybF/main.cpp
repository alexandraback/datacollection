#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <cassert>
#include <set>
using namespace std;


const int N=500;

string p[N],q[N];


int main () {
    freopen("hehe.txt","r",stdin);
    freopen("papa.txt","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        int n;
        cin>>n;
        for (int i=0;i<n;i++) {
            cin>>p[i]>>q[i];
        }
        int ret=n;
        for (int mask=0;mask<(1<<n);mask++) {
            set<string>a,b;
            int cnt=0;
            for (int i=0;i<n;i++) {
                if ((mask>>i)&1) {
                    a.insert(p[i]);
                    b.insert(q[i]);
                    cnt++;
                }
            }
            bool ok=true;
            for (int i=0;i<n;i++) {
                if ((mask>>i)&1) continue;
                if (!a.count(p[i])||!b.count(q[i])) ok=false;
            }
            if (ok) {
                ret=min(ret,cnt);
            }
        }
        ret=n-ret;
        static int cas=1;
        cout<<"Case #"<<cas++<<": "<<ret<<endl;
    }
    return 0;
}
