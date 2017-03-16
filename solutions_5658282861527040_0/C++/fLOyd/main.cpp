//
//  main.cpp
//  B
//
//  Created by fLOyd on 5/3/14.
//  Copyright (c) 2014 fLOyd. All rights reserved.
//

#include <iostream>

int T, A, B, K;
int ans = 0;

void solve() {
    ans = 0;
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < B; ++j) {
            if ((i & j) < K) {
                ans++;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        std::cin >> A >> B >> K;
        solve();
        std::cout << "Case #" << t + 1 << ": " << ans << std::endl;
    }
    return 0;
}
