
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int current_case_nb = 1; current_case_nb <= T; ++current_case_nb){
        int N;
        cin >> N;
        vector<int> best_friends;
        for(int i = 0; i < N; ++i){
            int x;
            cin >> x;
            x--;
            best_friends.push_back(x);
        }
        int best_length = 0;
        for(int i = 1; i < (1<<N); ++i){
            vector<int> nums;
            for(int x = 0; x < N; ++x){
                if(i & (1<<x))
                    nums.push_back(x);
            }
            do{
                bool good = true;
                for(int k = 0; k < nums.size(); ++k){
                    int left = (k+nums.size() - 1) % nums.size();
                    int right = (k+1) % nums.size();
                    if(best_friends[nums[k]] != nums[left] && best_friends[nums[k]] != nums[right]){
                        good = false;
                        break;
                    }
                }
                if(good)
                    best_length = max(best_length, (int)nums.size());
            }while(next_permutation(nums.begin(), nums.end()));
        }
        cout << "Case #" << current_case_nb << ": " << best_length << endl;
    }
    return 0;
}
