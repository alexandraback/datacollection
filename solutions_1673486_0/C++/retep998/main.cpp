#include <fstream>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <filesystem>
#include <thread>
#include <random>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
using namespace std::tr2::sys;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int T;
    in >> T;
    for (int n = 1; n <= T; ++n) {
        int A;
        in >> A;
        int B;
        in >> B;
        vector<double> p;
        for (int i = 0; i < A; ++i) {
            double pr;
            in >> pr;
            p.push_back(pr);
        }
        double best = 0;
        auto check = [&](double v) {
            if (!best || v < best) best = v;
        };
        check(B+2);
        double prob = 1;
        for (int i = 1; i <= A; ++i) {
            prob *= p[i-1];
            double res = prob*(B+A-2*i+1) + (1-prob)*(2*B+A-2*i+2);
            check(res);
        }
        out << "Case #" << n << ": " << fixed << setprecision(10) << best << endl;
    }
}