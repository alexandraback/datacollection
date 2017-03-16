#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for ( int t = 0; t < T; t++ ) {
        int A, B;
        cin >> A >> B;
        vector<double> p(A), pos(A+1,1.0), x(A+1,0);
        for ( int i = 0; i < A; i++ ) {
            cin >> p[i];
            pos[i+1] = pos[i] * p[i];
        }

        for ( int i = 0; i < pos.size(); i++ ) {
            x[i] = pos[i] * ( B + (A-i)*2 + 1 - A );
            x[i] += (1.0-pos[i]) * ( 2*B + (A-i)*2 + 2 - A );
        }
        x.push_back(B+2);
        printf( "Case #%d: %.10f\n", t+1, *min_element(x.begin(),x.end()) );
    }
    return 0;
}
