#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>


using namespace std;

#define T_INT long long unsigned int

inline T_INT get_digit(const T_INT &num, const T_INT &digit_multiplier) {
    return (num % (digit_multiplier * 10)) / digit_multiplier;
}

bool is_fair(T_INT &number) {
    T_INT last_multiplier = 1;
    T_INT first_multiplier = 1;
    T_INT tmp = number / 10;
    while (tmp) {
        first_multiplier *= 10;
        tmp /= 10;
    }
    do {
        T_INT last_digit = get_digit(number, last_multiplier);
        T_INT first_digit = get_digit(number, first_multiplier);
        if (last_digit != first_digit)
            return false;
        last_multiplier *= 10;
        first_multiplier /= 10;
    } while ((first_multiplier >= last_multiplier) && (first_multiplier > 0));
    return true;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input-file>" << endl;
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        cerr << "Couldn't open file" << endl;
        return 2;
    }
    int T = 0;
    if (!fscanf(fp, "%d", &T))
        cerr << "File not valid" << endl;

    for (int case_no = 0; case_no < T; ++case_no) {
        T_INT A, B, counter = 0;
        fscanf(fp, "%llu %llu", &A, &B);
        T_INT sqroot = sqrtl((long double) A) - 1;
        do {
            T_INT candidate = sqroot * sqroot;
            if ((candidate >= A) && (candidate <= B)) {
                if (is_fair(sqroot) && is_fair(candidate)) {
                    ++counter;
                }
            }
            ++sqroot;
        } while (sqroot * sqroot <= B);

        printf("Case #%d: %llu\n", case_no + 1, counter);
    }

    return 0;
}
