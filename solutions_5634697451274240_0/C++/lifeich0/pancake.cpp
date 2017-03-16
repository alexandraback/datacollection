#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char str[299];

int main()
{
    int sTT;
    scanf("%d", &sTT);
    for (int TT = 1; TT <= sTT; ++TT)
    {
        scanf("%s", str);
        int ans = 0;
        for (int i = 1; i < strlen(str); ++i)
            if (str[i - 1] == '+' && str[i] == '-') ++ ans;
        printf("Case #%d: %d\n", TT, ans + ans + (str[0] == '-'));
        //printf(">%s\n", str);
    }
    return 0;
}
