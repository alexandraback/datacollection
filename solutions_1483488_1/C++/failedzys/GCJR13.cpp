#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 2000050
int Num,x,y,n,Ans;
int List[10000000][10];
int ff[10];
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    ff[1] = 10;
    for (int i = 2; i <= 7; i++)
        ff[i] = ff[i-1] * 10;
    for (int i = 1; i <= 9999999; i++) for (int j = 1; j <= 6; j++)
        List[i][j] = (i % 10)*ff[j] + i / 10;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d",&x,&y);
        int Limit = 1,Cycle = 0;
        Ans = 0;
        while (Limit * 10 <= x)
            Limit *= 10,Cycle++;
        for (int j = x; j <= y; j++) {
            int tmp = j;
            for (int k = 1; k <= Cycle; k++) {
                tmp = List[tmp][Cycle];
                if (tmp == j)
                    break;
                if (tmp < j && tmp >= x)
                    Ans++;
            }
        }
        printf("Case #%d: %d\n",i,Ans);
    }
}
