#include <cstdio>
using namespace std;

const int Maxn = 1005;

int T;
int N;
int a[Maxn], b[Maxn];
int st, lvl[Maxn], need;
int res;

int Find(int w, int a[])
{
    int res = -1;
    for (int i = 0; i < N; i++)
        if (lvl[i] < w && st >= a[i])
            if (w == 2) return i;
            else if (res == -1 || b[i] > b[res]) res = i;
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &a[i], &b[i]);
            lvl[i] = 0;
        }
        st = 0; need = N;
        res = 0;
        while (need) {
            int ind;
            if ((ind = Find(2, b)) != -1) {
                st += 2 - lvl[ind]; lvl[ind] = 2; need--;
            } else if ((ind = Find(1, a)) != -1) {
                st++; lvl[ind] = 1;
            } else break;
            res++;
        }
        printf("Case #%d: ", tc);
        if (need) printf("Too Bad\n");
        else printf("%d\n", res);
    }
    return 0;
}
