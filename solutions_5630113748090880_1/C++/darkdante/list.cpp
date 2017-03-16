#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
        
         fstream fin("B-large.in",ios::in);
         fstream fout("listlarge.txt",ios::out) ; 
        ios_base::sync_with_stdio(0);
        int t,count=0;
        fin>>t;
        while(t--)
        {
                count++;
                int n;
                fin>>n;
                int arr[n],max=0;
                int j=0;
                int exp=2*(n*n)-n;
                int arr2[exp];
                for(int i=0;i<exp;i++)
                fin>>arr2[i];
                for(int i=0;i<exp;i++)
                if(arr2[i]>max)
                max=arr2[i];
                int soldier[max+1];
                for(int i=0;i<=max;i++)
                soldier[i]=0;
                for(int i=0;i<exp;i++)
                {
                        soldier[arr2[i]]++;
                 }
                 for(int i=0;i<=max;i++)
                     if(soldier[i]%2!=0)
                     arr[j++]=i;
                  fout<<"Case #"<<count<<": ";   
                 for(int i=0;i<n;i++)
                 fout<<arr[i]<<" ";
                 fout<<"\n";
           }
  }                      
                
