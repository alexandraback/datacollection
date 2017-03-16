#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
double a[205];
double b[205];
int main()
{
    freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    int t, Case = 1, i;
    scanf("%d",&t);
    while(t--)
    {
       int n;
       scanf("%d",&n);
       double temp1 = 0, temp2=0;
       for(i = 0; i < n; i++)
       {
         scanf("%lf",&a[i]);
         b[i] = a[i];
         temp1 += a[i];
       }
       sort(b, b+n);
       b[n] = 1000000;
       double ans = 0;
       for(i = 0;i < n; i++)
       {
			  if( ( b[i+1]-b[i] ) * (i+1) + temp2 >= temp1)
			  {
				  ans = b[i] + (temp1-temp2) / (i+1);
				  break;
			  }
			  else 
				  temp2 += ( b[i+1] - b[i] ) * (i+1);
       }
       printf("Case #%d: ",Case++);
       for(i = 0; i < n; i++)
       {
			 if(a[i] >= ans)
			 {
				printf("0 ");
			 }
			 else 
			 {
				printf("%.6lf ",100 * (ans-a[i]) / temp1);
			 }
	   }
	   puts("");
    }
    return 0;
}
