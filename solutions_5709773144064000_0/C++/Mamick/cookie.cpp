#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

long double c, f, x;

long double nextFarm(long double fNum) {
    return c / (2 + (f * fNum)); 
}

long double countFinish(long double fNum) {
    return x / (2 + (f * fNum));
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c >> f >> x;
        long double cumulSize = 0;
        long double lowestFinish = 999999;
        long double fNum = 0;
        while (true) {
            long double finish = cumulSize + countFinish(fNum);
            if (finish < lowestFinish) lowestFinish = finish;
            long double nextCumul = cumulSize + nextFarm(fNum);
            // cout << finish << " " << nextCumul << endl;
            if (nextCumul > lowestFinish) {
                break;
            }
            cumulSize = nextCumul;
            fNum++;
        }
        cout << "Case #" << i << ": " << setprecision(15) << lowestFinish << endl;
    }
}