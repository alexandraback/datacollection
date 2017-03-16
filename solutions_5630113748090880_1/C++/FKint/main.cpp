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
        map<int, int> nb_count;
        for(int i = 0; i < 2*N-1; ++i){
            for(int j = 0; j < N; ++j){
                int k;
                cin >> k;
                nb_count[k]++;
            }
        }
        cout << "Case #" << current_case_nb << ":";
        for(map<int, int>::iterator it = nb_count.begin(); it != nb_count.end(); ++it){
            if(it->second%2 == 1){
                cout << " " << it->first;
            }
        }
        cout << endl;
    }

    return 0;
}
