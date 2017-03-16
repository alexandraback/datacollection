#pragma warning(disable:4996)

#include <stdio.h>

int cnt[256];

int main()
{
    freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);

    int t, tt=0;
    scanf("%d", &t);
    while(t--)
    {
        static char s[2004];
        scanf("%s", s);
        for (int i=0; i<256; i++) cnt[i] = 0;
        for (int i=0; s[i]; i++)
            cnt[s[i]]++;

        int ans[10];
        for (int i=0; i<10; i++) ans[i]=0;

        ans[0] += cnt['Z'];
        cnt['E'] -= cnt['Z'];
        cnt['R'] -= cnt['Z'];
        cnt['O'] -= cnt['Z'];
        cnt['Z'] -= cnt['Z'];

        ans[2] += cnt['W'];
        cnt['T'] -= cnt['W'];
        cnt['O'] -= cnt['W'];
        cnt['W'] -= cnt['W'];

        ans[6] += cnt['X'];
        cnt['S'] -= cnt['X'];
        cnt['I'] -= cnt['X'];
        cnt['X'] -= cnt['X'];

        ans[8] += cnt['G'];
        cnt['E'] -= cnt['G'];
        cnt['I'] -= cnt['G'];
        cnt['H'] -= cnt['G'];
        cnt['T'] -= cnt['G'];
        cnt['G'] -= cnt['G'];

        ans[4] += cnt['U'];
        cnt['F'] -= cnt['U'];
        cnt['O'] -= cnt['U'];
        cnt['R'] -= cnt['U'];
        cnt['U'] -= cnt['U'];
        
        ans[3] += cnt['R'];
        cnt['T'] -= cnt['R'];
        cnt['H'] -= cnt['R'];
        cnt['E'] -= cnt['R'];
        cnt['E'] -= cnt['R'];
        cnt['R'] -= cnt['R'];

        ans[5] += cnt['F'];
        cnt['I'] -= cnt['F'];
        cnt['V'] -= cnt['F'];
        cnt['E'] -= cnt['F'];
        cnt['F'] -= cnt['F'];

        ans[7] += cnt['V'];
        cnt['S'] -= cnt['V'];
        cnt['E'] -= cnt['V'];
        cnt['E'] -= cnt['V'];
        cnt['N'] -= cnt['V'];
        cnt['V'] -= cnt['V'];

        ans[7] += cnt['V'];
        cnt['S'] -= cnt['V'];
        cnt['E'] -= cnt['V'];
        cnt['E'] -= cnt['V'];
        cnt['N'] -= cnt['V'];
        cnt['V'] -= cnt['V'];

        ans[1] += cnt['O'];
        cnt['N'] -= cnt['O'];
        cnt['E'] -= cnt['O'];
        cnt['O'] -= cnt['O'];

        ans[9] += cnt['I'];

        printf("Case #%d: ", ++tt);
        for (int i=0; i<10; i++)
            for (int j=0; j<ans[i]; j++)
                printf("%d", i);
        printf("\n");
    }

    return 0;
}
