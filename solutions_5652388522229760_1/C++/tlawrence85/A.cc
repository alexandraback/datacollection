#include <stdio.h>

int answers[1000001];

int main(void) {
    FILE *fin = fopen("Agen.out", "r");
    int ind = 1;
    int answer;
    while (fscanf(fin, "%d", &answer) != EOF) {
        answers[ind] = answer;
        ++ind;
    }

    int nC;
    scanf("%d", &nC);
    for (int cC = 1; cC <= nC; ++cC) {
        int input;
        scanf("%d", &input);
        if (input == 0) printf("Case #%d: INSOMNIA\n", cC);
        else printf("Case #%d: %d\n", cC, answers[input]);
    }
    return 0;
}