#include<iostream>
using namespace std;
int bff[1020],temp[1020],pret[1000],tl,pl,longest;
int isin(int a)
{
    int i;
    for(i=0;i<=1000;i++)
    {
        if(temp[i]==a||pret[i]==a)
        {
            return 1;
        }
    }
    return 0;
}
void fq(int a)
{
    int i,k;
    k=1;
    if(isin(bff[a])==0)
    {
        k=0;
        temp[tl+1]=bff[a];
        tl++;
        fq(temp[tl]);
        tl--;
        temp[tl+1] =0;
    }
    for(i=0;i<1010;i++)
    {
        if(bff[i]==a&&isin(i)==0)
        {
            k=0;
            temp[tl+1]=i;
            tl++;
            fq(temp[tl]);
            tl--;
            temp[tl+1]=0;
        }
    }
    if(k)
    {
        if(longest<pl+tl+1)
        {
            longest = pl+tl+1;
        }
    }
    return;
}
void fi(int a)
{
    int k,i;
    k=1;
    for(i=1;i<1010;i++)
    {
        if(bff[i]==a&&isin(i)==0)
        {
            k=0;
            pret[pl]=i;
            pl++;
            fi(i);
            pl--;
            pret[pl]=0;
        }
    }
    if(k)
    {
        fq(temp[tl]);
    }
    return;
}
int main()
{
	int i,j,k,l,n,t,bout,q,w,e;
	cin>>n;
	for(t=1;t<=n;t++)
    {
        for(i=0;i<1020;i++)
        {
            bff[i]=0;
            temp[i]=0;
        }
        cin>>k;
        for(i=1;i<=k;i++)
        {
            cin>>bff[i];
        }
        bout=0;
        for(l=1;l<=k;l++)
        {
            longest =0;
            for(i=0;i<1020;i++)
            {
                temp[i]=0;
                pret[i]=0;
            }
            tl=0;pl=0;
            temp[0]=l;
            fi(l);
            if(longest>bout)
            {
                bout=longest;
            }

        }

        cout<<"Case #"<<t<<": "<<bout<<endl;
    }
}
