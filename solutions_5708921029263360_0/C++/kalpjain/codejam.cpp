#include <bits/stdc++.h>
using namespace std;

int main(void) {
    freopen("in.txt", "rt", stdin);
    freopen("test.txt", "wt", stdout);
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc)
    {
        int ja, pa, sh, ka;
        cin >> ja >> pa >> sh >> ka;
        int sp[20][20] = {0}, sj[20][20] = {0}, jp[20][20] = {0};
        vector <pair <pair <int,int>, int> > ans;
        for(int i = 1; i <= ja; ++i)
        {
            for(int j = i; j <= pa; ++j)
            {
                for(int k = j; k <= sh; ++k)
                {
                    if(sp[j][k] < ka && sj[k][i] < ka && jp[i][j] < ka)
                    {
                        ans.push_back(make_pair(make_pair(i, j), k));
                        sp[j][k]++;
                        sj[k][i]++;
                        jp[i][j]++;
                    }
                }
            }
        }
        cout << "Case #" << tc << ": ";
        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << "\n";
    }
    return 0;
}
