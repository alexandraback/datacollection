#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    //freopen("A.in", "r", stdin);
    freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-large.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    //freopen("A-large.out", "w", stdout);
    
     double a[500][500],b[500][1],x[500],max,m,*c,*d;
     double s[500];
 /*int k=0,q=0,n,i,j;
 int T;
 scanf("%d", &T);
 for (int t = 1; t <= T; ++t) {
 scanf("%d",&n);
 
 double tot = 0.0;
 for (i = 0; i < n; ++i) {
        scanf("%lf", &s[i]);
        tot += s[i];
    }
    
   for (i = 0; i < n - 1; ++i) {
        a[i][i] = tot; a[i][i + 1] = -tot; b[i][0] = s[i + 1] - s[i];
    }
    for (i = 0; i < n; ++i)
        a[n - 1][i] = 1.0;
    b[n - 1][0] = 1.0;
    
 for(k=0;k<n && q==0;k++)
 {
    max=max_value(a,n,k);
    if(max==0)
       q=1;
    else
  {      if(I!=k)
    {
     c=&b[I][0];
     d=&b[k][0];
     change(c,d);

     for(j=k;j<n;j++)
     {
       c=&a[I][j];
       d=&a[k][j];
       change(c,d);
     }
     }
    for(i=k+1;i<n;i++)
     {
       m=a[i][k]/a[k][k];
       b[i][0]=b[i][0]-b[k][0]*m;
         for(j=0;j<n;j++)
           a[i][j]=a[i][j]-a[k][j]*m;
     }
  }
}
for(i=n-1;i>=0;i--)
{
   for(j=i+1;j<n;j++)
     b[i][0]=b[i][0]-a[i][j]*x[j];
   x[i]=b[i][0]/a[i][i];
}
for(i=0;i<n;i++)
   printf("x[%d]=%6.2f\n",i,x[i]);
   /*printf("%f",max);*/
   /*for(i=0;i<n;i++)
   for(j=0;j<n;j++)
    printf("%f",a[i][j]);
    getch();*/

int k,Pr,i,j; 
double t,total; 
int T, n;
 scanf("%d", &T);
 for (int tt = 1; tt <= T; ++tt) {
 scanf("%d",&n);
 
 double tot = 0.0;
 for (i = 0; i < n; ++i) {
        scanf("%lf", &s[i]);
        tot += s[i];
    }
    for (i = 0; i < n; ++i) {
    for (j = 0; j <= n; ++j) a[i][j] = 0.0;
    x[i] = 0.0;
    }
    
   for (i = 0; i < n - 1; ++i) {
        a[i][i] = tot; a[i][i + 1] = -tot; a[i][n] = s[i + 1] - s[i];
    }
    for (i = 0; i < n; ++i)
        a[n - 1][i] = 1.0;
    a[n - 1][n] = 1.0;



for(k=0;k<n-1;k++) 
{ 
Pr=k; 
for(i=k+1;i<n;i++) 
{ 
    if(a[i][k]>a[Pr][k]) 
    Pr=i; 
} 
if(Pr>k) 
for(j=k;j<n+1;j++) 
{ 
    t=a[k][j]; a[k][j]=a[Pr][j]; a[Pr][j]=t; 
} 
for(i=k+1;i<n;i++) 
{ 
t=a[i][k]; 
for(j=k;j<n+1;j++) 
a[i][j]=a[i][j]-(t*a[k][j])/a[k][k]; 
} 
} 
x[n-1]=a[n-1][n]/a[n-1][n-1]; 
for(i=n-2;i>=0;i--) 
{ 
total=a[i][n]; 
for(j=n-1;j>i;j--) 
total=total-x[j]*a[i][j]; 
x[i]=total/a[i][i]; 
} 
printf("Case #%d:", tt);
for(i=0;i<n;i++) 
printf(" %.6lf", x[i] * 100);
puts("");
}


    
    return 0;
}
