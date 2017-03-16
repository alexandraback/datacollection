#include <iostream>
#include <vector>

using namespace std;

int a[201];

int main()
{
   int t,n,i,j;
   cin >> t;
   for(int k=0; k<t; k++){
             cin >> n;
             int s=0;
             for(i=0;i<n;i++)
             {
                             cin >> a[i];
                             s+=a[i];
             }                  
             double lo=0.0, hi=1.0,mid;
             printf("Case #%d: ",(k+1));
             for(i=0;i<n;i++)
             {
                             lo=0.0, hi=1.0;
                             for(j=0;j<200;j++)
                             {
                                               mid=(lo+hi)/2.0;
                                               double x=a[i]+mid*s;
                                               double tot=mid;
                                               for(int k=0;k<n;k++)
                                               {
                                                       if(k==i) continue;
                                                       tot+=max(0.0,(x-a[k])/s);
                                               }
                                               if(tot+1e-8>1.0)
                                                               hi=mid;
                                               else lo=mid;
                             }
                             cout << 100.0*mid << " ";
             }
             cout<<endl;
   }
   return 0;
}                               
