#include <iostream>
#include <cmath>
#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n;
map < string , vector < string > > M1 , M2;
map < pair < string , string > , int > taken;
string A[1050] , B[1050];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);


    freopen("C-small-attempt2.in" , "r" , stdin);
    freopen("out.out" , "w" , stdout);

    int T , cc = 0;
    cin >> T;
    while(T--)
    {
        ++cc;
        set < string > left , right;
        cin >> n;

        for(int i = 0;i < n;++i)
        {
            cin >> A[i] >> B[i];
            left.insert(A[i]);
            right.insert(B[i]);

            M1[A[i]].push_back(B[i]);
            M2[B[i]].push_back(A[i]);
        }
        int leftCnt = left.size();
        int rightCnt = right.size();
        left.clear();
        right.clear();

        int cnt = 1;
        while(left.size() < leftCnt or right.size() < rightCnt)
        {
            for(auto it = M1.begin();it != M1.end();++it)
            {
                int sz = 50000;
                int idx = -1;
                for(int i = 0;i < (int)(it -> second).size();++i)
                {
                    if((it -> second).size() <= cnt and taken.find({it->first , (it -> second)[i]}) == taken.end())
                    {
                        if(M2[(it -> second)[i]].size() < sz)
                        {
                            idx = i;
                            sz = M2[(it -> second)[i]].size();
                        }
                    }
                }
                if(idx != -1)
                {
                    left.insert(it->first);
                    right.insert((it -> second)[idx]);
                    taken[{it->first , (it -> second)[idx]}] = 1;
                }
            }
            cnt = cnt  % rightCnt + 1;
        }

        int ans = 0;
        for(int i = 0;i < n;++i)
            if(taken.find({A[i] , B[i]}) == taken.end())
                ++ans;


        cout << "Case #" << cc << ": " << ans << "\n";
        M1.clear();
        M2.clear();
        left.clear();
        right.clear();
        taken.clear();

        cerr << "done  ->  " << cc << "\n";
    }
    return 0;
}
