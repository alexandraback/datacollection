#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long A;

vector<long> MOTE;

void read_input()
{
    cin >> A >> N;
    MOTE.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> MOTE[i];
    }
}

int solve()
{
    if (A == 1) {
        return N; // mote is too small to consume any other
    }
    vector<long> penalty(1+N);
    for (int k = 0; k <= N; ++k) {
        penalty[k] = N-k;
    }

    sort(MOTE.begin(), MOTE.end());

    long s = A;
    long p = 0;
    for (int i = 0; i < N; ++i) {
        while (s <= MOTE[i]) {
            s+= (s-1);
            ++p;
        }
        s+= MOTE[i];
        penalty[1+i]+= p;
    }

    long answer = *min_element(penalty.begin(), penalty.end());
    return answer;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        read_input();
        long answer = solve();
        cout << "Case #" << t << ": " << answer << endl;
    }
}