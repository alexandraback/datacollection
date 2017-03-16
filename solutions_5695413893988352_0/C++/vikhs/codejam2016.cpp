#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mini,cat,jat;
char care[10],jab[10];
void f(int c,int j,int a,int b)
{
    if(!care[c]&&!jab[j])
    {
        int diff;
        diff=abs(a-b);
        if(diff<mini)
        {
            mini=diff;
            cat=a,jat=b;
        }
        else if(diff==mini)
        {
            if(a<cat)
                cat=a,jat=b;
            else if(a==cat&&b<jat)
                jat=b;
        }
        return;
    }
    if(care[c])
    {
        if(care[c]=='?')
        {
            for(int i=0;i<=9;i++)
                f(c+1,j,a*10+i,b);
        }
        else
            f(c+1,j,a*10+care[c]-'0',b);
    }
    if(jab[j])
    {
        if(jab[j]=='?')
        {
            for(int i=0;i<=9;i++)
                f(c,j+1,a,b*10+i);
        }
        else
            f(c,j+1,a,b*10+jab[j]-'0');
    }
}
int main()
{
    FILE *pin,*ptrout;
    pin=fopen("C:\\Users\\DELL\\Desktop\\in.txt","r");
    ptrout=fopen("C:\\Users\\DELL\\Desktop\\out.txt","w");
    int t,T,i,n,tmp,c1,j1,j;
    fscanf(pin,"%d",&T);
    for(t=1;t<=T;t++)
    {
        fscanf(pin,"%s%s",care,jab);
        mini=cat=jat=INT_MAX;
        f(0,0,0,0);
        c1=cat,j1=jat;
        i=0;
        while(c1)
        {
            i++;
            c1/=10;
        }
        fprintf(ptrout,"Case #%d: ",t);
        if(cat==0)
            i=1;
        for(j=0;j<strlen(care)-i;j++)
            fprintf(ptrout,"0");
        fprintf(ptrout,"%d ",cat);
        i=0;
        while(j1)
        {
            i++;
            j1/=10;
        }
        if(jat==0)
            i=1;
        for(j=0;j<strlen(jab)-i;j++)
            fprintf(ptrout,"0");
        fprintf(ptrout,"%d\n",jat);
        //fprintf(ptrout,"Case #%d: %d %d\n",t,cat,jat);
    }
    fclose(pin);
    fclose(ptrout);
    return 0;
}
