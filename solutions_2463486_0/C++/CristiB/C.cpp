#include <iostream>
#include <set>
#include <utility>

using namespace std;

typedef pair<int, int> pi;
set<pi> sol;

int MASK, MASK_MSD;

void init(int a) {
    MASK = 1;
    for (; a; a /= 10) {
        MASK_MSD = MASK;
        MASK *= 10;
    }

    sol.clear();
}

int rotate(int a) {
    int msd = a / MASK_MSD;
    return (a * 10 + msd) % MASK;
}

int solveCase(int A, int B) {
    init(A);

    for (int a = A; a < B; ++a) {
        int rot = a;
        do
        {
            rot = rotate(rot);
            if (rot > a && rot <= B)
                sol.insert(make_pair(a, rot));
        } while (rot != a);
    }

    return sol.size();
}

int main() {
    //int a = 12345;
    //init(a);
    //for (int i = 0; i < 5; i++) {
        //cout << "Rot: " << (a = rotate(a)) << endl;
    //}
    
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int A, B;
        cin >> A >> B;
        cout << "Case #" << t << ": " <<  solveCase(A, B) << endl;
    }
    
    return 0;
}

