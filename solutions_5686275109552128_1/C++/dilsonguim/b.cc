#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minTime(const vector<int>& p){
    const int max_pi = *max_element(p.begin(), p.end());
    int min_time = max_pi;
    for(int p_time = 1; p_time < max_pi; p_time++){
        int s_time = 0;
        for(const auto& pi : p) s_time += (pi + p_time - 1) / p_time - 1;
        const int total_time = s_time + p_time;
        min_time = min(min_time, total_time);
    }
    return min_time;
}

int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int d;
        cin >> d;
        vector<int> p(d);
        for(auto& pi : p) cin >> pi;
        const int sol = minTime(p);
        cout << "Case #" << tc << ": " << sol << "\n";
    }
}
