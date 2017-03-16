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
        set<int> reverse_nodes;
        int nb_reverse_pairs = 0;
        for(int i = 0; i < N; ++i){
            if(best_friends[best_friends[i]] == i){
                ++nb_reverse_pairs;
                reverse_nodes.insert(i);
            }
        }
        map<int, int> longest_path_ending_at;
        int best_length = nb_reverse_pairs;
        for(int i = 0; i < N; ++i){
            if(reverse_nodes.count(i))
                continue;
            int current = best_friends[i];
            for(int j = 0; j < N; ++j){
                if(current == i){
                    best_length = max(best_length, j+1);
                    break;
                }
                if(reverse_nodes.count(current)){
                    best_length = max(best_length, j+1+nb_reverse_pairs);
                    longest_path_ending_at[current] = max(longest_path_ending_at[current], j+1);
                    break;
                } 
                current = best_friends[current];
            }
        }
        int reverse_path_length = 0;
        for(map<int, int>::iterator it = longest_path_ending_at.begin(); it != longest_path_ending_at.end(); ++it){
            reverse_path_length += it->second;
        }
        best_length = max(reverse_path_length + nb_reverse_pairs, best_length);
        cout << "Case #" << current_case_nb << ": " << best_length << endl;
    }
    return 0;
}
