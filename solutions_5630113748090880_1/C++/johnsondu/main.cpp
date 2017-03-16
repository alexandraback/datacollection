#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

const int N = 55;

struct Node {
    int a[N];
};
Node node[2*N];

int n;

int main()
{

    freopen("B-large.in", "r", stdin);
    freopen("outBL.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++ i) {
        cin >> n;
        int num;
        unordered_map<int, int> umap;
        for(int j = 0; j < 2*n-1; ++ j)
            for(int k = 0; k < n; ++ k)
            {
                cin >> num;
                umap[num] ++;
            }
        unordered_map<int, int>::iterator itr;
        vector<int> ans;
        for(itr = umap.begin(); itr != umap.end(); ++ itr) {
            if(itr->second & 1) ans.push_back(itr->first);
        }
        sort(ans.begin(), ans.end());
        cout << "Case #" << i << ": " << ans[0];
        for(int j = 1; j < ans.size(); ++ j)
            cout << " " << ans[j];
        cout << endl;

    }
    return 0;
}
