#include <fstream>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

long double p1[100000], p[100000], p2[100000];
int t, a, b;

void solve(int c) {
    for (int i = 0; i < 100000; ++i) p[i] = p1[i] = p2[i] = 0;
    cin >> a >> b;
    for (int i = 0; i < a; ++i) {
        cin >> p[i];
        if (i == 0) p2[i] = p[i];
        else p2[i] = p2[i-1] * p[i];
        /*if (i == 0) p1[i] = 1 - p[i];
        else p1[i] = (1 - p[i])*p2[i-1];*/
        if (i == 0) p1[i] = 1;
        else p1[i] = p2[i-1];
    }
    long double best = min((long double)(b+2), 2*b-a+2-p2[a-1]*(b+1));
    for (int k = 1; k < a; ++k)
        best = min(best, 2*k+2*b-a+2-p1[a-k]*(b+1));
    cout.precision(15);
    cout << "Case #" << c << ": " << fixed << best << endl;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; ++i) solve(i+1);

    return 0;
}
