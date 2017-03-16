#include <cstdio>
#include <cstring>

/*
ZERO
ONE
TWO
THREE
FOUR
FIVE
SIX
SEVEN
EIGHT
NINE
*/


void work()
{
    char s[10000];
    int ans[10] = {0};
    int count[100] = {0};
    scanf("%s", s);
    for (int i = 0, n = strlen(s); i < n; i++) {
        count[s[i]]++;
    }
    ans[0] = count['Z'];
    count['Z'] -= ans[0];
    count['E'] -= ans[0];
    count['R'] -= ans[0];
    count['O'] -= ans[0];
    ans[2] = count['W'];
    count['T'] -= ans[2];
    count['W'] -= ans[2];
    count['O'] -= ans[2];
    ans[4] = count['U'];
    count['F'] -= ans[4];
    count['O'] -= ans[4];
    count['U'] -= ans[4];
    count['R'] -= ans[4];
    ans[1] = count['O'];
    count['O'] -= ans[1];
    count['N'] -= ans[1];
    count['E'] -= ans[1];
    ans[3] = count['R'];
    count['T'] -= ans[3];
    count['H'] -= ans[3];
    count['R'] -= ans[3];
    count['E'] -= ans[3];
    count['E'] -= ans[3];
    ans[8] = count['G'];
    count['E'] -= ans[8];
    count['I'] -= ans[8];
    count['G'] -= ans[8];
    count['H'] -= ans[8];
    count['T'] -= ans[8];
    ans[6] = count['X'];
    count['S'] -= ans[6];
    count['I'] -= ans[6];
    count['X'] -= ans[6];
    ans[5] = count['F'];
    count['F'] -= ans[5];
    count['I'] -= ans[5];
    count['V'] -= ans[5];
    count['E'] -= ans[5];
    ans[7] = count['S'];
    count['S'] -= ans[7];
    count['E'] -= ans[7];
    count['V'] -= ans[7];
    count['E'] -= ans[7];
    count['N'] -= ans[7];
    ans[9] = count['E'];
    count['N'] -= ans[9];
    count['I'] -= ans[9];
    count['N'] -= ans[9];
    count['E'] -= ans[9];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < ans[i]; j++) {
            printf("%d", i);
        }
    }
    puts("");

}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        work();
    }
}