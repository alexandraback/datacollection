#include<bits/stdc++.h>
using namespace std;
bool isSubsetSum(long long  set[], long long  n, long long  sum)
{
    bool subset[sum+1][n+1];
    for (int i = 0; i <= n; i++)
      subset[0][i] = true;
    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
       }
     }
     return subset[sum][n];
}
 int main()
 {
    ifstream IF;
     ofstream OF;
     IF.open("input.txt");
     OF.open("output.txt");
     int t,trm;
long long C,D,V,i,arr[100010],cnt;
IF>>t;
for(trm=1;trm<=t;trm++)
{
IF>>C>>D>>V;
for(int i=0;i<D;i++)
    IF>>arr[i];
    cnt=0;
for(int i=1;i<=V;i++)
{
    if(isSubsetSum(arr,D,i)==false)
        {cnt++;
        arr[D++]=i;}

}
OF<<"Case #"<<trm<<": "<<cnt<<endl;



}



IF.close();
OF.close();
return 0;
 }
