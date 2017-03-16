#include <stdio.h>
#include <string.h>

bool all_visited(int digit[10]) {
    for (int i=0;i<10;i++) {
        if (!digit[i])
            return false;
    }
    return true;
}
int main()
{
    int T;
    int N; 
    char line[2000];
    char ans[6000];
    int len;
    int ans_len;
    scanf("%d", &T);
    for (int Ti=1;Ti<=T;Ti++) {
        printf("Case #%d: ", Ti);
        scanf("%s\n", line);
        len = strlen(line);
        int ans_start=3000;
        int ans_end=3001;
        ans[ans_start--] = line[0];
        char first_c = line[0];
        for (int i=1;i<len;i++) {
            if (line[i]<first_c) {
                ans[ans_end++] = line[i];
            }else {
                ans[ans_start--] = line[i];
                first_c = line[i];
            }
        }
        ans[ans_end] = '\0';
        printf("%s\n", &ans[ans_start+1]);
    }
    return 0;
}


