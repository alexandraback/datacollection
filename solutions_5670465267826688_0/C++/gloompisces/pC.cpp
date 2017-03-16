#include <stdio.h>
#include <iostream>
using namespace std;

int multi(char &x, char y)
{
    if (x == 'i')
    {
        if (y == 'i')
        {
            x = '1';
            return -1;
        }
        else if (y == 'j')
        {
            x = 'k';
            return 1;
        }
        else if (y == 'k')
        {
            x = 'j';
            return -1;
        }
        else // if (y == '1')
        {
            x = 'i';
            return 1;
        }
    }
    else if (x == 'j')
    {
        if (y == 'i')
        {
            x = 'k';
            return -1;
        }
        else if (y == 'j')
        {
            x = '1';
            return -1;
        }
        else if (y == 'k')
        {
            x = 'i';
            return 1;
        }
        else // if (y == '1')
        {
            x = 'j';
            return 1;
        }
    }
    else if (x == 'k')
    {
        if (y == 'i')
        {
            x = 'j';
            return 1;
        }
        else if (y == 'j')
        {
            x = 'i';
            return -1;
        }
        else if (y == 'k')
        {
            x = '1';
            return -1;
        }
        else // if (y == '1')
        {
            x = 'k';
            return 1;
        }
    }
    else // if (x == '1')
    {
        if (y == 'i')
        {
            x = 'i';
            return 1;
        }
        else if (y == 'j')
        {
            x = 'j';
            return 1;
        }
        else if (y == 'k')
        {
            x = 'k';
            return 1;
        }
        else // if (y == '1')
        {
            x = '1';
            return 1;
        }
    }
}

int main()
{
    
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    /*freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    */
    
    char str[10005];
    
    int cases;
    scanf("%d", &cases);
    for (int c = 1; c <= cases; c++)
    {
        int L;
        long long int X;
        cin >> L >> X;
        scanf("%s", &str);
        
        int state = 1;
        int mul = 1;
        char ch = '1';
        
        long long int start_r = 1;
        int start_s = 0;
        for (long long int r = 1; r <= X; r++)
        {
            for (int s = 0; s < L; s++)
            {
                //printf("%d %c %c ", state, ch, str[s]);
                mul *= multi(ch, str[s]);
                //printf("%c\n", ch);
                
                if (state == 1)
                {
                    if (mul == 1 && ch == 'i')
                    {
                        state = 2;
                        if (s == L - 1)
                        {
                            start_r = r + 1;
                            start_s = 0;
                        }
                        else
                        {
                            start_r = r;
                            start_s = s + 1;
                        }
                        mul = 1;
                        ch = '1';
                    }
                }
                else if (state == 2)
                {
                    if (mul == 1 && ch == 'j')
                    {
                        state = 3;
                        if (s == L - 1)
                        {
                            start_r = r + 1;
                            start_s = 0;
                        }
                        else
                        {
                            start_r = r;
                            start_s = s + 1;
                        }
                        mul = 1;
                        ch = '1';
                    }
                }
                else // state = 3
                {
                    long long int XX = X - start_r;
                    XX %= 4;
                    X = start_r + XX;
                }
                
                if (r - start_r >= 4 && s >= start_s)
                {
                    goto end;
                }
            }
        }
        
        if (state == 3)
        {
            if (mul == 1 && ch == 'k')
            {
                state = 4;
            }
        }
        
    end:
        if (state == 4)
        {
            printf("Case #%d: YES\n", c);
        }
        else
        {
            printf("Case #%d: NO\n", c);
        }
    }
    
    return 0;
}
