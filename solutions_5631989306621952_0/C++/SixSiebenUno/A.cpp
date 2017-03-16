#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MaxN = 1007;

int T,n;
string str,ans;

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&T);
    for (int i=1; i<=T; i++)
    {
        printf("Case #%d: ",i);
        cin >> str;
        n = str.size();
        ans = "";
        for (int j=0; j<n; j++)
        {
            if(str[j]+ans > ans+str[j]) ans = str[j] + ans;
            else ans = ans + str[j];
        }
        cout << ans; printf("\n");
    }
    return 0;
}
