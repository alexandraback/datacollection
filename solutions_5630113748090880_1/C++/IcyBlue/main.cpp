#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int time_limits;
    cin >> time_limits;
    for (int time_count = 0; time_count < time_limits; time_count++)
    {
        printf("Case #%d: ",time_count+1);
        int n;
        cin >> n;
        int count[2501];
        memset(count,0,sizeof(count));
        for (int i = 0; i < 2*n-1; i++){
            for (int j = 0; j < n; j++) {
                int temp;
                cin >> temp;
                count[temp]++;
            }
        }
        vector<int> ans;
        for (int i = 1; i <= 2500; i++)
        {
            if (count[i] % 2 != 0)
            {
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << ' ';
        }
        printf("\n");
    }

}