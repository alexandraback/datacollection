#include <cstdio>
#include <cstring>
using namespace std;

int t;
char s[1001];
char ans[1001];

int main(void) {
    FILE * input = fopen("input.txt", "r");
    FILE * output = fopen("output.txt", "w");
    fscanf(input, "%d", &t);
    
    for (int tIter = 1; tIter <= t; tIter++) {
        fprintf(output, "Case #%d:", tIter);
        fscanf(input, "%s", s);
        
        ans[0] = s[0];
        for (int i = 1; i < strlen(s); i++) {
            for (int j = 0; j <= i; j++) {
                if (j == i || ans[j] > s[i])  {
                    ans[i] = s[i];
                    break;
                }
                else if (ans[j] < s[i]) {
                    for (int k = i; k >= j+1; k--)
                        ans[k] = ans[k-1];
                    ans[j] = s[i];
                    break;
                }
            }
        }
        ans[strlen(s)] = '\0';
        fprintf(output, " %s\n", ans);
    }
    fclose(input);
    fclose(output);
    return 0;
}