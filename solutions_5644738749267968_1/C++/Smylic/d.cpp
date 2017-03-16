#include <iostream>

using namespace std;

double a[1024];
double b[1024];

bool u[1024];
bool v[1024];

int main()
{
    int t;
    cin >> t;

    for (int tt=1; tt<=t; tt++)
    {
        int n;
        cin >> n;

        for (int i=0; i<n; i++)
            cin >> a[i];
        for (int i=0; i<n; i++)
            cin >> b[i];

        sort(a, a+n);
        sort(b, b+n);

        memset(u, 0, sizeof(u));
        memset(v, 0, sizeof(v));

        int x = 0;

        for (int i=0; i < n && a[n-1] > b[x]; x++, i++)
            for (; i < n && a[i] <= b[x]; i++);

        int y = 0;
        for (int i=n-1, j=n-1; i>=0; i--)
            if (a[i] > b[j])
                y++;
            else
                j--;

        cout << "Case #" << tt << ": " << x << " " << y << endl;
    }
    return 0;
}
