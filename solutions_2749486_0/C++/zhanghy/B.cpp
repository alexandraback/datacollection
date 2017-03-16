#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int T,x,y;
    scanf("%d",&T);
    for (int kase = 1;kase <= T; kase++) {
        scanf("%d%d",&x,&y);
        printf("Case #%d: ",kase);
        for (int i = 1;i <= 2*abs(x); i++) {
            char ch;
            ch = (((x > 0) + i % 2)%2)?'E':'W';
            printf("%c",ch);
        }
        for (int i = 1;i <= 2*abs(y); i++) {
            char ch;
            ch = (((y > 0) + i % 2)%2)?'N':'S';
            printf("%c",ch);
        }
        printf("\n");
    }
    return 0;
}
