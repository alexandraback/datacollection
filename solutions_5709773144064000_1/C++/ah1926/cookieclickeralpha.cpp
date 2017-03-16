#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int testCount;
    in >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        double C, F, X;
        in >> C >> F >> X;
        double minTime = X / 2.0, time = C / 2.0;
        for (int farms = 1; time < minTime; time += C / (2.0 + (farms++) * F))
            minTime = min(minTime, time + X / (2.0 + farms * F));
        out << "Case #" << t << ": " << fixed << setprecision(7) << minTime << "\n";
    }
    in.close();
    out.close();
    return 0;
}
