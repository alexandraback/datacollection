#include <iostream>

using namespace std;

void qs(double e[], int l, int r)
{
    int i=l,j=r;
    double temp=e[l];
    while(i<j)
    {
        while(i<j && e[j]>=temp)j--;
        e[i]=e[j];
        while(i<j && e[i]<=temp)i++;
        e[j]=e[i];
    }
    e[i]=temp;
    if(l<i-1)
    qs(e,l,i-1);
    if(r>i+1)
    qs(e,i+1,r);
}

int main()
{
    double a[1001],b[1001];
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
        qs(a,0,n-1);
        qs(b,0,n-1);

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
