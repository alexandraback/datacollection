#include <stdio.h>
#include <string.h>
#include <deque>

using namespace std;

void solve() {
    char input[1001];
    scanf("%s", input);

    deque<char> output;
    int len = strlen(input);
    output.push_front(input[0]);
    for (int i = 1; i < len; ++i) {
        if (input[i] >= output.front())
            output.push_front(input[i]);
        else
            output.push_back(input[i]);
    }

    for (deque<char>::iterator it = output.begin(); it != output.end(); ++it) {
        printf("%c", *it);
    }
    printf("\n");
}

int main(void) {
    int nC;
    scanf("%d", &nC);
    for (int cC = 0; cC < nC; ++cC) {
        printf("Case #%d: ", cC + 1);
        solve();
    }

    return 0;
}