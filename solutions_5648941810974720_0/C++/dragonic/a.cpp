#include <bits/stdc++.h>

using namespace std;

/*
"ZERO", = Z
"SIX", = X
"FOUR", = U
"THREE", = R
"TWO", = W
"EIGHT", = H
"FIVE", = F
"SEVEN", = S
"ONE", = O
"NINE"
*/

int main()
{
    int nt;
    cin >> nt;
    
    for (int i = 0; i < nt; i++)
    {
        string test;
        cin >> test;
        
        map<char, int> cnt;
        
        for (char c: test)
            cnt[c]++;
        
        int answer[10] = {};
        
#define fill(index, letter, word) \
        answer[index] = cnt[letter]; \
        for (char c: string(word)) \
            cnt[c] -= answer[index]; \
        
        fill(0, 'Z', "ZERO");
        fill(6, 'X', "SIX");
        fill(4, 'U', "FOUR");
        fill(3, 'R', "THREE");
        fill(2, 'W', "TWO");
        fill(8, 'H', "EIGHT");
        fill(5, 'F', "FIVE");
        fill(7, 'S', "SEVEN");
        fill(1, 'O', "ONE");
        fill(9, 'I', "NINE");
        
        for (auto it: cnt)
        {
            //printf("cnt[%c] is %d\n", it.first, it.second);
            assert(it.second == 0);
        }
        
        printf("Case #%d: ", i + 1);
        for (int digit = 0; digit < 10; digit++)
            for (int i = 0; i < answer[digit]; i++)
                printf("%c", '0' + digit);
        printf("\n");
    }
}

