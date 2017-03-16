#include <iostream>
#include <cstdio>
using namespace std;
int n;
char str[1007];
int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas=0,t;
    cin >> t;
    while (cin >> n) {
        int ans=0,sum=0;
        cin >> str;
        for (int i=0;i<=n;++i)
        {
            str[i]-='0';
            if (sum<i) {ans+=i-sum;sum=i;}
            sum+=str[i];
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
