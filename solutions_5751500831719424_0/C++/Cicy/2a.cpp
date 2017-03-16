#include "2a.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        
        int N;
        cin >> N;
        vector< vector<int> > num_list (N);
        string compact;
        
        bool quit = false;
        
        for (int j=0; j<N; j++) {
            string s;
            cin >> s;
            string t;
            
            auto itr_1 = s.begin(), itr_2 = s.begin();
            while (itr_2 != s.end()) {
                if (*itr_2 == *itr_1) {
                    itr_2++;
                } else {
                    int count = (int)distance(itr_1, itr_2);
                    num_list[j].push_back(count);
                    t += *itr_1;
                    itr_1 = itr_2;
                }
            }
            if (itr_2 != itr_1) {
                int count = (int)distance(itr_1, itr_2);
                num_list[j].push_back(count);
                t += *itr_1;
            }
            
            if (j == 0) {
                compact = t;
            } else {
                if (compact != t) {
                    cout << "Case #" << i+1 << ": Fegla Won"<< endl;
                    quit = true;
                    break;
                }
            }
        }
        
        if (!quit) {

        int total_move = 0, size = (int)num_list[0].size();
        for (int m = 0; m < size; m++) {
            vector<int> tmp;
            for (int n = 0; n< N ; n++){
                tmp.push_back(num_list[n][m]);
            }
            sort(tmp.begin(), tmp.end());
            int target = tmp[tmp.size()/2];
            for (int n = 0; n< N ; n++){
                total_move += abs(tmp[n] - target);
            }
            
        }
        cout << "Case #" << i+1 << ": "<< total_move << endl;
        }

    }
    
    
}