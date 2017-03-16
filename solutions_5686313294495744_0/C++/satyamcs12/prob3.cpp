#include<bits/stdc++.h>
using namespace std;
string first[2000],second[2000];
int rl[2000];

int main()
{

    int t,i,j,k;

    scanf("%d",&t);

    for(int k1=0;k1<t;k1++)
    {

        cout<<"Case #"<<k1+1<<": ";
    int cnt=0;
    int n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>first[i];
        cin>>second[i];

    }
     for(i=0;i<(1<<n);i++)
     {
         for(j=0;j<n;j++)
         {

         if((i&(1<<j))!=0)
         {
             int f1=0;
             int s1=0;

             for(k=0;k<n;k++)
             {
                 if((i&(1<<k))==0)
                 {
                     if(first[j]==first[k])
                     f1=1;
                     if(second[j]==second[k])
                     s1=1;



                 }

             }

             if(s1==0||f1==0)
             break;
         }



         }
         if(j==n)
         {
             int c1=0;
             for(j=0;j<n;j++)
             {
                 if((i&(1<<j))!=0)
                 c1++;
             }
             if(c1>cnt)
             cnt=c1;

         }



     }

    cout<<cnt<<endl;


    }

    return 0;

}
