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

int digit_count(T_INT num) {
    int res = 0;
    while (num) {
        ++res;
        num /= 10;
    }
    return res;
}

T_INT left_half(T_INT number, int digits) {
    digits /= 2;
    while (digits) {
        number /= 10;
        --digits;
    }
    return number;
}

T_INT mirror_number(T_INT left_half, int digits) {
//    printf("Mirror number: %llu %d\n", left_half, digits);
    T_INT multiplier = 1;
    if ((digits % 2) == 1) {
        multiplier *= 10;
    }
    T_INT res = left_half;
    do {
//        printf("Res before: %llu, left half: %llu, multiplier: %llu\n", res, left_half, multiplier);
        res = res * 10 + get_digit(left_half, multiplier);
        multiplier *= 10;
//        printf("Res after: %llu, left half: %llu, multiplier: %llu\n", res, left_half, multiplier);
    } while (multiplier <= left_half);
    return res;
}


// returns a number like 101 or 10000000000000001
T_INT ones_and_zeroes(int digits) {
    T_INT res = 1;
    --digits;
    while (digits) {
        res *= 10;
    }
    if (res % 10 == 0)
        ++res;
    return res;
}

T_INT find_next_fair(T_INT starting_point) {
    if (is_fair(starting_point))
        return starting_point;

    // step 1: determine left half
    int digits = digit_count(starting_point);
    T_INT lh = left_half(starting_point, digits);
    T_INT candidate = mirror_number(lh, digits);
    if (candidate >= starting_point)
        return candidate;

    int lh_digits = digit_count(lh);
    ++lh;
    if (digit_count(lh) > lh_digits) {
        return ones_and_zeroes(digits + 1);
    } else {
        return mirror_number(lh, digits);
    }
}

int main(int argc, char *argv[])
{

/*    T_INT fs = 1;
    for (int i = 0; i < 200; ++i) {
        printf("%llu\n", fs = find_next_fair(fs + 1));
    }*/
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
            sqroot = find_next_fair(sqroot + 1);
        } while (sqroot * sqroot <= B);

        printf("Case #%d: %llu\n", case_no + 1, counter);
    }

    return 0;
}
