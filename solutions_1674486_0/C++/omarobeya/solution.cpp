#include<stdio.h>

int frm[1010][1010];
int cn[1010];
int fl[1010];
FILE*f1=fopen("A-small-attempt0.in","r");
FILE*f2=fopen("out.out","w");
char wv(int x,int st)
{
     //printf("wv %d %d\n",x,st);
     if(fl[x] == st)
     return '1';
     fl[x]=st;
     int j;
     for(j=0;j<cn[x];j++)
     if(wv(frm[x][j],st) == '1')
     return '1';
     return '0';
}
int main()
{
  int t,a,i,n,j;
    fscanf(f1,"%d",&t);
  for(a=0;a<t;a++)
  {
    fscanf(f1,"%d",&n);
    for(i=0;i<n;i++)
    fl[i]=-1;
    for(i=0;i<n;i++)
    {
      fscanf(f1,"%d",&cn[i]);
      for(j=0;j<cn[i];j++)
      {
       fscanf(f1,"%d",&frm[i][j]);
       frm[i][j]--;
      }
    }
    for(i=0;i<n;i++)
    {
     if(wv(i,i) == '1')
     {
      n=-1;
      break;
     }
     //if(cn[i] < 2)
     //continue;
    }
    if(n == -1)
     fprintf(f2,"Case #%d: Yes\n",a+1);
    else
     fprintf(f2,"Case #%d: No\n",a+1);
  }
  //scanf("%*d");



}
