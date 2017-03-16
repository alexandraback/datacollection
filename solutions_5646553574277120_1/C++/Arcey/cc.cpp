#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    ifstream fi("c.in");
    ofstream fo("c.out");

    int totaltest;
    fi >> totaltest;
    for (int test = 1; test <= totaltest; test++) {
        int C, D, V;
        fi >> C >> D >> V;
        long long nr[105];
        for (int i = 0; i < D; i++)
            fi >> nr[i];
        long long s = 0;
        long long ans = 0;
        int poz = 0;
        while (s < V && poz < D) {
            while (s < nr[poz] - 1) {
                s += C * (s + 1);
                ans++;
            }
            s += C * nr[poz];
            poz++;
        }
        while (s < V) {
            s += C * (s + 1);
            ans++;
        }
        fo << "Case #" << test << ": " << ans << endl;
    }
    return 0;
}
