#include <cstdio>
#include <cstring>
using namespace std;

int T;
int S;
char s[1002];
int main () {
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
        scanf("%d",&S);
        scanf("%s",s);
        int sum = 0;
        int current = s[0] - '0';
        for (int i=1;i<=S;++i) {
            if (current < i) sum += i-current, current=i;
            current += s[i] - '0';
        }
        printf("Case #%d: %d\n",z,sum);
    }
}
