#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

char input[5000];
int cnt[256];

string digits[] = {
    "ZERO",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",
    "EIGHT",
    "NINE"};

void reduce(int i, int m)
{
    for(auto x: digits[i])
        cnt[x] -= m;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca)
    {
        scanf("%s", input);
        memset(cnt, 0, sizeof(cnt) );
        int len = strlen(input);
        for(int i = 0; i < len; ++i)
            cnt[ input[i] ] += 1;
        int num[10] = {0};

        num[0] = cnt['Z'];
        reduce(0, num[0]);
        num[2] = cnt['W'];
        reduce(2, num[2]);
        num[4] = cnt['U'];
        reduce(4, num[4]);
        num[5] = cnt['F'];
        reduce(5, num[5]);
        num[7] = cnt['V'];
        reduce(7, num[7]);
        num[3] = cnt['R'];
        reduce(3, num[3]);
        num[1] = cnt['O'];
        reduce(1, num[1]);
        num[6] = cnt['S'];
        reduce(6, num[6]);
        num[8] = cnt['T'];
        reduce(8, num[8]);
        num[9] = cnt['I'];
        printf("Case #%d: ", ca);
        for(int i = 0; i < 10; ++i)
            for(int j = 0; j < num[i]; ++j)
                printf("%d", i);
        printf("\n");
    }
}
