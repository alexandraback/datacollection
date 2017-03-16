#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
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
        vector<int> nums;
        for(int n = 0; n < N; ++n){
            int tmp;
            cin >> tmp;
            nums.push_back(tmp);
        }

        map<long long, vector<unsigned int> > maps;
        for(unsigned int i = 0; i < (1 << N); ++i){
            long long tmp = 0;
            unsigned int j = i;
            int counter = 0;
            while(j){
                if (j & 0x1){
                    tmp += nums[counter];
                }
                j >>= 1;
                ++counter;
            }
            maps[ tmp ].push_back( i );
            //printf("0x%x: %lld\n", i, tmp);
        }

        cout << "Case #" << (t+1) << ": " << endl;
        bool isFound = false;
        for (map<long long, vector<unsigned int> >::iterator it = maps.begin();
             it != maps.end();
             ++it){
            vector<unsigned int> vec = it->second;
            if (vec.size() > 1 && !isFound){
                for(int i = 0; i < vec.size() - 1; ++i){
                        if (isFound){
                            break;
                        }
                        
                        for (int j = i + 1; j < vec.size(); ++j){
                                if (isFound){
                                    break;
                                }

                                if ((vec[i] & vec[j]) == 0){
                                    unsigned int k = vec[i];
                                    int counter = 0;
                                    while(k){
                                        if (k & 0x1){
                                            cout << nums[counter] << " ";
                                        }
                                        k >>= 1;
                                        ++counter;
                                    }
                                    cout << endl;

                                    k = vec[j];
                                    counter = 0;
                                    while(k){
                                        if (k & 0x1){
                                            cout << nums[counter] << " ";
                                        }
                                        k >>= 1;
                                        ++counter;
                                    }
                                    cout << endl;

                                    isFound = true;
                                    break;
                                }
                            }
                                 }
                    }
                        }

                if (!isFound){
                    cout << "Impossible" << endl;
                }
            }

            

    return 0;
}
