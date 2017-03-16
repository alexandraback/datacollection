#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int cas;
    const int MASK = (1<<10)-1;
    scanf(" %d", &cas);
    for (int i = 0; i < cas; ++i) {
        int n;
        scanf(" %d", &n);
        printf("Case #%d: ", i+1);
        if (n == 0) {
            printf("INSOMNIA\n");
            continue;
        }
        int state = 0;
        int num = 0;
        while (state != MASK) {
            num += n;
            int tmp = num;
            while (tmp) {
                state |= 1<<(tmp%10);
                tmp /= 10;
            }
        }
        printf("%d\n", num);
    }
    return 0;
}
