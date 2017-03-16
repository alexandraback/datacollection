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
        vector<int> judges;
        int sum = 0;
        for(int n = 0; n < N; ++n){
            int s;
            cin >> s;
            judges.push_back(s);
            sum += s;
        }

        cout << "Case #" << (t+1) << ": ";

//        cout << " sum = " << sum << endl;
//        cout << " N = " << N << endl;

        vector<int> jdg_copy = judges;
        sort(jdg_copy.begin(), jdg_copy.end());

        int remain = sum;
        double neededMin = jdg_copy[0];
        while(1){
            if (jdg_copy[0] == jdg_copy[N-1]){
                neededMin += (double)remain / N;
                break;
            }
            else{
                int sameNum = 0;
                int diff = 0;
                for(int i = 0; i < N; ++i){
                    if (jdg_copy[0] == jdg_copy[i]){
                        ++sameNum;
                    }
                    else{
                        diff = jdg_copy[i] - jdg_copy[0];
                        break;
                    }
                }
                if (diff * sameNum >= remain){
                    neededMin += (double)remain / sameNum;
                    break;
                }
                else{
                    for(int j = 0; j < sameNum; ++j){
                        jdg_copy[j] = jdg_copy[sameNum];
                    }
                    neededMin = jdg_copy[sameNum];
                    remain -= sameNum * diff;
                }
            }
        }

        for(int n = 0; n < N; ++n){
            double val = (neededMin - judges[n]) / (double)sum;
            val *= 100.0;
            printf("%.6f", max(val, 0.0));
            if (n != N-1){
                printf(" ");
            }
        }
            
        cout << endl;
    }

    return 0;
}
