#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;
struct cho
{
    int x, y, z;
    cho(int x, int y, int z): x(x), y(y), z(z) {}
    cho() {}
};
int main()
{
    int T; cin >> T;
    for (int TT = 1; TT <= T; ++TT)
    {
        int Jacket, Pants, Shirt, K;
        cin >> Jacket >> Pants >> Shirt >> K;
        vector<cho>vec;
        for (int i = 1; i <= Jacket; i++)
        {
            for (int j = 1; j <= Pants; j++)
            {
                for (int k = 1; k <= Shirt; k++)
                {
                    vec.push_back(cho(i, j, k));
                }
            }
        }
        int ansMax = 0;
        int ans = -1;
        for (int i = 1; i < (1 << (vec.size())); ++i)
        {
            map<pair<int , int> , int >maps[3];
            int cur = i;
            vector<cho> tVec;
            int ptr = 0;
            while(cur)
            {
                if (cur & 1)tVec.push_back(vec[ptr]);
                cur >>= 1;
                ptr++;
            }
            int flag = 1;
            for (int j = 0; j < tVec.size(); j++)
            {
                int tmp1 = ++maps[0][make_pair(tVec[j].x,tVec[j].y)];
                int tmp2 = ++maps[1][make_pair(tVec[j].x,tVec[j].z)];
                int tmp3 = ++maps[2][make_pair(tVec[j].y,tVec[j].z)];
                if(tmp1 > K || tmp2 > K || tmp3 > K)
                {
                    flag = 0;
                }
            }
            if(flag)
            {
                if(tVec.size() > ansMax)
                {
                    ansMax = tVec.size();
                    ans = i;
                }
            }
        }
        printf("Case #%d: %d\n", TT, ansMax);
        int ptr = 0;
        vector<cho> tVec;
        while(ans)
        {
            if (ans & 1)tVec.push_back(vec[ptr]);
            ans >>= 1;
            ptr++;
        }
        for(int i = 0; i < tVec.size(); ++i)
        {
            printf("%d %d %d\n",tVec[i].x,tVec[i].y,tVec[i].z);
        }
    }
    return 0;
}