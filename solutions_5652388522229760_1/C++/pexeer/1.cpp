#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <algorithm>

void solve(int T) {
    int result = 0;
    std::vector<char>   N;
    std::vector<char>   R;
    char input[10];
    scanf("%s", input);
    for (int i = 0; input[i]; ++i) {
        N.push_back(input[i] - '0');
    }
    if (N.size() == 1 && N[0] == 0) {
        printf("Case #%d: INSOMNIA\n", T);
        return ;
    }

    std::reverse(N.begin(), N.end());
    R = N;

    char bitmap[10];
    for (int i = 0; i < 10; ++i) {
        bitmap[i] = 1;
    }
    for (uint64_t dtry = 1; dtry < 90000000L; ++dtry) {
        // check R
        char carry = 0;
        for (int i =0; i < R.size(); ++i) {
            carry = R[i] + carry;
            R[i] =  carry % 10;
            carry = carry / 10;
            if (bitmap[R[i]]) {
                bitmap[R[i]] = 0;
                ++result;
            }
        }

        if (carry) {
            R.push_back(1);
            if (bitmap[1]) {
                bitmap[1] = 0;
                ++result;
            }
        }

        if (result == 10) {
             printf("Case #%d: ", T);
             for (int i = R.size() - 1; i >= 0; --i) {
                 printf("%d", R[i]);
             }
             printf("\n");
             return ;
        }

        // R + N
        for (int i =0; i < N.size(); ++i) {
            R[i] += N[i];
        }
    }
    printf("Case #%d: INSOMNIA\n", T);
}

int main(int argc, char* argv[]) {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve(i + 1);
    }
    return 0;
}
