#include <iostream>
#include <string>
#include <array>
#include <cstring>
#include <queue>

using namespace std;

int dives(int i, int j) {
    return (i + j - 1) / j;
}

int p[1005];
int divs[1005];
priority_queue<pair<int, int> > maxs;
int main() {
    int tmax, d;
    cin >> tmax;
    for (int t = 1; t <= tmax; t++) {
        cin >> d;
        int max = 0;
        for (int i = 0; i < d; i++) {
            cin >> p[i];
            if (p[i] > max) {
                max = p[i];
            }
        }
        int min = 9999;
        for (int i = 0; i < max; i++) {
            maxs = priority_queue<pair<int, int> >();
            for (int j = 0; j < d; j++) {
                divs[j] = 1;
                maxs.push(make_pair(p[j], j));
            }
            for (int k = 1; k <= i; k++) {
                pair<int, int> top = maxs.top();
                maxs.pop();
                int index = top.second;
                divs[index]++;
                maxs.push(make_pair(dives(p[index], divs[index]), index));
            }

            if (maxs.top().first + i < min) {
                min = maxs.top().first + i;
            }
        }
        cout << "Case #" << t << ": " << min << endl;
    }
}