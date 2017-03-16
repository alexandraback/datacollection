#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
typedef long long LL;
#define MAXN 100


int main()
{
    int T;
    
    freopen("/Users/thedream/Desktop/cpp/cpp/input","r",stdin);
    freopen("/Users/thedream/Desktop/cpp/cpp/output","w",stdout);
    
    scanf("%d",&T);
    
    for (int t=1;t<=T;t++) {
        string a;
        cin >> a;
        string ans;
        
        ans += a[0];
        
        for(int i=1;i<a.length();i++){
            if(ans[0] > a[i] ){
                ans += a[i];
            } else {
                ans = a[i] + ans;
            }
        }
        printf("Case #%d: %s\n",t,ans.c_str());
    }
    
    return 0;
}