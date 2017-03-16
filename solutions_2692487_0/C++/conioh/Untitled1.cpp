#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstdio>
#include<fstream>
#include<string>
using namespace std;
int arr[10];
int main()
{
    ifstream istr;
    ofstream ef;
    int t,i,n,j,my,k;
    istr.open("A-small-attempt1.in");
    istr>>t;
    ef.open("2.txt");
    for(i=1;i<=t;i++){
                      istr>>my>>n;
                      for(j=0;j<n;j++){
                                       istr>>arr[j];
                      }
                      sort(arr,arr+n);
                      int ans=n;
                      int ct=0;
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
