#include <iostream>
#include <cstdio>
#include <queue>

int min(int a, int b)
{
    return a < b ? a : b;
}

int min_time(std::priority_queue<int> q)
{
    int result = q.top();
    
    if (result != 1) {
        std::priority_queue<int> k(q), l(q);

        k.pop(); k.push(result / 2); k.push(result - (result / 2));
        int split_half = 1 + min_time(k);

        if (result >= 9) {
            l.pop(); l.push(result / 3); l.push(result - (result / 3));
            result = min(result, 1 + min_time(l));
        }

        result = min(result, split_half);
    }

    return result;
}

int main()
{
    int T; std::cin >> T;

    for (int test = 0; test < T; test++) {
        std::priority_queue<int> q;
        int D; std::cin >> D;

        for (int i = 0; i < D; i++) {
            int P; std::cin >> P;
            q.push(P);
        }

        std::cout << "Case #" << test + 1 << ": " << min_time(q) << std::endl;
    }

    return 0;
}