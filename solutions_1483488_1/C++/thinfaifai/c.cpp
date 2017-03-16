#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int tc,a,b;
int mp[2000005];

int main() {
    scanf("%d",&tc);
    for (int t=1; t<=tc; t++) {
        memset(mp,0,sizeof(mp));
        scanf("%d%d",&a,&b);
        int p10 = 1,ti = a;
        while (ti > 0) {
            p10 *= 10;
            ti /= 10;
        }
        p10 /= 10;
        int s[10];
        for (int i=a; i<=b; i++) {
            s[0] = i;
            int j;
            for (j=1; ; j++) {
                s[j] = s[j-1]%10*p10 + s[j-1]/10;
                if (s[j] == s[0]) break;
            }
            sort(s,s+j);
            mp[s[0]]++;
            //printf("%d: %d\n",i,s[0]);
        }
        int ret = 0;
        for (int i=1; i<=b; i++)
            ret += mp[i]*(mp[i]-1)/2;
        printf("Case #%d: %d\n",t,ret);
    }
}
