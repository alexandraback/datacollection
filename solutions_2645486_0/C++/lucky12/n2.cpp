#include<iostream>
#include<stdio.h>
using namespace std;
int maxi(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int e,r,n,max1;
int v[100];



void doing(int pos,int en,int gain)
{
                   if(pos==n)
                   {


                             max1=maxi(max1,gain);
                             return ;
                   }


                   for(int i=0;i<=en;i++)
                   {
                                         if((en-i+r)<=e)
                                         doing(pos+1,(en-i)+r,gain+v[pos]*i);
                                         else
                                         doing(pos+1,e,gain+v[pos]*i);
                   }

                   return ;
}
int main()
{
                    FILE *fp;
                    fp=fopen("out2.txt","w");

                    int t;

                    cin>>t;

                    for(int j=1;j<=t;j++)
                    {

                            cin>>e>>r>>n;

                            for(int i=0;i<n;i++)
                                    cin>>v[i];


                            max1=0;

                            doing(0,e,0);


                            fprintf(fp,"Case #%d: %d\n",j,max1);
                    }

                    return 0;
}
