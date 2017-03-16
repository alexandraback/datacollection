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

typedef struct { int star; int level; } data_t;

class comp{
public:
    bool operator()(const data_t& l, const data_t& r) const {
        return l.star < r.star;
    }
};

int main(void)
{
    int T;
    cin >> T;

    for(int t = 0; t < T; ++t){
        int N;
        cin >> N;
        vector<int> as(N);
        vector<int> bs(N);
        vector<data_t> aSort(N);
        vector<data_t> bSort(N);
        int ret = 0;
        for(int n = 0; n < N; ++n){
            int a, b;
            cin >> a >> b;
            as[n] = a;
            bs[n] = b;
            data_t aD, bD;
            aD.star = a;
            aD.level = n;
            bD.star = b;
            bD.level = n;
            aSort[n] = aD;
            bSort[n] = bD;
        }
        sort(aSort.begin(), aSort.end(), comp());
        sort(bSort.begin(), bSort.end(), comp());

//        cout << endl;
//        printf("star: \n");
//        for(int i = 0; i < as.size(); i++){
//            printf("level %d: %d, %d\n", i, as[i], bs[i]);
//        }
//        cout << endl;

//         for(int i = 0; i < aSort.size(); i++){
//             printf("%d: a star: %d, level: %d\n", i, aSort[i].star, aSort[i].level);
//         }
//         cout << endl;
//         for(int i = 0; i < aSort.size(); i++){
//             printf("%d: b star: %d, level: %d\n", i, bSort[i].star, bSort[i].level);
//         }
//         cout << endl;
        
        int aIdx = 0;
        int bIdx = 0;
        int star = 0;
        vector<int> aUsed(N, 0);
        vector<int> bUsed(N, 0);
        bool isFail = false;
        while(bIdx < bSort.size()){
            data_t b = bSort[bIdx];
//             printf("current star: %d\n", star);
//             printf("try b (level %d, star %d)\n", b.level, b.star);
             if (star >= b.star){
                if (aUsed[ b.level ]){
                    star++;
                }
                else{
                    star += 2;
                    aUsed[ b.level ] = 1;
                }
                bUsed[ b.level ] = 2;
                ++bIdx;
                ++ret;
            }
            else
            {
                bool isOk = false;
                for(int j = 0; j < aSort.size(); ++j){
                    data_t a = aSort[j];
                    if (star < a.star){
                        isFail = true;
                        break;
                    }

                    if (aUsed[ a.level ] || bUsed[ a.level ]){
                        continue;
                    }
                    else{
                        aUsed[ a.level ] = 2;
                        ++star;
                        ++ret;
                        isOk = true;
                    }
                }

                if (!isOk){
                    isFail = true;
                    break;
                }
            }
        }

//        printf("used: \n");
//        for(int i = 0; i < aUsed.size(); ++i)
//        {
//            printf("%d: %d %d\n", i, aUsed[i], bUsed[i]);
//        }

        if (isFail || bIdx != bSort.size()){
            cout << "Case #" << (t+1) << ": " << "Too Bad" << endl;
        }
        else{
            cout << "Case #" << (t+1) << ": " << ret << endl;
        }
    }

    return 0;
}
