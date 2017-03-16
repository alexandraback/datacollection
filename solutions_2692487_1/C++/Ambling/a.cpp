#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int get(int sum, const std::vector<int> &motes, int index)
{
    if (index >= motes.size())
    {
        return 0;
    }
    if (sum > motes[index])
    {
        return get(sum + motes[index], motes, index+1);
    }

    int cnt = 0;
    while(sum <= motes[index]){
        // cout<<" "<<sum-1<<" ";
        sum = sum * 2 -1;
        cnt++;
    }
    cnt += get(sum + motes[index], motes, index+1);

    if (cnt > motes.size() - index)
    {
        return motes.size() - index;
    }
    return cnt;
}

int main()
{
    // freopen("a7.in", "r", stdin);
    // freopen("a7.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);

        int a, n;
        cin>>a>>n;
        vector<int> motes;
        for (int i = 0; i < n; ++i)
        {
            int m;
            cin>>m;
            motes.push_back(m);
        }

        sort(motes.begin(), motes.end());

        if (a == 1)
        {
            cout<<n;
        } else {

            cout<<get(a, motes, 0);
        }
        

        printf("\n");
    }
    
    return 0;
}
