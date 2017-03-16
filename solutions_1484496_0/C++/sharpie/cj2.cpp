#include <iostream>
#include <vector>

using namespace std;

int arr[21];
int hashmap[10000001];
int main()
{
   int t,T,n,i,j;
   cin >> t;
   for(int k=0;k<t;k++)
   {
           cin >> n;
           memset(hashmap,0,sizeof(hashmap));
           for(i=0;i<n;i++)
           {
                           cin >> arr[i];
           }            
           printf("Case #%d: \n",k+1);
           for(i=1;i<(1<<n);i++)
           {
                                int s=0;
                                for(j=0;j<n;j++)
                                {
                                                if(i&(1<<j))
                                                s+=arr[j];
                                }
                                if(hashmap[s])
                                {
                                        for(j=0;j<n;j++){
                                                         if(hashmap[s]&(1<<j)){
                                                                         cout<<arr[j]<<" ";
                                                         }
                                        }
                                        cout<<endl;
                                        for(j=0;j<n;j++)
                                        {
                                                        if(i&(1<<j))
                                                        {
                                                                    cout<<arr[j]<<" ";    
                                                        }
                                        }
                                        cout<<endl;
                                        break;
                               }
                               else hashmap[s]=i;
           }
           if(i==(1<<n))
           {
                        cout<<"Impossible" << endl;
           }
   }
   return 0;
}
