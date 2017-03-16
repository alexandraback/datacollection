#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

#define int64 long long int
#define MX 2000000000000000

int arr[20];

bool palin_chk(int64 n)
{
    int pos = 1;

    while(n)
    {
        int64 v = n%10;
        arr[pos++] = v;
        n/=10;
    }

    bool chk = true;

    for(int i=1,j=pos-1;i<j;i++,j--)
    {
        if(arr[i]!=arr[j])
        {
            chk = false;
            break;
        }
    }

    return chk;
}

vector<int64>data;
int64 num;

int main()
{
    freopen("C-large-1.in","r",stdin);
    freopen("C-large-1.out","w",stdout);



    for(int i=1;i<=10000000;i++)
    {
        if(palin_chk(i))
        {
            num = (int64)i*i;
            if(palin_chk(num))
            {
                data.push_back(num);
            }
        }
    }

    data.push_back(MX);

    int64 t,a,b,posA,posB,lo,hi,mid,cc=1;
    bool fnd;


//    for(int i=0;i<=39;i++)
//    {
//        cout<<data[i]<<" "<<endl;
//    }

    cin>>t;

    while(t--)
    {
        cin>>a>>b;

        lo = 0;
        hi = data.size() - 1;
        fnd = false;

        while(lo<=hi)
        {
            mid = (lo+hi)/2;

            if(data[mid]==a)
            {
                fnd = true;
                posA = mid;
                break;
            }
            else if(data[mid]>a)
            {
                hi = mid - 1;
            }
            else if(data[mid]<a)
            {
                lo = mid + 1;
            }
        }

        if(!fnd) posA = lo;

//        cout<<"SSS "<<endl;

        lo = 0;
        hi = data.size() - 1;
        fnd = false;

        while(lo<=hi)
        {
            mid = (lo+hi)/2;

            if(data[mid]==b)
            {
                fnd = true;
                posB = mid;
                break;
            }
            else if(data[mid]>b)
            {
                hi = mid - 1;
            }
            else if(data[mid]<b)
            {
                lo = mid + 1;
            }
        }

        if(!fnd) posB = hi;

//        cout<<"s "<<posB<<endl;

        cout<<"Case #"<<cc++<<": "<<(posB  - posA + 1)<<endl;
    }

    return 0;
}
