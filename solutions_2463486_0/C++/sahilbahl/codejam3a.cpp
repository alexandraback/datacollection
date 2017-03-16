#include<iostream>
#include<math.h>
using namespace std;
int palin(int num)
{
    int n= num,rev=0,digit;
    do
     {
         digit = num%10;
         rev = (rev*10) + digit;
         num = num/10;
     }while (num!=0);
     if(n==rev)
     {
               return 1;
     }
     else
     {
         return 0;
     }
}
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("output.in","w",stdout);
    int cases,ans=0;
    cin>>cases;
    int count=0;
    int counter1=0;
    cin.ignore();
    while(cases--)
    {
                  counter1++;
      ans=0;
      int a,b, counter=0;
      
         int arr[] = {1,4,9, 121,484,676,10201};
         cin>>a;
         cin>>b;
         for(int i=0;i<6;i++)
         {
            if(arr[i]>=a&&arr[i]<=b)
            {
             if(palin((int)sqrt(arr[i])))
             {
                   ans++;
             }
            }
         } 
         cout<<"Case #"<<counter1<<": "<<ans<<endl;
    }
    
system("pause");
return 0;
}
