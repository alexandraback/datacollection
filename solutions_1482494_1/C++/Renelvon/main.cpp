#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<unsigned int> sol;
    unsigned int T, N, total, curstars, maxb;
    int next;
    bool flag;

    int a[1000], b[1000];
    unsigned int visited[1000];
    cin >> T;

    for (unsigned int i = 1; i < T + 1; ++i) {
        cin >> N;
        for (unsigned int j = 0; j < N; ++j) {
            cin >> a[j] >> b[j]; 
        }
        fill(visited, visited + N, 0);
        
        curstars = total = 0;

        do {
            next = -1;
            flag = false;
            for (unsigned int j = 0; j < N; ++j) {
                if (visited[j] == 0 && b[j] <= curstars) {
                    next = j;
                    flag = true;
                    curstars += 2;
                    visited[j] = 2;
                    ++total;
                    //cout << "curstars: " << curstars << ", b[j]: " << b[j] << endl;
                    //cout << "up 2:" << next << endl;
                    break;
                }
            }

            if (next == -1) {
                for (unsigned int j = 0; j < N; ++j) {
                    if (visited[j] == 1 && b[j] <= curstars) { 
                        next = j;
                        flag = true;
                        ++curstars;
                        visited[j] = 2;
                        ++total;
                        //cout << "curstars: " << curstars << ", b[j]: " << b[j] << endl;
                        //cout << "up rest:" << next << endl;
                        break;
                    }
                }
            }

            if (next == -1) {
                maxb = 0;
                for (unsigned int j = 0; j < N; ++j) {
                    if (visited[j] == 0 && a[j] <= curstars && b[j] >= maxb) { 
                        next = j;
                        maxb = b[j];
                    }
                }
                if (next != -1) {
                    flag = true;
                    ++curstars;
                    visited[next] = 1;
                    ++total;
                    //cout << "curstars: " << curstars << ", a[j]: " << a[next] << endl;
                    //cout << "up 1:" << next << endl;
                }
            }
        } while (flag);
        
        if (curstars < N * 2) {
            cout << "Case #" << i << ": Too Bad" << endl;
        } else {
            cout << "Case #" << i << ": " << total << endl;
        }
    }
}
