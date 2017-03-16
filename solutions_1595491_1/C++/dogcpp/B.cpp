#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//#define N 100010
int T, N, S, p, zzy, xwj;
int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    scanf("%d", &T);
    for(int j = 1; j <= T; ++j)
    {
        scanf("%d%d%d", &N, &S, &p);
        int ans = 0;
        for(int i = 1; i <= N; ++i)
        {
            scanf("%d", &xwj);
            zzy = xwj / 3;
            if(xwj > zzy * 3) {
				++zzy;
			}
			/*if(xwj >= zzy * 3) {
				++zzy;
			}*/
            if(zzy >= p) {
				++ans;//zzy nie
			}
            else if(xwj % 3 != 1 && xwj != 0 && S > 0 && zzy + 1 >= p) ++ans, --S;
        }
        printf("Case #%d: %d\n", j, ans);
    }
    //system("pause");
    return 0;
}
