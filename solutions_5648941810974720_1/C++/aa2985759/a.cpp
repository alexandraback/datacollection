#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char s[20100];
int cnt[20100],ans[20100];

int main()
{
    int t;
	scanf("%d", &t);
    for (int ii=1;ii<=t;ii++)
    {
        scanf("%s", s);
        int len = strlen(s);
        memset(cnt, 0, sizeof(cnt));
        memset(ans, 0, sizeof(ans));

        for (int i = 0; i<len; i++)
            cnt[s[i]-'A']++;

        ans[6] = cnt['X'-'A'];
        ans[7] = cnt['S'-'A']-ans[6];
        ans[5] = cnt['V'-'A']-ans[7];
        ans[4] = cnt['F'-'A']-ans[5];
        ans[2] = cnt['W'-'A'];
        ans[0] = cnt['Z'-'A'];
        ans[1] = cnt['O'-'A']-ans[2]-ans[4]-ans[0];
        ans[3] = cnt['R'-'A']-ans[0]-ans[4];
        ans[8] = cnt['G'-'A'];
        ans[9] = cnt['I'-'A']-ans[5]-ans[6]-ans[8];

        printf("Case #%d: ", ii);
        for (int i = 0; i<10; i++)
        {
            for (int j = 0; j<ans[i]; j++)
                printf("%d", i);
        }
        puts("");
    }


}
