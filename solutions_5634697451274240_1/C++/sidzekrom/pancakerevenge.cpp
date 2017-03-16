#include <bits/stdc++.h>
using namespace std;

int main_help(int casenum) {
    string pansage;
    cin >> pansage;
    int countparts = 1;
    char firstalph = pansage[0];
    for (int i = 1; i < pansage.size(); i++) {
        if (pansage[i] != pansage[i-1]) countparts++;
    }
    if (firstalph == '+') countparts -= (countparts % 2);
    if (firstalph == '-') countparts -= !(countparts % 2);
    cout << "Case #" << casenum+1 << ": " << countparts << endl;
    return 0;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        main_help(i);
    }
    return 0;
}
