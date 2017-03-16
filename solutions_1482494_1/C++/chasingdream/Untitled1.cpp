#include<iostream>
#include<string.h>
using namespace std;
int A[1000+10];
int B[1000+10];
int flag[1000+10];
int main()
{
     int t;
     cin>>t;
     freopen("n.txt","w",stdout);
     for(int ca=1;ca<=t;ca++)
     {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
          scanf("%d%d",&A[i],&B[i]);
        }
        memset(flag,0,sizeof(flag));
        int sum=0;
        int atp=0;
        int star=0;
        while(sum<n)
        {
           atp++;
           int ff=0;
           for(int i=0;i<n;i++)
           {
              if(star>=B[i])
              {
                   if(flag[i]==0)
                   {
                     ff=1,star+=2;
                     flag[i]=2;
                     sum++;
                     break;
                   }
                   else if(flag[i]==1)
                   {
                     ff=1,star++;
                     flag[i]=2;
                     sum++;
                     break;
                   }
              }
           }
           if(ff==1)
             continue;
           int hehe=-1,gai;
           for(int i=0;i<n;i++)
           {
              if(flag[i]==0&&star>=A[i])
              {
                  ff=1;
                  if(B[i]>hehe)
                    hehe=B[i],gai=i;
                  //break;
              }
           }
           if(ff==0)
             break;
           flag[gai]++;
           star++;   
        }
        if(sum<n)
            printf("Case #%d: Too Bad\n",ca);
        else
            printf("Case #%d: %d\n",ca,atp);
     }
     return 0;
}
