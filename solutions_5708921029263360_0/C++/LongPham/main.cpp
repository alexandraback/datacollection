#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <set>
#include <numeric>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)

int main() {
    std::ifstream in{ "small-practice.in" };
    std::ofstream out{ "small.out" };

    int T;
    in >> T;
    int t{ 1 };

    while (t <= T) {
        int J, P, S, K;
        in >> J >> P >> S >> K;

        int num = 0;


        unordered_map<string, int>PS{};
        unordered_map<string, int>JS{};
        unordered_map<string, int>JPS{};
        vector<string>outsuits{};

        for1(j,J) {
            for1(p, P) {
                for1(k, S) {
                    for1(s, S) {
                        if (JPS[to_string(j) + to_string(p) + to_string(s)] >= 1 || JS[to_string(j) + to_string(s)] >= K || PS[to_string(p) + to_string(s)] >= K) {
                            continue;
                        } else {
                            outsuits.emplace_back(to_string(j) + to_string(p) + to_string(s));
                            JS[to_string(j) + to_string(s)]++;
                            PS[to_string(p) + to_string(s)]++;
                            JPS[to_string(j) + to_string(p) + to_string(s)]++;
                            num++;
                            break;
                        }
                    }
                }
            }
        }

        out << "Case #" << t << ": " << num << std::endl;
        for (auto& outsuit : outsuits) {
            out << outsuit << endl;
        }

        t++;
    }

    return 0;
}