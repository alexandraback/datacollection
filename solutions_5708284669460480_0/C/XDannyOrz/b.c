#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	int TestCase, i, j;
	int K, L, S;
	double banana;
	double Pkey[26];
	double result;
	char c;
	int occurance;
	char tmpstr[100];
	char tmpstr2[100];
	char target[100];

	scanf("%d", &TestCase);
	getchar();
    
    for (i = 1; i <= TestCase; i++) {
        result = 1.0;
        occurance = 0;
        for (j = 0; j < 26; j++) {
            Pkey[j] = 0;
        }
        
        scanf("%d", &K);
        getchar();
        scanf("%d", &L);
        getchar();
        scanf("%d", &S);
        getchar();
        
        for (j = 0; j < K; j++) {
            scanf("%c", &c);
            Pkey[c - 'A'] += 1.0/K;
        }
        getchar();
        
        scanf("%s", &target);
        
        for (j = strlen(target)-1; j > 1; j--) {
            strncpy(tmpstr, target, j);
            strncpy(tmpstr2, &target[strlen(target)-j], j);
            tmpstr[j] = '\0';
            tmpstr2[j] = '\0';
            //printf("%s %s\n", tmpstr, tmpstr2);
            
            if (strcmp(tmpstr, tmpstr2) == 0) {
                occurance = j;    
            }
            break;
        } 
        //printf("%d\n", (strlen(target)-occurance));
        //printf("%d %d\n", strlen(target), S);
        
        banana = 1.0 + (S-strlen(target))/(strlen(target)-occurance);
        //printf("%lf", banana);
        
        for (j = 0; j < strlen(target); j++) {
            if (Pkey[target[j]-'A'] == 0) {
                banana = 0;    
            }
            result *= Pkey[target[j]-'A'];
        }
        //printf("%lf, %lf\n", banana, result);
        // main program here
        printf("Case #%d: %lf\n", i, banana - banana * result);
    }
 
	return 0;
}
