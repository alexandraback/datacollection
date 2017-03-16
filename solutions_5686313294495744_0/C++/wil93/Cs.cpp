#include <bits/stdc++.h>

int main() {
    int T;
    std::cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        std::cin >> N;

        std::vector<std::string> a(N), b(N);

        for (int i = 0; i < N; i++) {
            std::cin >> a[i] >> b[i];
        }

        int best = 0;
        for (int i = 0; i < (1 << N); i++) {
            std::set<std::string> realA, realB;
            std::vector<std::string> fakeA, fakeB;

            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    fakeA.push_back(a[j]);
                    fakeB.push_back(b[j]);
                } else {
                    realA.insert(a[j]);
                    realB.insert(b[j]);
                }
            }

            bool ok = true;
            for (unsigned j = 0; j < fakeA.size(); j++) {
                if (!realA.count(fakeA[j]) || !realB.count(fakeB[j])) {
                    ok = false;
                }
            }

            if (ok) {
                best = std::max(best, int(fakeA.size()));
            }
        }

        std::cout << "Case #" << t << ": " << best << std::endl;
    }
}
