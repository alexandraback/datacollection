#include <cstdio>

char map[] = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q', };

int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    int test_cases;
    scanf("%d ", &test_cases);
    for (int test_num = 1; test_num <= test_cases; test_num++) {
        int len = 0;
        char str[110], tmp = '\0';
        while (tmp < 'a' || tmp > 'z')
            scanf("%c", &tmp);
        while (tmp != '\n') {
            str[len++] = tmp;
            scanf("%c", &tmp);
        }
        
        for (int i = 0; i < len; i++)
            if ('a' <= str[i] && str[i] <= 'z')
                str[i] = map[str[i] - 'a'];
        str[len] = '\0';
        
        printf("Case #%d: %s\n", test_num, str);
    }
}