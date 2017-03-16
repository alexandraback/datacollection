#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int s[256];
    double res[256];
    bool done[256];
    int T;
    cin >> T;
    for (int t=1; t <=T; t++)
    {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> s[i];

        int sum=0;
        for (int i=0; i<n; i++)
        {
            done[i] = false;
            sum += s[i];
        }

        bool go = true;

        int c = n;
        double x;
        while (go)
        {
            go = false;
            int tmpsum=0;
            for (int i=0; i<n; i++)
            {
                if(!done[i])
                    tmpsum += s[i];
            }

            x = ((double)sum + tmpsum) / c;

            for (int i = 0; i < n; i++)
            {
                if (!done[i] && (x <= (double)s[i]))
                {
                    res[i] = 0.0;
                    done[i] = true;
                    c--;
                    go = true;
                }
            }

        }

        for (int i = 0; i < n; i++)
        {
            if (done[i])
                continue;   
            res[i] = (x - s[i])/(double)sum;
            res[i] *= 100.0;
        }

        cout << "Case #" << t << ":";
        for (int i = 0; i <n; i++)
            cout << " " << res[i];
        cout << endl;
    }

    return 0;
}
