#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k)
    {
        int C, D, V;
        cin >> C >> D >> V; // C == 1

        int n = D;
        //cin >> n;

        vector<int> arr;
        int z;
        for (int i = 0; i < n; ++i)
        {
            cin >> z;
            arr.push_back(z);
        }
        int sum = 0;
        int i = 0;
        while(sum+1 <= V)
        {
            //cout << i << " ";
            if (i)
            {
                arr.push_back(sum+1);
                //cout << "sum+1";
            }
            sum = 0;
            sort( arr.begin(), arr.end() );

            for (size_t i = 0; i < arr.size() ; ++i)
                if (arr[i] <= sum + 1)
                    sum += arr[i];
                else
                    break;

            //cout << sum + 1 << " " << V << endl;
            ++i;
        }
       // cout << "Case #" << k << ": ";
       // for (int i = 0; i < arr.size(); ++i)
       //     cout << arr[i] << " ";
       // cout <<": " << arr.size()-n;
       // cout << endl;
        cout << "Case #" << k <<": " << arr.size()-n << endl;
    }
}
