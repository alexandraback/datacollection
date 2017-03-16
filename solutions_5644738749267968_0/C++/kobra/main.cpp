#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <memory.h>

using namespace std;

int main()
{
    freopen("D-small-attempt0.in", "r", stdin);
    //freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    int T;
    cin >> T;
    for (int z = 0; z < T; z++) {
        vector<double> pl1;
        vector<double> pl2;
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            double num;
            cin >> num;
            pl1.push_back(num);
        }
        for (int i = 0; i < N; i++) {
            double num;
            cin >> num;
            pl2.push_back(num);
        }
        sort(pl1.begin(), pl1.end());
        sort(pl2.begin(), pl2.end());
        vector<double> pl2Copy = pl2;
        int res1 = 0;
        for(int i = 0; i < N; i++)
        {
            bool existBigger = false;
            for(int j = 0; j < pl2.size(); j++)
                if(pl2[j] > pl1[i]) {
                    pl2.erase(pl2.begin() + j);
                    existBigger = true;
                    break;
                }
            if (!existBigger) {
                pl2.erase(pl2.begin());
                res1++;
            }
        }
        int res2 = 0;
        for(int i = 0; i < N; i++) {
            bool existBigger = false;
            for(int j = 0; j < pl1.size(); j++)
                if(pl2Copy[i] < pl1[j]) {
                    pl1.erase(pl1.begin() + j);
                    existBigger = true;
                    res2++;
                    break;
                }
        }

        printf("Case #%d: ", z + 1);
        printf("%d %d", res2, res1);
        printf("\n");
    }
    return 0;
}

