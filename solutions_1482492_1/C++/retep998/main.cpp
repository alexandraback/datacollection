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
    out.precision(16);
    int T;
    in >> T;
    for (int Case = 1; Case <= T; ++Case) {
        double D;
        in >> D;
        int N;
        in >> N;
        int A;
        in >> A;
        vector<double> T;
        vector<double> X;
        for (int i = 0; i < N; ++i) {
            double t;
            in >> t;
            T.push_back(t);
            double x;
            in >> x;
            X.push_back(x);
        }
        out << "Case #" << Case << ":" << endl;
        for (int i = 0; i < A; ++i) {
            double a;
            in >> a;
            double v = 0;
            double x = 0;
            bool done = false;
            for (int j = 1; j < N && !done; ++j) {
                double t1 = T[j]-T[j-1];
                double dx = X[j]-X[j-1];
                double ov = dx/t1;
                double ox = X[j-1];
                double t2 = (sqrt(v*v-2*ov*v-2*a*x+2*a*ox+ov*ov)-v+ov)/a;
                double t3 = (sqrt(v*v-2*a*(x-D))-v)/a;
                double t4 = (D-X[j-1])/ov;
                double t5 = (sqrt(v*v+2*dx)-v)/a;
                if (t3 <= t1 && t3 <= t2) {//Hit target first
                    out << t3+T[j-1] << endl;
                    done = true;
                } else if (t1 < t2) {//Just keep driving
                    x += 0.5*a*t1*t1+v*t1;
                    v += a*t1;
                } else if (t1 < t3) {//t2 < t1 < t3
                    v = t5*a+v;
                    x = X[j];
                } else if (X[j] >= D) {//t2 < t3 < t1
                    out << t4+T[j-1] << endl;
                    done = true;
                } else {//t2 < t3 < t1
                    v = t5*a+v;
                    x = X[j];
                }
            }
            if (!done) {
                double t = (sqrt(v*v-2*a*(x-D))-v)/a;
                out << T[N-1]+t << endl;
            }
        }
        
    }
    high_resolution_clock::time_point end = clock.now();
    cout << "Time taken: " << duration_cast<milliseconds>(end-start).count() << " ms" << endl;
}