#include <iostream>
#include <vector>
#include <utility>

using namespace std;
vector<pair<pair<int, int>, int> > data;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        data.clear();

        for (int j = 0; j < m; ++j) {
            int a, b;
            cin >> a >> b;
            data.push_back(make_pair(make_pair(b, a), 2));
        }

        sort(data.begin(), data.end());

        int curr = 0;
        int played = 0;
        bool updated = false;
        while (data.size() > 0) {
            updated = false;

            for (int j = 0; j < data.size(); ++j) {
                if (curr >= data[j].first.first && data[j].second > 0) {
                    curr += data[j].second; 
                    //cout << "updated for free at " << data[j].second << " with " << data[j].first.second << ' ' << data[j].first.first << endl;
                    data[j].second = 0;
                    played += 1;
                    updated = true;
                }

                if (data[j].first.first > curr) break;
            }

            bool done = true;
            for (int j = 0; j < data.size(); ++j) 
                if (data[j].second != 0) {
                    done = false;
                    break;
                }
            if (done) 
                break;

            int currmin = -1;
            for (int j = 0; j < data.size(); ++j) {
                if (data[j].second == 2 && data[j].first.second <= curr) {
                    currmin = max(currmin, data[j].first.first); 
                }
            }

            if (currmin > -1) {
                int ind = -1;
                for (int j = 0; j < data.size(); ++j) 
                    if (data[j].second == 2 && data[j].first.second <= curr && data[j].first.first == currmin) {
                        ind = j;
                        break;
                    }

                //cout << "forced update" << " with " << data[ind].first.second << ' ' << data[ind].first.first << endl;
                data[ind].second = 1;
                played += 1;
                curr += 1;
                updated = true;
            } 

            if (!updated) {
                break;                 
            }
        }

        if (!updated) {
            cout << "Case #" << i+1 << ": Too Bad" << endl;
        }
        else {
            cout << "Case #" << i+1 << ": " << played << endl;
        }
    }

    return 0;
}

