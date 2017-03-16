#include<iostream>
#include<cstdio>
#include<algorithm>
#include<fstream>

using namespace std;

int motes[1005];

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int tc;
    scanf("%d",&tc);
    for (int i=0; i<tc; i++)
    {
        int a,n;
        int ans=1000000000;
        int tmp=0;
        scanf("%d%d",&a,&n);
        for (int j=0; j<n; j++)
        {
            scanf("%d",motes+j);
        }
        int motesleft=n;
        sort(motes,motes+n);
        int pt=0;
        //Run Simulation
        while (pt<n && a>motes[pt])
        {
              a+=motes[pt];
              motesleft--;
              pt++;
        }
        ans=min(ans,motesleft);
        if (a!=1)
        {
            while (motesleft!=0) //There are still some motes left
            {
                  //printf("pt:%d,motesleft:%d,a:%d,tmp:%d\n",pt,motesleft,a,tmp);
                  //Add a new mote
                  a+=(a-1);
                  //Run Simulation
                  while (pt<n && a>motes[pt])
                  {
                     a+=motes[pt];
                     motesleft--;
                     pt++;
                  }
                  tmp+=1;
                  ans=min(ans,tmp+motesleft);
                  if (pt==n)
                  {
                     break;
                  }
            }
        }
        printf("Case #%d: %d\n",i+1,ans);
    }
}
