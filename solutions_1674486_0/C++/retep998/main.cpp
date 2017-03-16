#include <iostream>
#include <thread>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>
#include <fstream>
#include <algorithm>
using namespace std;
using namespace chrono;

vector<int> C;
vector<vector<int>> I;

void Check(int n) {
    ++C[n];
    for (int v : I[n]) {
        Check(v);
    }
};

int main() {
    high_resolution_clock clock;
    high_resolution_clock::time_point start = clock.now();
    ifstream in("input.txt");
    ofstream out("output.txt");
    int T;
    in >> T;
    for (int Case = 1; Case <= T; ++Case) {
        cout << "Case " << Case << endl;
        int N;
        in >> N;
        I.clear();
        for (int i = 0; i < N; ++i) {
            int M;
            in >> M;
            I.emplace_back();
            for (int j = 0; j < M; ++j) {
                int v;
                in >> v;
                --v;
                I[i].push_back(v);
            }
        }
        cout << "Data read" << endl;
        bool D = false;
        C.clear();
        for (int i = 0; i < N; ++i) {
            C.emplace_back();
        }
        for (int i = 0; i < N; ++i) {
            fill(C.begin(), C.end(), 0);
            Check(i);
            if (count_if(C.begin(), C.end(), [](int c){return c > 1;})) {
                D = true;
            }
        }
        out << "Case #" << Case << ": " << (D?"Yes":"No") << endl;
    }

    high_resolution_clock::time_point end = clock.now();
    cout << "Time taken: " << duration_cast<milliseconds>(end-start).count() << " ms" << endl;
}