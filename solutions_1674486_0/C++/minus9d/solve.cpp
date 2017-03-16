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

int main(void)
{
    int T;
    cin >> T;

    for(int t = 0; t < T; ++t){
        int N;
        cin >> N;
        vector< map<int, int> > fromTo(N+1);
        vector< map<int, int> > toFrom(N+1);
        bool flag = false;
        for(int from = 1; from < N+1; ++from){
            int num;
            cin >> num;
            for(int i = 0; i < num; ++i){
                int to;
                cin >> to;
                //cout << "  from, to = " << from << ", " << to << endl;
                fromTo[from][to]++;
                toFrom[to][from]++;
                // if (fromTo[from][to] > 1){
                //     flag = true;
                // }

                //printf(" sizes = %d, %d\n", toFrom[from].size(), fromTo[to].size());
                for(map<int, int>::iterator it = toFrom[from].begin();
                    it != toFrom[from].end();
                    ++it){

                    for(map<int, int>::iterator it2 = fromTo[to].begin();
                        it2 != fromTo[to].end();
                        ++it2){
                        //printf("  %d to %d is also ok\n", it->first, it2->first);
                    
                        fromTo[it->first][it2->first]++;
                        toFrom[it2->first][it->first]++;
                        // if (fromTo[it->first][it2->first] > 1){
                        //     flag = true;
                        // }
                    }
                    
                }

                for(map<int, int>::iterator it = toFrom[from].begin();
                    it != toFrom[from].end();
                    ++it){
                    fromTo[it->first][to]++;
                    toFrom[to][it->first]++;
                }
                for(map<int, int>::iterator it2 = fromTo[to].begin();
                    it2 != fromTo[to].end();
                    ++it2){
                    fromTo[from][it2->first]++;
                    toFrom[it2->first][from]++;
                }
            }
        }

        for(int n = 1; n < N+1; ++n){
             for(map<int, int>::iterator it = fromTo[n].begin();
                 it != fromTo[n].end();
                 ++it){
                 if (it->second > 1){
                     flag = true;
                 }
             }
        }


        // // for debug
        // for(int n = 1; n < N+1; ++n){
        //     cout << "from " << n << ": " << endl;
        //      for(map<int, int>::iterator it = fromTo[n].begin();
        //          it != fromTo[n].end();
        //          ++it){
        //          cout << "  to: " << it->first << " , times : " << it->second << endl;
        //      }
        // }
        // // for debug
        //  for(int n = 1; n < N+1; ++n){
        //      cout << "to " << n << ": " << endl;
        //      for(map<int, int>::iterator it = toFrom[n].begin();
        //          it != toFrom[n].end();
        //          ++it){
        //          cout << "  from: " << it->first << " , times : " << it->second << endl;
        //      }
        // }
            
        if (flag){
            cout << "Case #" << (t+1) << ": " << "Yes" << endl;
        }
        else{
            cout << "Case #" << (t+1) << ": " << "No" << endl;
        }
    }

    return 0;
}
