#include<cstring>
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
     long long int t,k=0,ca=0,c1,c2;
     long long int j,a,b;
     long long int m[] = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004};
     cin>>t;
     while(t--)
     {
               ca++;

               cin>>a>>b;
               k = 39;
               if(a>m[k-1])
               {
                cout<<0<<endl;

                continue;
                }
               if(b>m[k-1])
               b=m[k-1];
               for(int i=0;i<k;i++)
               {
                       if(m[i]>=a)
                       {
                       c1=i;
                       break;}
               }
               for(int i=0;i<k;i++)
               {
                       if(m[i]<=b)
                       c2=i;
               }
                cout<<"Case #"<<ca<<": "<<c2-c1+1<<endl;

     }
}

