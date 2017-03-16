#include <cstdio>
#include <cstring>

using namespace std;

int a[26];
int b[10];
char s[2001];

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, j;
        
        scanf("%s", s);
        
        n = strlen(s);
        
        for (j = 0; j < 26; j++) a[j] = 0;
        
        for (j = 0; j < n; j++) a[s[j] - 'A']++;
        
        for (j = 0; j < 10; j++) b[j] = 0;
        
        b[0] = a['Z' - 'A'];
        b[2] = a['W' - 'A'];
        b[4] = a['U' - 'A'];
        b[6] = a['X' - 'A'];
        b[8] = a['G' - 'A'];
        b[1] = a['O' - 'A'] - b[0] - b[2] - b[4];
        b[3] = a['R' - 'A'] - b[0] - b[4];
        b[5] = a['F' - 'A'] - b[4];
        b[7] = a['V' - 'A'] - b[5];
        b[9] = a['I' - 'A'] - b[5] - b[6] - b[8];
        
        printf("Case #%d: ", i + 1);
        
        for (j = 0; j < 10; j++) {
            while (b[j] > 0) {
                putchar(j + '0');
                b[j]--;
            }
        }
        
        puts("");
    }
    
    return 0;
}
