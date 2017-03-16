#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

bool all_seen(vector<bool> &a) {
    return all_of(a.begin(), a.end(), [](bool b){return b;});
}

int main() {
    ifstream fin("A-small-attempt0.in");
    ofstream fout("a-small.out");

    int T;
    fin >> T;
    //cin >> T;

    for (int i=1; i<=T; i++) {
        vector<bool> digits(10, false);
        int N, counter;
        fin >> N;
        //cin >> N;
        counter = 0;

        if (N == 0) {
            fout << "Case #" << i << ": INSOMNIA\n";
            //cout << "Case #" << i << ": INSOMNIA\n";
            continue;
        }

        while (!all_seen(digits)) {
            counter += N;
            stringstream ss;
            ss << counter;

            string num = ss.str();
            for (string::iterator it=num.begin(); it<num.end(); it++) {
                digits[(*it)-'0'] = true;
            }
        }

        fout << "Case #" << i << ": " << counter << "\n";
        //cout << "Case #" << i << ": " << counter << "\n";
    }

    return 0;
}
