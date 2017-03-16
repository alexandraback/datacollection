/*
* @Author: Comzyh
* @Date:   2016-04-16 09:20:42
* @Last Modified by:   Comzyh
* @Last Modified time: 2016-04-16 09:27:29
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int T, N;
int num[2501];
int main()
{
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++)
    {
        scanf("%d", &N);
        memset(num, 0, sizeof(num));
        for (int i = 1; i < 2 * N; i++)
            for (int j = 0; j < N; j++)
            {
                int x;
                scanf("%d", &x);
                num[x] ++;
            }
        vector<int> ans;
        for (int i = 1; i <= 2500; i++)
            if (num[i] & 1)
                ans.push_back(i);
        sort(ans.begin(), ans.end());
        printf("Case #%d:", TT);
        for (size_t i = 0; i < ans.size(); i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}