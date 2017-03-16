#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

int main(void)
{
    int T;
    cin >> T;

    for(int t = 0; t < T; ++t){
        int R, N, M, K;
        cin >> R >> N >> M >> K;

        vector<vector<int> > select;
        for(int i = 2; i <= M; ++i){
            vector<int> arr(1, i);
            select.push_back(arr);
        }
        
        for(int n = 1; n < N; ++n){
            vector<vector<int> > select_;
            for(int i = 2; i <= M; ++i){
                for(int j = 0; j < select.size(); ++j){
                    vector<int> arr = select[j];
                    arr.push_back(i);
                    select_.push_back(arr);
                }
            }
            select = select_;
        }


        vector< map< vector<int>, double > > prob_list(M * M * M + 1);
        
        for(int j = 0; j < select.size(); ++j){
            vector<int> arr = select[j];
            sort(arr.begin(), arr.end());

            // product, probability
            map<int, double> p;

            // initial
            p[1] = 0.5;
            p[arr[0]] = 0.5;

            for(int mem = 1; mem < arr.size(); ++mem){
                map<int, double> p_;
                int num = arr[mem];

                for(map<int, double>::iterator it = p.begin();
                    it != p.end();
                    ++it){

                    int product = it->first;
                    double prob = it->second;

                    p_[ product ] += prob / 2.0;
                    p_[ product * num ] += prob / 2.0;
                }
                p = p_;
            }

            // record
            for(map<int, double>::iterator it = p.begin();
                it != p.end();
                ++it){
                int product = it->first;
                double prob = it->second;

                //printf("product, prob = %d, %f\n", product, prob);

                prob_list[ product ][arr] += prob;
            }
        }

        


        cout << "Case #" << (t+1) << ":" << endl;
        for(int r = 0; r < R; ++r){
            // selected_cards, prob
            map< vector<int>, double > bin;
            int product;
            cin >> product;

            map< vector<int>, double > zzz = prob_list[ product ];
            for(map< vector<int>, double >::iterator it = zzz.begin();
                it != zzz.end();
                ++it){
                vector<int> arr = it->first;
                double prob = it->second;
                bin[ arr ] += prob;
            }

            // each R
            map<vector<int>, int> possible_arr;
            double best_prob = -0.1;
            vector<int> best_arr;

            for(map< vector<int>, double >::iterator it = bin.begin();
                it != bin.end();
                ++it){

                if (it == bin.begin()){
                    possible_arr[ it->first ] = 1;
                }
                else{
                    if (possible_arr.count(it->first) == 0){
                        possible_arr.erase(it->first);
                    }
                }
            }

            if (possible_arr.size() == 1){
                best_arr = possible_arr.begin()->first;
            }
            else{
                for(map<vector<int>, int>::iterator it =  possible_arr.begin();
                    it != possible_arr.end();
                    ++it){
                    if (possible_arr.count( it->first )){

                        if (it->second > best_prob){
                            best_prob = it->second;
                            best_arr = it->first;
                        }
                    }
                }
            }

            for(int i = 0; i < best_arr.size(); ++i){
                cout << best_arr[i];
            }
            cout << endl;
        }
        


    }

    return 0;
}
