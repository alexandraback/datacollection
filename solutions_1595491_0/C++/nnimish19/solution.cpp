#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#define intin(a) scanf("%d",&a)
#define intsin(a,b) scanf("%d%d",&a,&b)
#define swap(a,b) c=a;a=b;b=c
#define MIN(a,b) a<b?a:b
using namespace std;
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    ofstream file1("output.txt");
    int cases,n,s,p,a[101];
    int avg,rem,g_cnt,s_cnt,x=0;
    intin(cases);
    while(++x<=cases)
    {
        intin(n);
        intsin(s,p);g_cnt=0;s_cnt=0;
        for(int i=0;i<n;i++)
        {   intin(a[i]);
            avg=a[i]/3;
            rem=a[i]%3;
            if(avg>=p)
                g_cnt++;
        //================================avg<p

            else if (rem==0)
            {   if(avg+1==p && s_cnt<s &&avg>=1)
                {   g_cnt++;
                    s_cnt++;
                }
            }

            else if(rem==1 && avg+rem==p)
                g_cnt++;

            else if(rem==2)
            {   if(avg+1==p)        //score=11  avg=3 rem=4 p=4
                    g_cnt++;
                else if(avg+2==p && s_cnt<s)
                {   g_cnt++;
                    s_cnt++;
                }
            }
        }
        //printf("Case #%d: %d\n",x,g_cnt);
        file1<<"Case #"<<x<<": "<<g_cnt<<endl;
    }
}
