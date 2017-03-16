#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <assert.h>
#include <algorithm>

using namespace std;

int J , P , S , K;

int main()
{
    freopen("C-small-attempt5.in" , "r" , stdin);
    freopen("out.out" , "w" , stdout);

    int T , cc = 0;
    scanf("%d" , &T);
    while(T--)
    {
        ++cc;
        scanf("%d%d%d%d" , &J , &P , &S , &K);

//        vector < vector < int > > ans;
//        for(int i = 1;i <= J;++i)
//            for(int j = 1;j <= P;++j)
//                for(int k = 1;k <= S;++k)
//                {
//                    vector < int > A({i , j , k});
//                    ans.push_back(A);
//                }

//        vector < vector < int > > finalAns;
//        for(int i = 0;i < (1 << ans.size());++i)
//        {
//            vector < vector < int > > temp;
//            map < pair < int , int > , int > JP , JS , PS;
//
//            for(int j = 0;j < (int)ans.size();++j)
//            {
//                if(i & (1 << j))
//                {
//                    JP[{ans[j][0] , ans[j][1]}]++;
//                    JS[{ans[j][0] , ans[j][2]}]++;
//                    PS[{ans[j][1] , ans[j][2]}]++;
//                    temp.push_back(ans[j]);
//                }
//            }
//
//        bool done = true;
//        for(auto x = JP.begin();x != JP.end();++x)
//            if(x -> second > K)
//            {
//                done = false;
//                break;
//            }
//
//
//
//        for(auto x = JS.begin();x != JS.end();++x)
//            if(x -> second > K)
//            {
//                done = false;
//                break;
//            }
//
//        for(auto x = PS.begin();x != PS.end();++x)
//            if(x -> second > K)
//            {
//                done = false;
//                break;
//            }
//
//        if(done and temp.size() < finalAns.size())
//            finalAns = temp;
//      }

        vector < vector < int > > ans;
        map < pair < int , int > , int > JP , JS , PS;

        int cnt = 1;
        for(int i = 1;i <= J;++i)
            for(int j = 1;j <= P;++j)
            {
                for(int k = 0;k < min(S , K);++k)
                {
                    vector < int > A({i , j , cnt});

                    if(JP[{i , j}] < K and JS[{i , cnt}] < K and PS[{j , cnt}] < K)
                    {
                        JP[{i , j}]++;
                        JS[{i , cnt}]++;
                        PS[{j , cnt}]++;
                        ans.push_back(A);
                        cnt = cnt % S + 1;
                    }
                }
            }

        cerr << min(J * P * K , J * P * S) - ans.size() << " << ";

        printf("Case #%d: %d\n" , cc , ans.size());
        for(int i = 0;i < (int)ans.size();++i)
        {
            if(i)   printf("\n");
            printf("%d %d %d" , ans[i][0] , ans[i][1] , ans[i][2]);
        }
        printf("\n");
//        assert(ans.size() == min(J * P * K , J * P * S) and "asdasdasd");

//        JS.clear();
//        PS.clear();
//        JP.clear();
        cerr << "done -> " << cc << "\n";
    }
    return 0;
}
