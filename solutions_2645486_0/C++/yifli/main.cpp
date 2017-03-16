#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> value;

int E, R, N;

void solve(vector<int>& results, int energy, int v, int n) {

    if( n == N ) {
        results.push_back(energy*value[n]+v);
        return;
    }

    for(int i = 0; i <= energy; i++)
        solve(results, min(energy-i+R, E), v+i*value[n], n+1);

}

int main(int argc, char *argv[])
{
    ifstream input("B-small-attempt0.in");
    cin.rdbuf(input.rdbuf());

    ofstream output("B-small-attempt0.out");
    cout.rdbuf(output.rdbuf());

    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        cout << "Case #" << i+1 << ": ";

        cin >> E >> R >> N;

        value.clear();
        value.push_back(0);

        int v;
        for(int j = 0; j < N; j++) {
            cin >> v;
            value.push_back(v);
        }

        vector<int> results;
        solve(results, E, 0, 1);
        cout << *(max_element(results.begin(), results.end())) << endl;
    }

}
