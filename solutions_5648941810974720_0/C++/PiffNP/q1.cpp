#include <stdio.h>
#define LEN 3000
char s[LEN];
char a[LEN], b[LEN];
int main(){
    int t;
    char alpha[10][200] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE",
                            "SIX", "SEVEN", "EIGHT", "NINE"};
    char key[10] = {'Z', 'X', 'G', 'W', 'U', 'F', 'V', 'T', 'O', 'I'};
    int r[10] = {0, 6, 8, 2, 4, 5, 7, 3, 1, 9};
    FILE *fp1, *fp2;
    if((fp1 = fopen("a.in", "r")) == NULL)
        return 1;
    fp2 = fopen("a.out", "w");
    fscanf(fp1, "%d", &t);
    for(int i = 0; i < t; i++){
        fscanf(fp1, "%s", s);
        int count[200] = {0};
        int ans[10] = {0};
        for(int j = 0; j < 10; j++)
            ans[j] = 0;
        int num = 0;
        for(num = 0; s[num] != '\0'; num++){
            count[s[num]]++;    
        }
        fprintf(fp2, "Case #%d: ", i + 1);
        for(int j = 0; j < 10; j++){
            int flag = 1;
            if(count[key[j]] > 0){
                for(int k = 0; alpha[r[j]][k] != '\0'; k++)
                    count[alpha[r[j]][k]]--;
                ans[r[j]]++;
                j--;
            }
        }
        for(int j = 0; j < 10; j++)
            for(int k = 0; k < ans[j]; k++)
                fprintf(fp2, "%d", j);
        fprintf(fp2, "\n");
    }
    return 0;
}
