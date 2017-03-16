#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int tc, t;
    char input[102];

    scanf("%d\n", &tc);
    for (t = 1; t <= tc; t++) {
        fgets(input, 101, stdin);
        input[strlen(input) - 1] = '+';
        int cnt = 0;
        for (int i = 1; i < strlen(input); i++) {
            if (input[i] != input[i - 1]) 
                cnt++;
        }
        printf("Case #%d: %d\n", t, cnt);
    }
    return 0;
}
