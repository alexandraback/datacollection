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
string s;
int n,k;
int f[1000100];
int pre[1000100];
int main() {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {

        cin>>s>>k;
        n = s.size();
        s  = "." + s;
        for (int i = 1;i<=n;++i) {
            if (s[i]!='a' && s[i]!='e' &&s[i]!='i' &&s[i]!='o' &&s[i]!='u')
                f[i] = f[i-1]+1;
            else
                f[i] = 0;
        }
        pre[0] = -1;
        for (int i=1;i<=n;++i) {
            pre[i] = pre[i-1];
            if (f[i]>=k) {
                pre[i] = i - k + 1;
            }
        }
        long long sum = 0;
        for (int i=1;i<=n;++i)
            if (pre[i]>=0)
                sum = sum + pre[i];
        cout<<"Case #"<<t<<": ";
        cout<<sum<<endl;
    }
    return 0;
}




