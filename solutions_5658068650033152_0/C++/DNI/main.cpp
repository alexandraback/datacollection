#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>


using namespace std;



int main()
{

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	

	int tt;
	cin >> tt;
	for(int t = 1; t <= tt; t++)
	{


        int n, m ,kk;
        cin >> n >> m >> kk;
        int minVal = kk;
        for (int j = 1; j <= m - 2; ++j)
        {
            for (int k = 1; k <= n - 2; ++k)
            {
                int temp = 2 * k + 2 * j;
                int covered = temp + k * j;
                //cout << temp << " " << covered << endl;
                if ((covered >= kk) && (temp < minVal))
                {
                    minVal = temp;
                }
                else if ((k > 1 || j > 1) && covered - 2 >= kk && temp - 1< minVal)
                    minVal = temp - 1;
                else if ((covered < kk) && (temp + kk - covered < minVal))
                    minVal = temp - covered + kk;

            }
		}
		printf("Case #%d: %d\n", t, minVal);


    }
	return 0;
}