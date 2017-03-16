#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vv;
int main()
{
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _ ++)
    {
        int c, d, v;
        cin >> c >> d >> v;
        vv.clear();
        for (int i = 0; i < d; i ++) {
            int x;
            cin >> x;
            vv.push_back(x);
        }
        sort(vv.begin(), vv.end());
        int ans = 0;
        if (vv[0] != 1) {
            vv.push_back(1);
            ans ++;
        }
        sort(vv.begin(), vv.end());
        int t = 1, now = 1;
        while (now < v)
        {
            if (t < vv.size() &&
                    vv[t] > now + 1){
                now = 2 * now + 1;
                ans ++;
            } else if (t >= vv.size()){
                vv.push_back(now + 1);
                now = 2 * now + 1;
                t ++;ans ++;
            } else if(t < vv.size() &&
                    vv[t] <= now + 1)
            {
                now += vv[t];
                t ++;
            }
        }
        printf("Case #%d: %d\n",_,ans);
    }
    return 0;
}