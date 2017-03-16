/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

#define read(word) {for(const char &w: word) if(w) -- letter[w - 'A'];}

int tests;
char word[2048];

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        int letter[32] = {};
        int count[16] = {};

        scanf("%s", word);
        printf("Case #%d: ", t + 1);
        for(int w = 0; word[w]; ++ w)
            ++ letter[word[w] - 'A'];

        // Zero
        while(letter['Z' - 'A'])
        {
            ++ count[0];
            read("ZERO");
        }

        // Two
        while(letter['W' - 'A'])
        {
            ++ count[2];
            read("TWO");
        }

        // Four
        while(letter['U' - 'A'])
        {
            ++ count[4];
            read("FOUR");
        }

        // Five
        while(letter['F' - 'A'])
        {
            ++ count[5];
            read("FIVE");
        }

        // One
        while(letter['O' - 'A'])
        {
            ++ count[1];
            read("ONE");
        }

        // Three
        while(letter['R' - 'A'])
        {
            ++ count[3];
            read("THREE");
        }

        // Six
        while(letter['X' - 'A'])
        {
            ++ count[6];
            read("SIX");
        }

        // Seven
        while(letter['V' - 'A'])
        {
            ++ count[7];
            read("SEVEN");
        }

        // Eight
        while(letter['G' - 'A'])
        {
            ++ count[8];
            read("EIGHT");
        }

        // Nine
        while(letter['N' - 'A'])
        {
            ++ count[9];
            read("NINE");
        }

        for(int c = 0; c < 10; ++ c)
            while(count[c])
            {
                -- count[c];
                putchar(c + '0');
            }

        puts("");
    }

    return 0;
}
