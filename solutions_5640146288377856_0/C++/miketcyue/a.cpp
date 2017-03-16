#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
using namespace std;


int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T;
    cin>>T;
    int cas = 1;
    while (T--) {
        int W,R,C;
        cin>>R>>C>>W;
        int ans = 0;
        ans += R * (C / W);
        ans += W - 1;
        if (C % W != 0) ans++;
        printf("Case #%d: %d\n",cas++,ans);
    }
}
