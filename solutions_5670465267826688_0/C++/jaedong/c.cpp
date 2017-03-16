#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

const char *answer[] = {"NO", "YES"};
const int I = 2, J = 3, K = 4;
const int mul_matrix[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, I, J, K},
    {0, I, -1, K, -J},
    {0, J, -K, -1, I},
    {0, K, J, -I, -1}};

int mul(int a, int b) {
    int sign_a = a < 0 ? -1 : 1;
    int sign_b = b < 0 ? -1 : 1;
    return mul_matrix[abs(a)][abs(b)] * sign_a * sign_b;
}

int toq(char c) {
    switch (c) {
    case 'i': return I;
    case 'j': return J;
    case 'k': return K;
    }
    assert(0);
}

int l;
uint64_t x;
char line[10001];

bool solve() {
    int prod = 1;
    bool i_found = false, k_found = false; 
    for (int rep = 0; rep < x; rep++) {
        for (int i = 0; i < l; i++) {
            prod = mul(prod, toq(line[i]));
            if (prod == I)
                i_found = true;
            if (prod == K and i_found)
                k_found = true;
        }
    }
    return k_found and prod == -1;
}

int main() {
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        scanf("%d%lu%s", &l, &x, line);
        printf("Case #%d: %s\n", cs, answer[solve()]);
    }
}
