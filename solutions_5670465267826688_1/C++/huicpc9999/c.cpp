#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int L, X;
string str;

int multi(int x, int y)
{
    int flag = 1;
    if (x < 0) {flag *= -1; x = -x;}
    if (y < 0) {flag *= -1; y = -y;}
    if (x == 1) return flag * y;
    if (y == 1) return flag * x;
    int ans;
    if (x == y) ans = -1;
    if (x == 'i')
        if (y == 'j') ans = 'k';
        else if (y == 'k') ans = -'j';
    if (x == 'j')
        if (y == 'i') ans = -'k';
        else if (y == 'k') ans = 'i';
    if (x == 'k')
        if (y == 'i') ans = 'j';
        else if (y == 'j') ans = -'i';
    return flag * ans;
}
void printChar(int x)
{
    if (x < 0){printf("-"); x = -x;}
    if (x == 1){printf("1"); return;}
    printf("%c", x);
}
bool judge1()
{
    int tms = X % 4;
    if (tms == 0) tms = 4;
    int total = 1, one = 1;
    //printf("one = ");
    for (int i = 0; i < L; ++i)
    {
        one = multi(one, str[i]);
        //printChar(one);
        //printf(" ");
    }
    //printf("\n");
    for (int i = 0; i < tms; ++i)
        total = multi(total, one);
    //printf("total = "); printChar(total); puts("");
    return total == -1;
}
bool judge2()
{
    int tmp = 1, len1, len2, p;
    for (p = 0, len1 = 1; len1 <= 4*L; ++p, ++len1)
    {
        tmp = multi(tmp, str[p%L]);
        if (tmp == 'i') break;
    }
    if (len1 > 4*L) return false;
    tmp = 1;
    for (p = L-1, len2 = 1; len2 <= 4*L; --p, ++len2)
    {
        tmp = multi(str[((p%L)+L)%L], tmp);
        if (tmp == 'k') break;
    }
    if (len2 > 4*L) return false;
    if (len1 + len2 < X*L) return true;
    return false;
}
int main()
{
    //freopen("C-large.in", "r", stdin);
    //freopen("C-large.out", "w", stdout);
    int T; scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        cin >> L >> X >> str;
        printf("Case #%d: %s\n", cas, (judge1() && judge2())?("YES"):("NO")); //
    }
    return 0;
}
