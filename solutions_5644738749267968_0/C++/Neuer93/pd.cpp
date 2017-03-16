#include <iostream>

using namespace std;

int main()
{
    double a[11],b[11];
    int t,amin,amax,bmin,bmax,n,sum,count;
    cin>>t;

    for (int ii = 0; ii < t; ++ii)
    {
        cin>>n;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin>>b[i];
        }
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                if (a[i] > a[j])
                {
                    double temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                if (b[i] > b[j])
                {
                    double temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;
                }
        cout<<"Case #"<<ii + 1<<": ";
        sum = 0;
        count = 0;

        amin = 0;
        amax = n - 1;
        bmin = 0;
        bmax = n - 1;

        while(count < n){
            while(a[amax] < b[bmax] && count < n){
                ++amin;
                --bmax;
                ++count;
            }
            while(a[amin] < b[bmin] && count < n){
                ++amin;
                --bmax;
                ++count;
            }
            if (count < n)
            {
                ++amin;
                ++bmin;
                ++sum;
                ++count;
            }
        }
        cout<<sum;

        amin = 0;
        amax = n - 1;
        bmin = 0;
        bmax = n - 1;
        sum = 0;

        while(bmin <= bmax){
            while(a[amin] > b[bmin] && bmin <= bmax){
                ++bmin;
            }
            if (bmin <= bmax)
            {
                ++bmin;
                ++amin;
                ++sum;
            }
        }
        cout<<" "<<n-sum<<endl;
    }

    return 0;
}
