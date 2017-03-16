#include <iostream>
#include <vector>

using namespace std;

bool exhausts(int E, int R, const vector<int>& vals, vector<int>& spent) {
    int energy=E;
    for (size_t i=0; i<spent.size(); ++i) {
        energy -= spent[i];
        if (energy<0) return true;
        energy += R;
        if (energy>E) energy = E;
    }

    return false;
}

int score(int E, int R, const vector<int>& vals, vector<int> &spent) {
    int score=0;

    for (size_t i=0; i<vals.size(); ++i) {
        score += vals[i] * spent[i];
    }

    return score;
}

void R_mg(int E, int R, const vector<int>& vals, vector<int> &spent, int& gain, size_t ndx) {
    if (ndx > vals.size()) return;
    if (exhausts(E, R, vals, spent)) return;

    /*for (size_t i=0; i<spent.size(); i++) {
        cout << spent[i] << " ";
    }
    cout << endl;*/

    int c_score = score(E, R, vals, spent);
    if (c_score > gain) gain = c_score;

    for (int i=0; i<=E; ++i) {
        spent[ndx]+=i;
        R_mg(E, R, vals, spent, gain, ndx+1);
        spent[ndx]-=i;
    }
}

int mg(int E, int R, vector<int>& vals) {
    int gain=0;
    vector<int> spent(vals.size(), 0);
    R_mg(E, R, vals, spent, gain, 0);
    return gain;
}

int main()
{
    int T;

    cin >> T;

    for (int i=0; i<T; ++i) {
        int max_gain=0, E,//max/init energy
                      R,//amt regained after each
                      N;//num activities for day
        cin >> E >> R >> N;

        vector<int> values(N);
        for (int j=0; j<N; ++j) {
            cin >> values[j];
        }

        /*if (E == R) {
            for (int j=0; j<N; ++j) {
                max_gain += values[j] * R;
            }
        } else*/ max_gain = mg(E, R, values);

        cout << "Case #" << (i+1) << ": " << max_gain << endl;
    }

    return 0;
}
