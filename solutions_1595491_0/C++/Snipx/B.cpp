# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <math.h>
# include <algorithm>
# include <string.h>
# include <stack>
# include <queue>
# include <sstream>
# include <set>
# include <map>
using namespace std;

int maxi_s[33], maxi[33];
int f[111][111];

int main()
{
    //ios_base::sync_with_stdio(false);
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");
    int ttt;
    cin >> ttt;
    
    memset(maxi_s, -1, sizeof(maxi_s));
    memset(maxi, -1, sizeof(maxi));
    
    for (int a = 0; a <= 10; a++)
        for (int b = 0; b <= 10; b++)
            for (int c = 0; c <= 10; c++)
            {
                int s = a + b + c;
                if (abs(a - c) > 2 || abs(a - b) > 2 || abs(b - c) > 2)
                   continue;
                if (abs(a - c) == 2 || abs(a - b) == 2 || abs(b - c) == 2)
                   maxi_s[s] = max(maxi_s[s], max(a, max(b, c)));
                else
                    maxi[s] = max(maxi[s], max(a, max(b, c)));
            }
    
    int test = 1;
    while (ttt--)
    {
          cout << "Case #" << test++ << ": ";
          int n, s;
          cin >> n >> s;
          int p;
          cin >> p;
          vector<int> a(n);
          for (int i = 0; i < n; i++)
              cin >> a[i];
          memset(f, -1, sizeof(f));
          f[0][0] = 0;
          for (int i = 1; i <= n; i++)
              for (int j = 0; j <= i; j++)
                {
                       if (j > 0 && maxi_s[a[i - 1]] != -1)
                          f[i][j] = max(f[i][j], f[i - 1][j - 1] + (maxi_s[a[i - 1]] >= p ? 1 : 0));
                          
                       if (maxi[a[i - 1]] != -1)
                          f[i][j] = max(f[i][j], f[i - 1][j] + (maxi[a[i - 1]] >= p ? 1 : 0));
                } 
          cout << f[n][s] << endl;
    }
    //system("pause");
    return 0;
}
