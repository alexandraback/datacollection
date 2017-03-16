#include <cstdio>
FILE *fin, *fout;
using namespace std;
int t, c, r, w;
int main()
{
    fin = freopen("small1.in", "r", stdin);
    fout = freopen("small1.out", "w", stdout);
    scanf("%d", &t);
    for(int i = 1; i<= t; i++)
    {
        scanf("%d%d%d", &r, &c, &w);
        if(c%w == 0) printf("Case #%d: %d\n", i, c/w + w - 1);
        else printf("Case #%d: %d\n", i, c/w + w);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
