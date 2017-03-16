#include<iostream>
#include<map>

using namespace std;

int main()

{
    float t,n,sum,each,c,count,temp,sum1;
    c=1;
    int  a[202],i;
    cin>>t;
    while(t--)
    {
              sum=0;
              cin>>n;
              for(i=0;i<202;i++)
              a[i]= 0;
              for(i=0;i<n;i++)
              {
              cin>>a[i];
              sum+=a[i];
              }
      //        cout<<"sum : " <<sum<<endl;
      
    sum1=sum;
    sum=sum*2;
    count=0;temp=0;
    int flag=0;
    temp=sum/n;
   // cout<<"temp : " <<temp<<endl;
    for(i=0;i<n;i++)
    {
     if(a[i]>temp)
      {sum=sum-a[i];
      count++;
      flag=1;
      }
    }    
    //cout<<"count ="<<count<<endl;
    if(flag)each = sum/(n-count);
    else
    each = temp;
   // cout<<"each : " <<each<<endl;
    //cout<<"sum : " <<sum <<endl;
    cout<<"Case #"<<c++<<": ";
    for(i=0;i<n;i++)
    {
    if(temp<a[i])
    printf( "0.000000 " );
    else
    {
    //cout<<"a[i] = "<<((each-a[i])*100)/sum<<endl;
    printf("%.6f ",((each-a[i])/sum1)*100);
}
    }
     
    cout<<endl;
    }
    //system("pause");
    return 0;
    }
