#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve(int N, vector<int> adj) {

    vector<int> dists(N);
    fill(dists.begin(), dists.end(), -1);
    
    int best = 0;
    
    for (int start = 0; start < N; start++) {
        vector<bool> marked(N);

        int d = 0;
        int pos = start;
        while (true) {
            
            // already visited
            if (dists[pos] > -1 && d <= dists[pos]) {
                break;
            }
            
            // self-intersect
            if (marked[pos]) {
                // bona fide loop
                int val = d - dists[pos];
                if (val > best) best = val;
                //cerr << start << ' ' << pos << ' ' << d << ' ' << val << endl;
                break;
            }
            
            marked[pos] = true;
            dists[pos] = d++;
            
            // bff pair
            if (adj[adj[pos]] == pos) {
                break;
            }

            pos = adj[pos];
        }
    }
    
    
    //for (int i = 0; i < N; i++) {
    //    cerr << ' ' << i << ":" << dists[i];
    //}
    //cerr << endl;
    

    int nice = 0;
    vector<bool> usedNice(N);
    for (int i = 0; i < N; i++) {
        if (adj[adj[i]] == i && !usedNice[i]) {
            usedNice[i] = true;
            usedNice[adj[i]] = true;
            int val = dists[i] + dists[adj[i]] + 2;
            nice += val;
        }
    }
    
    //cerr << "nice is " << nice << endl;
    if (nice > best) best = nice;
    
    return best;
}
        
        

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            arr[i]--;
        }
        
        int res = solve(N, arr);
        cout << "Case #" << t << ": " << res << endl;
    }
}