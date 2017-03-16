#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long ul;

int main() {
    int T;
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        int A, N;
        
        cin >> A >> N;
        
        vector<int> motes(N);
        for(int n = 0; n < N; n++) {
            int k;
            cin >> k;
            motes[n] = k;
        }
        sort(motes.begin(), motes.end());
        
        ul cur_size = A;
        int cur_index = 0;
        int cur_moves = 0;
        int min_moves = motes.size();
        
        if(cur_size == 1) {
            cout << "Case #" << t << ": " << min_moves << endl;
            continue;
        }
        
        for(int i = 0; i < motes.size(); i++) {
            //cout << "mote = " << motes[i] << endl;       
            //cout << "cur min = " << min_moves << endl;
            //cout << "option2 = " << (cur_moves + (int)motes.size() - i) << endl;
            if(cur_size > motes[i]) {
                cur_size += motes[i];
            }
            else {
                while(cur_size <= motes[i]) {
                    cur_size += cur_size - 1;
                    cur_moves++;
                }
                cur_size += motes[i];
                //int moves = max(1, (int)ceil(log(((double)(motes[i]-1))/(cur_size-1))/log(2.0)));
                //cur_size = (1<<moves) * cur_size - (1<<moves) + 1;
                //cur_moves += moves;
            }
            
            min_moves = min(min_moves, cur_moves + (int)motes.size() - i - 1);
        }
        
        cout << "Case #" << t << ": " << min_moves << endl;
    }
}
