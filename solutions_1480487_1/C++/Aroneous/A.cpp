#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

void doCase(int caseNum) {
    int N;
    cin >> N;

    vector<int> s;

    int total = 0;
    for (int i = 0; i < N; i++) {
        int si;
        cin >> si;
        s.push_back(si);
        total += si;
    }

    cout << "Case #" << caseNum << ":";
    // Need 1/N of 2*total
    double avg = ((double)(total * 2))/((double)N);
    int numbelowavg = 0;
    int totalbelowavg = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] < avg) {
            numbelowavg++;
            totalbelowavg += s[i];
        }
    }

    double per = ((double)(totalbelowavg + total))/((double)numbelowavg);
    for (int i = 0; i < N; i++) {
        const int& a = s[i];

        double missing = per - a;
        double mp = missing/((double)total);
        double ans = max(mp*100, 0.0);
        cout << " " << setprecision (9) << ans;
//        printf(" %f", mp*100);
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        doCase(i+1);
    }
}
