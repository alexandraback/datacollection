#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

bool cansolve(const vector<int> &vals, int test, int splitMax) {
    int splits = 0;
    vector<int> vals2;
    for (int val : vals) {
        for (int split = 1; split <= val; split++, splits++) {
            int t = val / split + !!(val%split);
            if (t <= test - splitMax) {
                vals2.push_back(t);
                //splits += split - 1;
                goto next;
            }
            if (splits > splitMax)
                return false;
        }
        next:;
    }
    if (splits > splitMax)
        return false;
    int M = 0;
    for (int val : vals2)
        if (val > M)
            M = val;
    return M + splits <= test;;
}
bool cansolve2(const vector<int> &vals, int test) {
    int low = 0;
    //for (int val : vals)
    //    low += val / test;
    for (int i = low; i <= test; i++) {
        if (cansolve(vals, test, i))
            return true;
    }
    return false;
}
void solve(istream &in, ostream &out, int caseNum) {
    int d;
    in >> d;
    vector<int> vals(d);
    for (int i = 0; i < d; i++) {
        in >> vals[i];
    }

    int m = 0;
    int M = 1111;

    while (m < M) {
        int mid = (m + M) / 2;
        if (cansolve2(vals, mid))
            M = mid;
        else
            m = mid + 1;
    }

    out << "Case #" << caseNum << ": " << m << endl;
    cout << caseNum << endl;
}


int main(int argc, char **args) {
    ios_base::sync_with_stdio(0);
    if (argc != 3) {
        cout << "Usage: InfiniteHouseOfPancakes file.in file.out" << endl;
        return 0;
    }
    ifstream fin(args[1]);
    ofstream fout(args[2]);

    int t;
    fin >> t;
    for (int i = 0; i < t; i++)
        solve(fin, fout, i + 1);

    fout.close();
    fin.close();
}