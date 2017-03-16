#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int case_num, i(0), r, l, j, k;
    cin >> case_num;
    int map[101][101];
    while (i++ < case_num)
    {
        cin >> r >> l;
        memset(map, 0, sizeof(map));
        for (j = 1; j <= r; j++)
        {
            for (k = 1; k <= l; k++)
            {
                cin >> map[j][k];
                if (map[j][k] > map[0][k]) map[0][k] = map[j][k];
                if (map[j][k] > map[j][0]) map[j][0] = map[j][k];
            }
        }
        cout << "Case #" << i << ": ";
        bool flag = true;
        for (j = 1; j <= r & flag; j++)
        {
            for (k = 1; k <= l & flag; k++)
            {
                if (map[j][k] != map[j][0] && map[j][k] != map [0][k])
                {
                    flag = false;
                }
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
