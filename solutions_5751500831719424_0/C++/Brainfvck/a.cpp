#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

int main()
{
    string s[100];
    int t;
    cin >> t;
    for (int ii = 0 ; ii < t; ii++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> s[i];
        int cc[100][100] = {0}, num[100][100] = {0},index[100] = {0};
        for (int i = 0; i < n; i++)
        {
            cc[i][index[i]++] = s[i][0];
            for (int j = 0; j < s[i].length(); j++)
            {
                if (s[i][j] == cc[i][index[i] - 1]) num[i][index[i] - 1] ++;
                else
                {
                    cc[i][index[i]++] = s[i][j];
                    num[i][index[i] - 1]++;
                }
            }
        }

        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (index[i] != index[0])
            {
                flag = 1;
                break;
            }
            for(int j = 0; j < index[i]; j++)
                if (cc[i][j] != cc[0][j])
                {
                    flag = 1;
                    break;
                }
            if (flag == 1) break;
        }
        if (flag == 1)
        {
            cout << "Case #" << ii + 1 << ": " << "Fegla Won" << endl;
            continue;
        }
        int ans = 0,min;
        for (int i = 0; i < index[0]; i++)
        {
            min = 100000;
            for (int j = 1; j <= 100; j++)
            {
                int dis = 0;
                for (int k = 0; k < n; k++)
                    dis += abs(num[k][i] - j);
                min = min > dis ? dis : min;
            }
            ans += min;
        }
        cout << "Case #" << ii + 1 << ": " << ans << endl;
    }
    return 0;

}
