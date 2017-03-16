#include <iostream>
#include <climits>
#include <string>

using namespace std;

int solver(string N)
{
    int ret = 0;

    for (int i = 1; i < N.size(); i++) {
        if (N.at(i-1) != N.at(i)) ret++;
    }
    if (N.at(N.size()-1) == '-') ret++;

    return ret;
}


int main()
{
    int T;
    string N;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << "Case #" << (i + 1) << ": " << solver(N) << endl;
    }

    return 0;
}