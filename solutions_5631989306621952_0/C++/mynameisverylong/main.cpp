#include <stdio.h>
#include "stdlib.h"
#include "string"

using namespace std;

char s[1100];
string ans;

int main() {
    freopen("A-small-attempt0.in.txt", "r", stdin);
    freopen("A-small-attempt0.out.txt", "w", stdout);
    int t,tt;
    scanf("%d",&tt);
    for (t=1;t<=tt;t++){
        scanf("%s",s);
        ans=s[0];
        for (int i=1;s[i];i++){
            if (s[i]>=ans[0])
                ans=s[i]+ans;
            else
                ans=ans+s[i];
        }
        printf("Case #%d: %s\n",t,ans.c_str());
    }
    return 0;
}
