#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<double> V1;
vector<double> V2;

int main()
{
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int nc;
    cin >> nc;
    for (int tc=1; tc<=nc; tc++)
    {
        V1.clear();
        V2.clear();
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
        {
            double x;
            cin >> x;
            V1.push_back(x);
        }
        for (int i=0; i<n; i++)
        {
            double x;
            cin >> x;
            V2.push_back(x);
        }
        sort(V1.begin(), V1.end());
        sort(V2.begin(), V2.end());
        int z = 0;
        for (int j=n-1, i=n-1, k=0; k<n; k++)
        {
            if (V1[i] > V2[j])
            {
                i--;
                z++;
            }
            else
            {
                i--;
                j--;
            }
        }
        int y = 0;
        for (int j=0, i=0, k=0; k<n; k++)
        {
            if (V1[i] > V2[j])
            {
                i++;
                j++;
                y++;
            }
            else
            {
                i++;
            }
        }
        cout << "Case #" << tc << ": "  << y << " " << z << endl;
    }
    fclose (stdout);
    return 0;
}

