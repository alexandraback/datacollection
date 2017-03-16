#include <stdlib.h>
#include <stdio.h>

#define MAX_NUMS 100

#define MAX_SQUARE 100000000000000

#define TRUE  1
#define FALSE 0

typedef unsigned long long ull;

int n_cases;
int is_palindrome(ull num);

int find_equal_or_higher(int start, int end, ull val);

ull fair_squares[MAX_NUMS];
int square_upto = 0;

int main(int argc, char* argv[]) {
    FILE* fin = fopen(argv[1], "r");
    fscanf(fin, "%d", &n_cases);
    ull i;
    
    for (i = 1; i*i <= MAX_SQUARE; i++) {
        if (is_palindrome(i) && is_palindrome(i*i)) {
            fair_squares[square_upto++] = i*i;
        }
    }

    int test;
    for (test = 1; test <= n_cases; test++) {
        ull a,b;
        fscanf(fin, "%llu %llu", &a, &b);
        int num_fair_and_square = find_equal_or_higher(0, square_upto-1, b+1) -
            find_equal_or_higher(0, square_upto-1, a);
        printf("Case #%d: %d\n", test, num_fair_and_square);
    }
    
    return 0;
}

int find_equal_or_higher(int start, int end, ull val) {
    int best_so_far = end+1;
    while (start <= end) {
        int mid = (start + end)/2;
        if (fair_squares[mid] >= val) {
            best_so_far = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return best_so_far;
}

char buffer[50];
int is_palindrome(ull num) {
    int num_chars = 0;
    while (num > 0) {
        buffer[num_chars] = num%10;
        num /= 10;
        num_chars++;
    }
    
    int i;
    int palindrome = TRUE;
    for (i = 0; i < num_chars/2; i++) {
        if (buffer[i] != buffer[num_chars-i-1]) {
            palindrome = FALSE;
            break;
        }
    }
    return palindrome;
}
