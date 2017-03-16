#include<iostream>
#include<math.h>
using namespace std;
int f[1000],n,large=0,temp;
int combi[1000];
int out()
{
    int i,o=0;
    for(i=1;i<n-1;i++)
    {
        if((f[combi[i]-1]==combi[i-1])||(f[combi[i]-1]==combi[i+1]))
        {
            o++;
        }
    }
    if((f[combi[0]-1]==combi[n-1])||(f[combi[0]-1]==combi[1]))
    {
        o++;
    }
    if((f[combi[n-1]-1]==combi[0])||(f[combi[n-1]-1]==combi[n-2]))
    {

        o++;
    }
    return o;
}
int check()
{

    int j,i,o=0;
    for(j=n;j>0;j--)
    {
    int flag=1;
    for(i=1;i<j-1;i++)
    {
        if(!((f[combi[i]-1]==combi[i-1])||(f[combi[i]-1]==combi[i+1])))
        {
            flag=0;
        }
    }
    if(!((f[combi[0]-1]==combi[j-1])||(f[combi[0]-1]==combi[1])))
    {
        flag=0;
    }
    if(!((f[combi[j-1]-1]==combi[0])||(f[combi[j-1]-1]==combi[j-2])))
    {

        flag=0;
    }
    if(flag==1)
    {
        return j;
    }
    }

}
void swapp (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(int *a,int i,int n)
{
    int j;
    int k;
    if (i == n)
        {   temp=check();
            if(temp>large)
            {
                large=temp;
            }
        }
    else
    {
        for (j = i; j <= n; j++)
        {
            swapp((a + i), (a + j));
            permute(a, i + 1, n);
            swapp((a+i), (a + j));
       }
   }
}
int main()
{

    int t,k,c,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        large=0;
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>f[j];
        }
        for(j=0;j<n;j++)
        {
            combi[j]=j+1;
        }
        permute(combi,0,n-1);
        cout<<"Case #"<<i+1<<": "<<large<<"\n";
    }
    return 0;
}
