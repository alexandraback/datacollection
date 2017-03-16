#include <iostream>

using namespace std;

int main() {

    int T, r, t;
    int paint=0;
    int count=0;

    std::cin >> T;

    for(int z=1; z<=T; z++) {
        cin >> r >> t;
        //cout << "Input: " << r << " " << t << endl;

        count=0;
        paint=0;
        while(paint <= t) {
            paint += ((r+1)*(r+1) - r*r);
            count++;
            r+=2;
            //cout << "paint: " << paint << " count: " << count << endl;
        }

        cout << "Case #" << z << ": ";
        cout << count-1 << endl;
    }

    return 1;
}
