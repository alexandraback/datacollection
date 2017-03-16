#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <set>
#include <map>
#include <stack>
using namespace std;

struct attack{
    attack(int l, int r, int s) {
        left=l,right=r,str=s;
    }
    int left,right,str;
};
vector<attack> t[676061];
int ans;
int h[500];
void init() {
    memset(h,0,sizeof(h));
}
void cal(vector<attack> q) {
//
//    for (unsigned i=0;i<q.size();++i)
//        cout<<q[i].left<<' '<<q[i].right<<' '<<q[i].str<<endl;
//    cout<< endl;

    bool suc;
    for (unsigned i = 0; i < q.size();++i) {
        suc = false;
        for (int j=q[i].left+200;j<q[i].right+200;++j)
        if (q[i].str > h[j]) {
            suc = true;
            break;
        }
        ans += suc;
    }

    for (unsigned i = 0; i < q.size();++i) {
        for (int j=q[i].left+200;j<q[i].right+200;++j)
            h[j] = max(h[j],q[i].str);
    }
}
int main() {
    int T;
    int d,k,w,e,s,dd,dp,ds,n;
    cin>>T;
    for (int tt=1;tt<=T;++tt) {
        for (int i = 0; i<= 676060;++i)
            t[i].clear();
        cin>>n;
        for (int i=0;i<n;++i) {
            cin>>d>>k>>w>>e>>s>>dd>>dp>>ds;
            for (int j=0;j<k;++j)
                t[d+j*dd].push_back(attack(w+j*dp,e+j*dp,s+j*ds));
        }
        ans = 0;
        init();
        for (int i = 0;i<=676060;++i)
            if (!t[i].empty())
                cal(t[i]);
        cout<<"Case #"<<tt<<": ";
        cout<<ans<<endl;
    }
    return 0;
}
