#include <cstdio>
#include <cstring>
#include <cstdlib>

long long solve(char *pancakes)
{
    int length = strlen(pancakes);
    char last = pancakes[0];
    long long answer = 0;
    
    for (int i = 1; i < length; i++) {
        if (pancakes[i] != last) {
            answer++;
            last = pancakes[i];
        }
    }
    if (last == '-') answer++;
    return answer;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        long long N;
        char pancakes[200];
        scanf("%s", pancakes);
        long long answer = solve(pancakes);
        printf("Case #%d: %lld\n", t, answer);
    }    
}