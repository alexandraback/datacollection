#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
        long long d1,d2,m1,m2,s1,s2,n;
        cin >> n;
        if (n == 1)
        {
            long long h;
            cin >> d1;
            d2 = d1;
            cin >> h;
            if (h == 1) {cout << "Case #" << t << ": 0\n"; continue;}
            long long m;
            cin >> m;
            m1 = m, m2 = m+1;
        }
        else
        {
            long long h;
            cin >> d1 >> h >> m1;
            cin >> d2 >> h >> m2;
            if (d1 > d2) swap(d1,d2), swap(m1,m2);
        }
        long long t1 = (360-d1)*m1;
        long long t2 = (360-d2)*m2;
        if (t1 < (720-d2)*m2 and t2 < (720-d2)*m1) cout << "Case #" << t << ": 0\n";
        else cout << "Case #" << t << ": 1\n";
    }
    
    
    return 0;
}
