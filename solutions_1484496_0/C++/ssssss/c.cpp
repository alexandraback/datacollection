#include <iostream>
#include <vector>
using namespace std;

int subset(vector<int>S, int a) {
    int r = 0;
    for (size_t i=0; i < S.size(); ++i) {
        if (a & (1 << i)) r+= S[i];
    }
    return r;
}

void print(vector<int> S, int a) {
    bool first = true;
    for (size_t i=0; i < S.size(); ++i) {
        if (a & (1 << i)){
            if (!first) {
                cout << " ";
            }
            cout << S[i];
            first = false;
        }
    }
    cout << endl;
}


void test() {
    int N;
    cin >> N;
    vector<int> S;
    S.reserve(N);
    for(int j=0; j < N; ++j) {
        int s;
        cin >> s;
        S.push_back(s);
    }
    for(int a=1; a < (1<<N); ++a) {
        for(int b=1; b < (1<<N); ++b) {
            if (a&b) continue;
            if (subset(S,a) == subset(S,b)) {
                print(S,a);
                print(S,b);
                return;
            }
        }
    }
    cout << "Impossible" <<endl;
}

int main() {
    int T;
    cin >> T;
    for (int i=1; i<=T; ++i) {
        cout << "Case #" << i<< ":" << endl;
        test();
    }
}

