#include<iostream>
#include<vector>

using namespace std;

int minCount(int n) {
    return 0;
}

int main() {
    int T = 0;
    cin >> T;
    for(int i=0; i<T; ++i) {
        int N = 0;
        cin >> N;
        int count = minCount(N);

        cout << "Case #" << i+1 << ": " << count << endl;
    }

    return 0;

}
