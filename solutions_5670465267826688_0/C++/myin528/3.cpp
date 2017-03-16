#include <iostream>
using namespace std;

int l, x;
char s[20000];

// 1, i, j, k, -1, -i, -j, -k
// h, i, j, k,  l,  m,  n,  o
// 0, 1, 2, 3,  4,  5,  6,  7
int trans[4][4] = 
{
    {0, 1, 2, 3},
    {1, 4, 3, 6},
    {2, 7, 4, 1},
    {3, 2, 5, 4}
};

char op(char a, char b) {
    int x = a - 'h';
    int y = b - 'h';
    bool changeSign = false;
    if (x > 3) {
        changeSign = !changeSign;
        x -= 4;
    }
    if (y > 3) {
        changeSign = !changeSign;
        y -= 4;
    }
    return (trans[x][y] + (changeSign ? 4 : 0)) % 8 + 'h';
}

bool process() {

    int first_stop = -1, last_stop = -1;
    char current = 'h';
    // printf("%s\n", s);

    for (int i = 0; i < l; i++) {
        current = op(current, s[i]);
    }

    if (current == 'h' ||
        (current >= 'i' && current <= 'k' && x % 4 != 2) ||
        (current == 'l' && x % 2 != 1) ||
        (current >= 'm' && current <= 'o' && x % 4 != 2)) {
        return false;
    }

    current = 'h';

    for (int i = 0; i < l * 10 && i < l * x; i++) {
        current = op(current, s[i % l]);
        // printf("%c ", current);
        if (current == 'i') {
            first_stop = i;
            break;
        }
    }
    // printf("\n");

    current = 'h';

    for (int i = l * x - 1; i >= 0 && i >= l * (x - 10); i--) {
        current = op(s[i % l], current);
        // printf("%c ", current);
        if (current == 'k') {
            last_stop = i;
            break;
        }
    }
    // printf("\n");

    // printf("*%d %d\n", first_stop, last_stop);

    return first_stop >= 0 && last_stop >= 0 && first_stop < last_stop;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test = 0; test < T; test++) {
        scanf("%d %d", &l, &x);
        scanf("%s", s);

        printf("Case #%d: %s\n", test + 1 , process() ? "YES" : "NO");
    }
    return 0;
}