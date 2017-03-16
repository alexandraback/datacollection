#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T;
    string s;
    cin>>T;
    for(int ca=1;ca<=T;ca++) {
        cin>>s;
        cout<<"Case #"<<ca<<": ";
        int N = s.length();
        int ans = 0;
        for(int i=N-1;i>=0;i--) {
            if(s[i] == '+') continue;
            ans++;
            for(int j=0;j<=i;j++) {
                if(s[j] == '+') s[j] = '-';
                else s[j] = '+';
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
