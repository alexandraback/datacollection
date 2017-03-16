#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int A[300000],L[200000],R[2000000];
void merge(int A[],int start,int end)
{
    int start1=start;
    int end1=(start+end)/2;
    int start2=end1+1;
    int end2=end;
    int size1=(end1-start1)+1;
    int size2=(end2-start2)+1;
    int i,j=0,k=0;
    for(i=0;i<size1;i++)
        L[i]=A[start1+i];




    for(i=0;i<size2;i++)
        R[i]=A[start2+i];


    for(i=start;i<=end;i++)
    {
        if((j<size1)&&(k<size2))
        {
            if(L[j]<R[k])
            {
                A[i]=L[j];
                j++;
            }
            else
            {
                A[i]=R[k];
                k++;
            }
        }
        else
        {
            if(j>=size1)
            {
                A[i]=R[k];k++;
            }
            else
            {
                A[i]=L[j];j++;
            }
        }
    }



}
void mergesort(int A[],int start,int end)
{
    if(start<end)
    {
         mergesort(A,start,((end+start)/2));
         mergesort(A,((end+start)/2)+1,end);
         merge(A,start,end);
    }
}

char keys[10],en[10];
int l,tot,mx;

int func(int pos, char *str, int s, int k)
{
    if(pos==s)
    {
        tot++;
        int total=0,j;
        for(int i=0;i<s;i++)
        {
            for(j=i;j<i+l&&j<s;j++)
                if(str[j]!=en[j-i])
                    break;
            if(j==i+l)
                total++;
        }
        mx=max(mx,total);
        return total;
    }
    int r=0;
    for(int i=0;i<k;i++)
    {
        str[pos]=keys[i];
        r=r + func(pos+1,str,s,k);
    }
    return r;
}

int main()
{
    freopen("inp.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,i,T,k,s,ans;
    char str[10];
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d%d%d",&k,&l,&s);
        scanf("%s",keys);
        scanf("%s",en);
        tot=0;
        mx=0;
        ans=func(0,str,s,k);
        if(mx==0)
        {
            printf("Case #%d: 0.00000\n",t);
            continue;
        }
        int an=tot*mx;
        double res=(double)an-(double)ans;
        res=res/(double)tot;
        printf("Case #%d: %.9lf\n",t,res);
    }
    return 0;
}
