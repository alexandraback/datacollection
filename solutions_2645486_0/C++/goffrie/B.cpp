#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& s, const vector<int>& v) {
    s << '{';
    for (int i = 0 ;i <  v.size(); ++i) {
        s << (i ? "," : "") << v[i];
    }
    return s << '}';
}

int main() {
    int T;
    cin >> T;
    for (int Case = 1; Case <= T; ++Case) {
        int E, R, N;
        cin >> E >> R >> N;
        vector<pair<int,int>> values;
        for (int i = 0; i < N; ++i) {
            int val;
            cin >> val;
            values.push_back(make_pair(val, i));
        }
        vector<int> expenditure(N, 0);
        vector<int> maxE(N, E);
        vector<int> energyBefore(N, E);
        vector<int> minEB(N, 0);
        sort(values.begin(),values.end(),greater<pair<int,int>>());
        int total = 0;
        for (auto p : values) {
            int i = p.second, val = p.first;
            expenditure[i] = maxE[i];
            if (i == N-1) minEB[i] = expenditure[i];
            else minEB[i] = expenditure[i] + max(minEB[i+1] - R, 0);
            assert(minEB[i] >= 0);
            total += expenditure[i] * val;
            cerr << "spending " << expenditure[i] << " on #" << i << " (" << val << ")" << endl;
            for (int j = i; j--; ) {
                // energyBefore[j]  + R = minEB[j+1] + maxE
                maxE[j] = min(maxE[j], energyBefore[j] - minEB[j+1] + R);
                assert(maxE[j] >= 0);
                minEB[j] = max(minEB[j], minEB[j+1] - R + expenditure[j]);
                assert(energyBefore[j] <= E);
                assert(minEB[j] <= energyBefore[j]);
            }
            int energyTotal = min(energyBefore[i] - expenditure[i] + R, E);
            for (int j = i+1; j < N; ++j) {
                energyBefore[j] = energyTotal;
                maxE[j] = min(energyBefore[j] - minEB[j] + expenditure[j], maxE[j]);
                assert(expenditure[j] <= maxE[j]);
                assert(expenditure[j] <= energyBefore[j]);
                energyTotal -= expenditure[j];
                assert(energyTotal >= 0);
                energyTotal += R;
                energyTotal = min(energyTotal,E);
                assert(energyTotal >= 0);
            }
            cerr << expenditure << '\n' << maxE << '\n' << energyBefore << '\n' << minEB << endl;
        }
        cout << "Case #" << Case << ": " << total << endl;
    }
}
