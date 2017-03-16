#include<iostream>
using namespace std;
int main()
{      
   freopen("n.txt","w",stdout);
   int t;
   cin>>t;
   int ca=0;
   while(t--)
   {
      int a,b;
      double x,correct=1;
      cin>>a>>b;
      double mn=a+b+1;
      for(int i=0;i<a;i++)
      {
        scanf("%lf",&x);
        correct*=x;
        double thisone=(a+b-2*i-1)*correct+(a+2*b-2*i)*(1-correct);
        if(thisone<mn)
          mn=thisone;
        //cout<<thisone<<endl;
      }
      if(b+2<mn)
        mn=b+2;
      printf("Case #%d: %.6lf\n",++ca,mn);
   }
   return 0;
}
