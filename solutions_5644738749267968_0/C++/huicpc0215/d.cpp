#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;
ifstream i1("D-small-attempt0.in");
//ifstream i1("dt2.txt");
ofstream o1("d_s.out");
#define eps 1e-8


double sa[1010],sb[1010];
int n;
int main()
{
    int t,casecnt=1;
    double *p;
    i1>>t;
    printf("t=%d\n",t);
    while(t--)
    {
        o1<<"Case #"<<casecnt++<<": ";
        i1>>n;
        for(int i=0;i<n;i++)
            i1>>sa[i];
        for(int i=0;i<n;i++)
            i1>>sb[i];
        //for(int i=0;i<n;i++)
        //    printf("sa =%lf sb=%lf\n",sa[i],sb[i]);
        sort(sa,sa+n);
        sort(sb,sb+n);
        int r=0,ans1=0,ans2=0;
        for(int i=0;i<n;i++)
        {
            while(r < n && sa[i]+eps > sb[r] ) r++;
            if(r==n) ans2++;
            else r++;
        }
        r = 0 ;
        for(int i=0;i<n;i++)
        {
            if( sa[i]+eps > sb[r] )
            {
                ans1++; r++;
            }

        }
        o1<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}

