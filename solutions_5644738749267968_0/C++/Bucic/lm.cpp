#include<iostream>
#include<algorithm>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<algorithm>
using namespace std;
int t,r,c,m,o,n,w,dw,ai,bi;
double a[10000],b[10000];
int main()
{
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    cin>>t;
    for (o=0; o<t; o++)
    {
        cin>>n;
        for (int i=0; i<n; i++)
            cin>>a[i];

        for (int i=0; i<n; i++)
            cin>>b[i];

        sort(a,a+n);
        sort(b,b+n);
        //for (int i=0; i<n; i++)
         //   cout<<a[i]<<" ";
        //cout<<endl;
        //for (int i=0; i<n; i++)
        //    cout<<b[i]<<" ";
        //cout<<endl;
        bi=0;


        for (int i=0; i<n; i++)
            {
                for (int j=bi; j<n; j++)
                    if (j==n-1 || b[j]>a[i])
                    {
                        if (j==n-1 && b[j]>a[i])
                            {
                                bi=n-1;
                                break;
                            }

                        bi=j+1;
                        break;
                    }
                if (bi==n)
                    {
                        w=n-i;
                        break;
                    }
            }
        bi=0;
        dw=0;
        for (int i=0; i<n; i++)
        {
            if (a[i]>b[bi])
                {
                    bi++;
                    continue;
                }
        }
        dw=bi;


        cout<<"Case #"<<o+1<<": "<<dw<<" "<<w<<endl;
    }
    return 0;
}
