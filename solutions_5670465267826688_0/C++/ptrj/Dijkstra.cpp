//==============================================================================
// Qualification Round 2015
// Problem C. Dijkstra
//
//==============================================================================

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

using sol_type = bool;

void read_data();
sol_type find_solution();

long long L, X;
vector<int> S;
int get(const vector<int> & vi, const int x, const int y);

constexpr array<array<int,8>,8> mult = {
    array<int,8> {0,1,2,3,4,5,6,7},         // 1,i,j,k,-1,-i,-j,-k
    array<int,8> {1,4,3,6,5,0,7,2},
    array<int,8> {2,7,4,1,6,3,0,5},
    array<int,8> {3,2,5,4,7,6,1,0},
    array<int,8> {4,5,6,7,0,1,2,3},
    array<int,8> {5,0,7,2,1,4,3,6},
    array<int,8> {6,3,0,5,2,7,4,1},
    array<int,8> {7,6,1,0,3,2,5,4},
};

int main() {

    int cases;
    int case_num =0;

    cin >> cases;

    while (cases--) {
        ++case_num;
        read_data();
        auto solution = find_solution();
        cout << "Case #" << case_num << ": ";
        cout << (solution ? "YES" : "NO") << endl;
    }
    return 0;
}

void read_data(){
    cin >> L >> X;
    string t;
    cin >> t;
    S.resize(L);
    transform(t.begin(), t.end(), S.begin(), [](const char c){return c-'i'+1;});
}

sol_type find_solution(){
    long long ipos = -1, kpos = -1;

    int c = 0;
    for(auto i=0ll; i <= min(4ll,X)*L; ++i) {
        c = mult[c][S[i%L]];
        if(c == 1) {        // i found
            ipos = i;
            break;
        }
    }
    if(ipos == -1)
        return false;

    c = 0;
    for(auto i=0ll; i <= min(4ll,X)*L; ++i) {
        c = mult[S[L-1-i%L]][c];
        if(c == 3) {        // k found
            kpos = X*L -1 - i;
            break;
        }
    }
    if(kpos == -1 || kpos <= ipos + 1)
        return false;

    c = 0;
    if(ipos%L < L-1)
        c = get(S, ipos%L+1, min(kpos,L));
    if(kpos/L > ipos/L +1) {
        auto full = get(S,0,L);
        for(int i=0; i< (kpos/L-ipos/L-1)%4; ++i)
            c = mult[c][full];
    }
    if(kpos >= L)
        c = mult[c][get(S,0,kpos%L)];

    if(c == 2)              // j
        return true;

    return false;
}

int get(const vector<int> & vi, const int x, const int y) {
    return accumulate(vi.begin()+x, vi.begin()+y, 0, [](const int a, const int b){return mult[a][b];});
}
