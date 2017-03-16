#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>#include <cstdio>
using namespace std;
string res;
int u,R,N,M,K,v;
int a[10];

int f(int fact, int num) {
    int p = 0;
    while (num%fact==0) {
        p++;
        num/=fact;
    }
    return p;
}

string check() {
    int n3=0;
    int n5=0;
    for (int i=0;i<7;++i) {
        n3 = max(n3, f(3,a[i]));
        n5 = max(n5, f(5,a[i]));
    }
    string res = "";
    for (int i=0;i<n3;++i) res+="3";
    for (int i=0;i<n5;++i) res+="5";
    for (int i = 0; i<3-n3-n5;++i) res+="2";
    res = res.substr(0,3);
    return res;
}
int main () {    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for (int cas=1;cas<=T;++cas) {
        cout<<"Case #"<<cas<<":"<<endl;
        cin>>R>>N>>M>>K;
        for (int i=0;i<R;++i) {

            u = -10;
            v = 10000;
            for (int j=0;j<K;++j) {
                    cin>>a[j];
                    u = max(u,a[j]);
                    v = min(v,a[j]);
            }
            switch (u) {
            case 60: res = "345"; break;
            case 24: res = "234"; break;
            case 30: res = "235"; break;
            case 40: res = "245"; break;
            case 36: res = "334"; break;
            case 100: res = "455"; break;
            case 64: res = "444"; break;
            case 1: res = "222"; break;
            default: res = check(); break;
            }
            cout<<res<<endl;
        }    }
    return 0;
}
