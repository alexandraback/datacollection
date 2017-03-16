#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdio.h>
#define N 1010
using namespace std;

int n,i,j,k,time,tt,a[N][3],stars,tmp,sum,f[N][3],flag,mxj;
FILE *in,*out;

int main()
{
    in=freopen("B-small.in","r",stdin);
    out=freopen("output.txt","w",stdout);
    cin>>tt;
    time=1;
    while (time<=tt)
    {
        cin>>n;
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        for (i=0;i<n;i++)
            cin>>a[i][1]>>a[i][2];

        for (i=0;i<n-1;i++)
            for (j=i+1;j<n;j++)
            {
                if (a[i][2]>a[j][2])
                {
                    tmp=a[i][1];
                    a[i][1]=a[j][1];
                    a[j][1]=tmp;
                    tmp=a[i][2];
                    a[i][2]=a[j][2];
                    a[j][2]=tmp;
                }
            }
        i=0;
        stars=0;
        sum=0;
        flag=1;
        while (stars<2*n && flag==1)
        {
            flag=0;
            while (a[i][2]<=stars && i<n)
            {
                if (f[i][1]==1)
                    stars++;
                else
                    stars+=2;
                sum++;
                f[i][2]=1;
                f[i][1]=1;
                i++;
                flag=1;
            }
            if (stars<2*n)
            {
                j=0;
                mxj=-1;
                flag=0;
                while (stars<a[i][2] && j<n)
                {
                    while (f[j][1]==1 && j<n)
                        j++;
                    if (j<n && stars>=a[j][1])
                    {
                        /*
                        stars++;
                        sum++;
                        f[j][1]=1;
                        */
                        if (mxj==-1)
                            mxj=j;
                        else if (a[mxj][2]<a[j][2])
                            mxj=j;
                        flag=1;
                    }
                    j++;
                }
                if (mxj!=-1)
                {
                    stars++;
                    sum++;
                    f[mxj][1]=1;
                }
            }
        }

        if (flag==1)
            cout<<"Case #"<<time<<": "<<sum<<endl;
        else
            cout<<"Case #"<<time<<": Too Bad"<<endl;

        time++;
    }
    return 0;
}

