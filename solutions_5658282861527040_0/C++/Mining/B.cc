#include <iostream>
#include <cstdio>

unsigned solve_ways_to_win(int a, int b, int k)
{
    int count = 0;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++) 
            if ((i&j) < k) count++;
    return count;
}

int main()
{
    int cases;
    std::cin >> cases;
    for (int i = 1; i <= cases; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        printf("Case #%d: %u\n", i, solve_ways_to_win(a,b,c));
    }
}