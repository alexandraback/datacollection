
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

inline bool isVowel(char c)
{
    return c == 'a'  || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int solve()
{
    char input[128];
    scanf("%s", input);

    int n;
    scanf("%d", &n);

    int len = strlen(input);

    int answer = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            int max_c = 0, current_c = 0;
            for (int p = i; p <= j; p++)
            {
                if (isVowel(input[p]) == false)
                {
                    current_c++;
                    max_c = max(max_c, current_c);
                }
                else
                {
                    current_c = 0;
                }
            }

            if (n <= max_c)
            {
                answer++;
            }
        }
    }

    return answer;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int n;
    scanf("%d", &n);

    for (int t = 1; t <= n; t++)
    {
        printf("Case #%d: %d\n", t, solve());
    }
}