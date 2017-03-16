#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstdio>
#include<fstream>
#include<string>
using namespace std;
int arr[1000000];
int main()
{
    ifstream istr;
    ofstream ef;
    int t,i,n,j,k;
    long long my;
    istr.open("A-large.in");
    istr>>t;
    ef.open("2.txt");
    for(i=1;i<=t;i++){
                      istr>>my>>n;
                      for(j=0;j<n;j++){
                                       istr>>arr[j];
                      }
                      sort(arr,arr+n);
                      long long int ans=n;
                      long long int ct=0;
                      bool flag=1;
                      for(j=0;j<n;j++){
                                      if(my>arr[j]){
                                                    my+=arr[j];
                                      } 
                                      else{
                                           flag=0;
                                           while(my<=arr[j]){
                                                             if(my==1){
                                                                       ct=1000;
                                                                       break;
                                                             }
                                                             my+=my-1;
                                                             ct++;
                                           }
                                           my+=arr[j];
                                      }
                                      ans=min(ans,ct+n-1-j);
                      }
                      ef<<"Case #"<<i<<": "<<ans<<"\n";        
    }
    ef.close();
    istr.close();
   system("pause");
   return 0;
}
