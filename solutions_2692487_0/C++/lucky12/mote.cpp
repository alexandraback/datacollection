#include<iostream>
#include<stdio.h>
using namespace std;

void merge(int a[100],int p,int q,int r)
{
    int i,j;
    int n1=q-p+1;
    int n2=r-q;
    int* l;
    int* rt;
    l=new int[n1+1];
    rt=new int[n2+1];
    for(i=0;i<n1;i++)
    l[i]=a[p+i];
    for(j=0;j<n2;j++)
    rt[j]=a[q+j+1];
    l[n1]=1000000;                                                              //placing the senitals at the end of the loop
    rt[n2]=1000000;
    i=0;
    j=0;
    for(int k=p;k<=r;k++)
    {
        if(l[i]<=rt[j])
        {
            a[k]=l[i];
            i++;
        }
        else
        {
            a[k]=rt[j];
            j++;
        }
    }

}

void mergesort(int a[100],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        mergesort(a,p,q);                                                                   //recursion
        mergesort(a,q+1,r);
        merge(a,p,q,r);
    }
}

int main()
{
    FILE *fp;
    fp=fopen("abc.txt","w");
    int t;int z=0;
    scanf("%d",&t);
    while(t--)
    {
        z++;
        int m;
        int a[100];
        int n;
        scanf("%d%d",&m,&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
    mergesort(a,0,n-1);

    int c=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<m)
            m=m+a[i];
        else
        {

            if(m+m-1<=a[i+1])
            {
                c=c+(n-i);
                break;
            }
            c=c+1;
            m=m+m-1;
        }
    }
    fprintf(fp,"Case #%d: %d\n",z,c);
    }

}
