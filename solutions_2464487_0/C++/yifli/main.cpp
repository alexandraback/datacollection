#include <fstream>
#include <iostream>

using namespace std;


void solve(long r, long t) {
    r++;
    int counter = 0;

    while( t - (2*r-1) >= 0 ) {
        counter++;
        t = t - (2*r-1);
        r = r+2;
    }

    cout << counter << endl;
}

int main(int argc, char *argv[])
{
    ifstream input("A-small-attempt0.in");
    cin.rdbuf(input.rdbuf());

    ofstream output("A-small-attempt0.out");
    cout.rdbuf(output.rdbuf());

    int T;
    cin >> T;

    long r, t;
    for(int i = 0; i < T; i++) {
        cout << "Case #" << i+1 << ": ";

        cin >> r >> t;

        solve(r, t);
    }

}
