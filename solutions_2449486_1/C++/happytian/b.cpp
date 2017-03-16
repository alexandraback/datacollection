#include<iostream>
using namespace std;

int data[110][110];

//bool is_possible(int n, int m) {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (data[i][j] == 1) {
//                int ok = 1;
//                for (int k = 0; k < n; k++) 
//                    if (data[k][j] != 1) {
//                        --ok;
//                        break;
//                    }
//                for (int k = 0; k < m; k++) 
//                    if (data[i][k] != 1) {
//                        --ok;
//                        break;
//                    }
//                if (ok < 0)
//                    return false;
//            }
//        }
//    }
//    return true;
//}

bool is_possible_large(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int current = data[i][j];
            int ok = 1;
            for (int k = 0; k < n; k++) {
                if (data[k][j] > current) {
                    --ok;
                    break;
                }
            }
            if (ok == 1)
                continue;
            for (int k = 0; k < m; k++) {
                if (data[i][k] > current) {
                    --ok;
                    break;
                }
            }
            if (ok < 0)
                return false;
        }
    }
    return true;
}

int main() {
    int T, n, m;
    cin >> T;
    for (int k = 1; k <= T; k++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> data[i][j];
        if(is_possible_large(n, m))
            cout << "Case #" << k << ": " << "YES" << endl;
        else
            cout << "Case #" << k << ": " << "NO" << endl;
    }
}
