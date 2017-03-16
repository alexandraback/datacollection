#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main()
{
    ios::sync_with_stdio(false);

    ifstream fin ("standova.in");
    ofstream fout ("standova.out");

    int t;
    fin >> t;

    int smax;
    string shy;
    int runclap = 0;
    int add = 0;
    for (int test = 0; test < t; test++) {
        fin >> smax;
        fin >> shy;

        runclap = 0;
        add = 0;
        for (int k = 0; k <= smax; k++) {
            if (int(shy[k])-48 == 0) {
                continue;
            }

            if (runclap >= k) {
                runclap += int(shy[k])-48;
            } else {
                add += (k-runclap);
                runclap += (k-runclap) + int(shy[k])-48;
            }
        }


        fout << "Case #" << (test+1) << ": " << add << "\n";
    }

    return 0;
}
