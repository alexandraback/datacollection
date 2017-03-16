#include <bits/stdc++.h>

int main() {
    int T;
    std::cin >> T;

    for (int t = 1; t <= T; t++) {
        int best = std::numeric_limits<int>::max();
        std::string best_C = "9999";
        std::string best_J = "9999";

        std::string C, J;
        std::cin >> C >> J;

        for (int i0=0; i0<10; i0++)
            for (int i1=0; i1<10; i1++)
                for (int i2=0; i2<10; i2++)
                    for (int i3=0; i3<10; i3++)
                        for (int i4=0; i4<10; i4++)
                            for (int i5=0; i5<10; i5++) {
                                std::string CC = C, JJ = J;
                                if (CC[0] == '?') CC[0] = '0' + i0;
                                if (CC[1] == '?') CC[1] = '0' + i1;
                                if (CC[2] == '?') CC[2] = '0' + i2;
                                if (JJ[0] == '?') JJ[0] = '0' + i3;
                                if (JJ[1] == '?') JJ[1] = '0' + i4;
                                if (JJ[2] == '?') JJ[2] = '0' + i5;

                                int diff = std::abs(std::stoi(CC) - std::stoi(JJ));

                                if (diff < best || ((diff == best) && (best_C > CC)) || ((diff == best) && (best_C == CC) && (best_J > JJ))) {
                                    best = diff;
                                    best_C = CC;
                                    best_J = JJ;
                                }
                            }

        std::cout << "Case #" << t << ": " << best_C << " " << best_J << std::endl;
    }
}
