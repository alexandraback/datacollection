#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <unordered_set>
#include <sstream>

using namespace std;

string problem = "/Users/apierce/codejam16/codejam/qual/C-large";
FILE *infile;
FILE *outfile;

typedef long long lld;

#define NUM_PRIMES 100
#define MAX_LENGTH 32

// primes[i] is the i'th prime
int primes[NUM_PRIMES];

// place_value[i][j][k] is the value of i^j mod the k'th prime
int place_value[11][MAX_LENGTH][NUM_PRIMES];

// current_value[i][j] is the current value mod the j'th prime in base i
int current_value[11][NUM_PRIMES];

lld next_lld() {
    lld result = 0;
    fscanf(infile, "%lld", &result);
    return result;
}

int next_int() {
    int result = 0;
    fscanf(infile, "%d", &result);
    return result;
}

string next_string() {
    char result[1000];
    fscanf(infile, "%s", result);
    return string(result);
}

int stop_index;

void add_at_index(int index) {
    for (int base = 2; base <= 10; base++) {
        for (int prime_index = 0; prime_index < NUM_PRIMES; prime_index++) {
            current_value[base][prime_index] =
                    (current_value[base][prime_index] +
                    place_value[base][index][prime_index]) %
                    primes[prime_index];
        }
    }
}

void subtract_at_index(int index) {
    for (int base = 2; base <= 10; base++) {
        for (int prime_index = 0; prime_index < NUM_PRIMES; prime_index++) {
            current_value[base][prime_index] =
                    (current_value[base][prime_index] -
                     place_value[base][index][prime_index] +
                     primes[prime_index]) %
                    primes[prime_index];
        }
    }
}

int num_answers_left;

void check_answer(string answer) {
    vector<int> results(11, -1);
    for (int base = 2; base <= 10; base++) {
        int divisor = -1;
        for (int prime_index = 0; prime_index < NUM_PRIMES; prime_index++) {
            if (current_value[base][prime_index] == 0) {
                divisor = primes[prime_index];
                break;
            }
        }
        if (divisor == -1) {
            // Didn't find a divisor.
            return;
        }
        results[base] = divisor;
    }
    printf("%s", answer.c_str());
    fprintf(outfile, "%s", answer.c_str());
    for (int base = 2; base <= 10; base++) {
        printf(" %d", results[base]);
        fprintf(outfile, " %d", results[base]);
    }
    printf("\n");
    fprintf(outfile, "\n");
    num_answers_left--;
}

void try_next(int index, string answer) {
    if (num_answers_left == 0) {
        return;
    }
    if (index == stop_index) {
        check_answer("1" + answer);
        return;
    }

    try_next(index + 1, "0" + answer);
    if (num_answers_left == 0) {
        return;
    }
    add_at_index(index);
    try_next(index + 1, "1" + answer);
    subtract_at_index(index);
}

string handle_case() {
    int length = next_int();
    int num_results = next_int();
    num_answers_left = num_results;

    stop_index = length - 1;

    add_at_index(0);
    add_at_index(length - 1);

    try_next(1, "1");

    int result = 0;

    stringstream ss;
    ss << "\n" << result;
    return ss.str();
}

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void compute_primes() {
    int index = 0;
    for (int i = 2;; i++) {
        if (is_prime(i)) {
            primes[index] = i;
            index++;
            if (index == NUM_PRIMES) {
                return;
            }
        }
    }
}

void compute_place_value() {
    for (int base = 2; base <= 10; base++) {
        for (int index = 0; index < MAX_LENGTH; index++) {
            for (int prime_index = 0; prime_index < NUM_PRIMES; prime_index++) {
                if (index == 0) {
                    // base^0 = 0 for any base
                    place_value[base][index][prime_index] = 1;
                } else {
                    place_value[base][index][prime_index] =
                            base * place_value[base][index - 1][prime_index] %
                                    primes[prime_index];
                }
            }
        }
    }
}

void clear_current_value() {
    for (int i = 2; i <= 10; i++) {
        for (int j = 0; j < NUM_PRIMES; j++) {
            current_value[i][j] = 0;
        }
    }
}

int main() {
    compute_primes();
    compute_place_value();
    clear_current_value();

    string infilename = problem + ".in";
    string outfilename = problem + ".out";
    infile = fopen(infilename.c_str(), "r");
    outfile = fopen(outfilename.c_str(), "w");

    lld n_cases = next_lld();
    printf("Case #1:\n");
    fprintf(outfile, "Case #1:\n");
    handle_case();
    return 0;
}