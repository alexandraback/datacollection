#include<iostream>
#include<queue>
#include<map>
#include<cstdio>
#include<cmath>
#include<sstream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<stdio.h>
#include<string.h>

using namespace std;

int arr[105][105];
int rowmax[105], colmax[105];
int main(){
    int t,m,n,c=1;
    int i,j;
   // freopen("input.in","r",stdin);
  //  freopen("output.out","w",stdout);
    cin>>t;
    while(t--){
               cin>>m>>n;
               for(i=0;i<m;i++)
                 for(j=0;j<n;j++)
                   cin>>arr[i][j];
               for(i=0;i<m;i++){
                  rowmax[i]=0;
                  for(j=0;j<n;j++)
                    rowmax[i]=max(rowmax[i],arr[i][j]);
               }
               for(j=0;j<n;j++){
                  colmax[j]=0;
                  for(i=0;i<m;i++)
                    colmax[j]=max(colmax[j],arr[i][j]);
               }
               for(i=0;i<m;i++)
                 for(j=0;j<n;j++)
                   if(arr[i][j]!=rowmax[i]&&arr[i][j]!=colmax[j])
                   {
                      cout<<"Case #"<<c<<": NO"<<endl;
                      goto end;
                   }
               cout<<"Case #"<<c<<": YES"<<endl;
               end:
               c++;      
    }

    return 0;
}
