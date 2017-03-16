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
        long nr[105];
        for (int i = 0; i < D; i++)
            fi >> nr[i];
        long s = 0;
        long ans = 0;
        int poz = 0;
        while (s < V && poz < D) {
            while (s < nr[poz] - 1) {
                s += s + 1;
                ans++;
            }
            s += nr[poz];
            poz++;
        }
        while (s < V) {
            s += s + 1;
            ans++;
        }
        fo << "Case #" << test << ": " << ans << endl;
    }
    return 0;
}
