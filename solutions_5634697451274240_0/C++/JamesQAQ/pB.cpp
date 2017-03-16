#include <stdio.h>
#include <string.h>
#include <iostream>
using std::swap;

int main()
{
    int cases;
    scanf("%d", &cases);
    for (int t = 1; t <= cases; t++){
        int ans = 0, len;
        char s[101];
        scanf("%s", s);
        len = strlen(s);
        do{
            while (len > 0 && s[len - 1] == '+')
                len--;
            if (len > 0){
                if (s[0] == '+' && s[len - 1] == '-'){
                    int pos = len - 1;
                    while (s[pos] == '-')
                        pos--;
                    pos++;
                    ans++;
                    for (int i = 0; i < pos / 2; i++)
                        swap(s[i], s[pos - i - 1]);
                    for (int i = 0; i < pos; i++){
                        if (s[i] == '+')
                            s[i] = '-';
                        else
                            s[i] = '+';
                    }
                }
                else{
                    ans++;
                    for (int i = 0; i < len / 2; i++)
                        swap(s[i], s[len - i - 1]);
                    for (int i = 0; i < len; i++){
                        if (s[i] == '+')
                            s[i] = '-';
                        else
                            s[i] = '+';
                    }
                }
            }
        } while (len > 0);
        
        printf("Case #%d: %d\n", t, ans);
    }
}

/*

Input 
 	
Output 
 
5
-
-+
+-
+++
--+-

Case #1: 1
Case #2: 1
Case #3: 2
Case #4: 0
Case #5: 3


*/
