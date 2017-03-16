#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    freopen("A-small-attempt4.in","r",stdin);
    freopen("OUTPUT.TXT","w",stdout);
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cout << "Case #" << i+1 << ": ";
        int k;
        cin >> k;
        vector <int> a(k);
        int min=0;
        int sum=0;
        for (int i=0;i<k;i++)
        {
            cin >> a[i];
            sum+=a[i];
        }
        vector <bool> is(k);
        int s=2*sum;
        int cnt=k;
        int k1=k;
        bool flag=true;
        int s1=s;
        while (k1!=cnt||flag)
        {
            k1=cnt;
            s1=s;
            flag=false;
            for (int i=0;i<k;i++)
            {
            if (!is[i]&&k1*a[i]>s1)
            {
                is[i]=true;
                s-=a[i];
                cnt--;
            }
            }
        }


        for (int i=0;i<k;i++)
        {
            long double z;
            if (is[i]) z=0; else z=((long double)s/(long double)cnt-(long double)a[i])/(long double)sum;
            z*=100;
            //if (z<0) z=0;
            printf ("%.7f ",(double)z);
        }
        cout << endl;
    }

    return 0;
}
