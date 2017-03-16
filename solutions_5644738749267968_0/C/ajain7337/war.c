#include<stdio.h>
int n;
float a[1000],b[1000];
void sort();
int d_war();
int war();
int main()
{
    int t,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%f",&a[j]);
        }
         for(j=0;j<n;j++)
        {
            scanf("%f",&b[j]);
        }
        sort();
        printf("Case #%d: %d %d\n",i+1,d_war(),war());
    }
    return 0;
}

int d_war()
{
    int i=0,j=0,k;
    int count=0;
    while(i<n && j<n)
    {
        if(a[i]<b[j]) i++;
        else if(a[i]>b[j])
        {
            i++;
            j++;
            count++;
        }
    }
    return count;
}

int war()
{
    int i,j,bmax=n-1,bmin=0,count=0;
    /*for(i=0;i<n;i++)
    {
        a[i][1]=1;
        b[i][1]=1;
    }*/
    for(i=n-1;i>=0;i--)
    {
        if(a[i]>b[bmax])
        {
            count++;
            bmin++;
        }
        else
        {
            bmax--;
        }
    }
    return count;
}

void sort()
{
    int i,j;
    float temp,temp2;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[j]<a[i])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
             if(b[j]<b[i])
            {
                temp2=b[j];
                b[j]=b[i];
                b[i]=temp2;
            }
        }
    }
}
