#include<iostream>
using namespace std;


int A, B, K;

void read() {
    cin >> A >> B >> K;
}


void work(int cases) {
    int cnt = 0;
    for (int i = 0; i < A; ++i)
        for (int j = 0; j < B; ++j)
            cnt += ((i & j) < K);

    cout << "Case #" << cases << ": " << cnt << endl;
}


int main() {
    int cases;
    cin >> cases;
    
    for (int i = 0; i < cases; ++i) {
        read();
        work(i + 1);
    }
    return 0;
}
