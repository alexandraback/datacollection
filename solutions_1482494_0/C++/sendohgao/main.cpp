#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second > b.second;
    else return a.first > b.first;
}

int main()
{
    ifstream fin("B-small-attempt3.in");
    ofstream fout("output.txt");

    int t;
    fin >> t;

    for (int i = 0; i != t; ++i) {
        int n;
        fin >> n;
        vector<pair<int, int> > stars(n);
        int mask[n];

        for (int j = 0; j != n; ++j) {
            fin >> stars[j].first >> stars[j].second;
            mask[j] = 2;
        }

        sort(stars.begin(), stars.end(), compare);

        int result = 0;
        int star = 0;
        while (star != 2 * n) {
            bool flag = false;
            for (int j = 0; j != n; ++j) {
                if (stars[j].second <= star && (mask[j] == 2 || mask[j] == 1)) {
                    star += (mask[j] == 2) ? 2 : 1;
                    ++result;
                    mask[j] = 0;
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            for (int j = 0; j != n; ++j) {
                if (stars[j].first <= star && mask[j] == 2) {
                    mask[j] = 1;
                    star += 1;
                    ++result;
                    flag = true;
                    break;
                }
            }
            if (!flag) break;
        }

        if (star == 2 * n) {
            fout << "Case #" << (i + 1) << ": " << result << endl;
        }
        else {
            fout << "Case #" << (i + 1) << ": " << "Too Bad" << endl;
        }
    }

    fin.close();
    fout.close();
    return 0;
}
