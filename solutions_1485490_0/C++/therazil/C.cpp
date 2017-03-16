#include<iostream>
#include<cstdio>
#include<algorithm>
#include<fstream>
using namespace std;
int q,t,n,m,i,j,k,h,boxt[128],toyt[128];
long long boxn[128],toyn[128];
long long sum,curr,b1,b2,b3,ans;

int main()
{
  FILE *in=fopen("C-small-attempt4.in","r");
  FILE *out=fopen("C-small-attempt4.out","w");

  fscanf(in,"%d",& t);
  for(q=1;q<=t;q++)
  {
ans=0;
  fscanf(in,"%d%d",& n,& m);
  for(i=1;i<=n;i++) fscanf(in,"%I64d%d",& boxn[i],& boxt[i]);
  for(i=1;i<=m;i++) fscanf(in,"%I64d%d",& toyn[i],& toyt[i]);

  if (n==3)
  {
    sum=0;
    for(i=1;i<=m;i++)
     if (toyt[i]==boxt[1]) sum+=toyn[i];
    if (boxt[1]==boxt[3]) ans=min(sum,boxn[1]+boxn[3]);
    if (boxt[1]==boxt[2] && boxt[1]==boxt[3]) ans=min(sum,boxn[1]+boxn[2]+boxn[3]);

    for(i=0;i<=m;i++)
     for(j=i;j<=m;j++)
      {
         sum=0;
         b1=boxn[1];b2=boxn[2];b3=boxn[3];
         for(h=1;h<=i;h++)
          if (toyt[h]==boxt[1]) { curr=min(toyn[h],b1);b1-=curr;sum+=curr;if (b1==0);break;}
         for(h=i+1;h<=j;h++)
          if (toyt[h]==boxt[2]) { curr=min(toyn[h],b2);b2-=curr;sum+=curr;if (b2==0);break;}
         for(h=j+1;h<=m;h++)
          if (toyt[h]==boxt[3]) { curr=min(toyn[h],b3);b3-=curr;sum+=curr;if (b3==0);break;}
         if (sum > ans) ans=sum;
      }
    fprintf(out,"Case #%d: %I64d\n", q, ans);
  }
  else
  if (n==2)
  {
    sum=0;
    for(i=1;i<=m;i++)
     if (toyt[i]==boxt[1]) sum+=toyn[i];
    if (boxt[1]==boxt[2]) ans=min(sum,boxn[1]+boxn[2]);

    for(i=0;i<=m;i++)
    {
       sum=0;
       b1=boxn[1];b2=boxn[2];
       for(h=1;h<=i;h++)
        if (toyt[h]==boxt[1]) { curr=min(toyn[h],b1);b1-=curr;sum+=curr;if (b1==0);break;}
       for(h=i+1;h<=m;h++)
        if (toyt[h]==boxt[2]) { curr=min(toyn[h],b2);b2-=curr;sum+=curr;if (b2==0);break;}
       if (sum>ans) ans=sum;
    }
    fprintf(out,"Case #%d: %I64d\n", q, ans);
  }
  else
  if (n==1)
  {
    sum=0;
    for(i=1;i<=m;i++)
     if (toyt[i]==boxt[1]) sum+=toyn[i];
    ans=min(sum,boxn[1]);
    fprintf(out,"Case #%d: %I64d\n", q, ans);
  }
  }
  fclose(in);
  fclose(out);
return 0;
}
