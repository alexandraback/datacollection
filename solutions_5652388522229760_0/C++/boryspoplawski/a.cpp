#include <iostream>

bool seen[10];

int len(long long int x) {
    if (x == 0) {
        return 0;
    }
    return 1 + len(x / 10);
}

void see(long long int x) {
    if (x == 0) {
        return;
    }
    seen[x % 10] = true;
    see(x / 10);
}

void clean() {
    int i;
    for (i = 0; i < 10; ++i) {
        seen[i] = false;
    }
}

long long int sheep(long long int n) {
    long long int counter = 0;
    bool y;
    int i;
    
    while (true) {
        counter += n;
        see(counter);
        y = true;
        for (i = 0; i < 10; ++i) {
            if (!seen[i]) {
                y = false;
            }
        }
        if (y) {
            break;
        }
    }
    return counter;
}

int main() {
    int T, i;
    long long int N;
    
    std::cin >> T;
    for (i = 1; i <= T; ++i) {
        std::cin >> N;
        clean();
        std::cout << "Case #" << i << ": ";
        if (N == 0) {
            std::cout << "INSOMNIA";
        } else {
            std::cout << sheep(N);
        }
        std::cout << std::endl;
    }
    return 0;
}
