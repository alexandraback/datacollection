#include <iostream>
#include <cmath>

using namespace std;

int T, A, N;
int motes[100];
int number_operation;

int osmos(int start, int A);

int main() {
    cin >> T;

    for (int t=1 ; t<=T ; ++t) {
        cin >> A >> N;

        for (int n=0 ; n<N ; ++n)
            cin >> motes[n];

        if (A == 1) {
            cout << "Case #" << t << ": " << N << endl;
            continue;
        }

        sort(motes, motes+N);

        number_operation = osmos(0, A);

        cout << "Case #" << t << ": " << number_operation << endl;
    }

    return 0;
}

int osmos(int start, int A) {
    if (start == N)
        return 0;

    if (motes[start] < A)
        return osmos(start+1, A+motes[start]);
    else {
        int up_A = A;
        int operation = 0;

        while (up_A <= motes[start]) {
            up_A += up_A-1;
            operation++;
        }

        return min(operation + osmos(start+1, up_A+motes[start]), 1 + osmos(start+1, A));
    }
}
