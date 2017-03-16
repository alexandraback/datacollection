#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 0.000001;

int main()
{
    ios_base::sync_with_stdio(0);

    int T;
    cin >> T;

    for(int t=1; t<=T; t++)
    {
        int n;
        cin >> n;

        double d[n];
        double h[n];
        double m[n];
        for(int i=0; i<n; i++)
            cin >> d[i] >> h[i] >> m[i];

        cout << "Case #" << t << ": ";
        if(n == 1)
            cout << "0\n";
        else
        {
            //faster at m[1]
            if(m[0] < m[1])
            {
                swap(m[0], m[1]);
                swap(d[0], d[1]);
                swap(h[0], h[1]);
            }

            //faster is first
            //if(d[1] > d[0] || fabs(d[1]-d[0]) <= EPS)
            {
                if((m[1]*(720-d[1])/360) <= (m[0]*(360-d[0])/360))
                    cout << "1\n";
                else
                    cout << "0\n";
            }
        }
    }

    return 0;
}
