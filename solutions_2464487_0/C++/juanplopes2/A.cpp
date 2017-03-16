#include <iostream>
#include <cmath>
#define PI 3.14159265359
#define ull unsigned long long
using namespace std;

int main() {
    int cc=0, cases; 
    cin >> cases;
    while(cc++ < cases) {
        double r, t;
        cin >> r >> t;

        r = 2*r+1;
        double answer = 0.25 * (sqrt(r*r-4*r+8*t+4) - r + 2);
        
        cout << "Case #" << cc << ": " << (ull)floor(answer) << endl;
    }
}
