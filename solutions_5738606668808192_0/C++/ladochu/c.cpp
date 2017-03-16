#include <cstdio>
#include <string>
using std::string;

int main() {
    int T;
    scanf("%d", &T);

    for (int I = 1; I <= T; I++) {
        int N, J;
        scanf("%d%d", &N, &J);
        printf("Case #%d:\n", I);

        for (int i = 0; i < J; i++) {
            string output;
            int tmp;
            for (output = "11", tmp = i; output.length() < N; tmp /= 2) {
                if (tmp % 2) {
                    output.insert(1, "00");
                } else {
                    output.insert(1, "11");
                }
            }
            printf("%s 3 2 5 2 7 2 9 2 11\n", output.data());
        }
    }
}
