#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int lawn[100][100];
int row_max[100], col_max[100];
int N,M;

string isValidPattern() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (lawn[i][j] < min(row_max[i], col_max[j])) {
                return "NO";
            }
        }
    }
    return "YES";
}

void testcase(int _t)
{
    cin >> N;
    cin >> M;
    
    for (int i=0; i<N; i++) for (int j=0; j<M; j++) { cin >> lawn[i][j]; }

    for (int i=0; i<N; i++) {
        int v = 0;
        for (int j=0; j<M; j++) { v = max(v, lawn[i][j]); }
        row_max[i] = v;
    }
    
    for (int j=0; j<M; j++) {
        int v = 0;
        for (int i=0; i<N; i++) { v = max(v, lawn[i][j]); }
        col_max[j] = v;
    }

    cout << "Case #" << _t << ": ";
    cout << isValidPattern();
    cout << endl;
}

int main(int argc, char** argv) {
    int T;
    cin >> T;

    for (int t=1; t<=T; t++) {
        testcase(t);
    } 
}
