#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char in[1000099];
char s[1000099];
int n;

int main() {
    int T, L, i;
    scanf("%d\n", &T);
    for(i=1;i<=T;i++) {


       long long int sol = 0;
       int prev = -1;
       int j = 0;
       L = 0;
       int p = 0;
       char tmp = 'a';

       while (1)
       {
           scanf("%c", &tmp);
           if (tmp != ' ')
           {
               in[j] = tmp;
               j++;
           }
           else break;
       }
       L = j;

       scanf("%d\n", &n);

       int cnt = 0;
       int k = 0;
       for (j=0; j<L; j++)
       {
           if (in[j] != 'a' && in[j] != 'e' && in[j] != 'i' && in[j] != 'o' && in[j] != 'u')
           {
               cnt++;
           }
           else
           {
               cnt = 0;
           }

           if (cnt >= n)
           {
               s[k] = j - n + 1;
               k++;
           }
       }

       p = k;

       for (j = 0; j<p; j++)
       {
            sol += ( (long long int)s[j] - (long long int)prev ) * ( (long long int)L - (long long int)s[j] - (long long int)n + 1);
            prev = s[j];
       }



        printf("Case #%d: ", i);
        printf("%lld\n", sol);
    }
    return 1;
}

