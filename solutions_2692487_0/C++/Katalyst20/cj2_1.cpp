#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
       freopen("input.in","r",stdin);
       freopen("output.in","w",stdout);
       int t,mot,i,c=0,n,sum;
       cin>>t;
       for(int j=1;j<=t;j++)
       {
              cin>>mot>>n;
              c=0;
              int c1=0;
              sum=mot;
              int a[n];
              //int mot,n;
              for(i=0;i<n;i++)
              cin>>a[i];
              sort(a,a+n);
              if(mot==1)
              {cout<<"Case #"<<j<<": "<<n<<endl;
              continue;
              }
              for(i=0;i<n;)
              {
                     if(sum>a[i])
                     {
                            sum+=a[i];
                            i++;
                     }
                     else if(sum+sum-1>a[i])
                     {
                            sum=sum+sum-1+a[i];
                            c++;
                            i++;
                            
                     }
                     else
                     {
                            c++;
                            sum=sum+sum-1;
                            //n--;
                            
                            
                            //continue;
                     }
              }
              //cout<<"abc"<<endl;
              sum=mot;
              for(i=0;i<n;)
              {
                     if(sum>a[i])
                     {
                            sum+=a[i];
                            i++;
                     }
                     else if(sum+sum-1>a[i])
                     {
                            sum=sum+sum-1+a[i];
                            c1++;
                            i++;
                            
                     }
                     else
                     {
                            c1++;
                            //sum=sum+sum-1;
                            n--;
                            
                            
                            //continue;
                     }
              }
              cout<<"Case #"<<j<<": "<<min(c,c1)<<endl;
       }
       //system("pause");
       return 0;
}
