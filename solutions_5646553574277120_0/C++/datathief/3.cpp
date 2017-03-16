#include<iostream>
//#include<conio.h>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;

bool isSubsetSum(int set[], int n, int sum)
{
  
   if (sum == 0)
     return true;
   if (n == 0 && sum != 0)
     return false;
 
   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);
 
   return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}


int main() {
    int t,o=1;
    cin>>t;
    while(t--)
    {
        int c,d,v,i,j,co=0;
        cin>>c>>d>>v;
        int a[6];
        for(i=0;i<d;i++)
        {cin>>a[i]; j=i;}
        for(i=1;i<=v;i++)
        {   
if(!isSubsetSum(a, d, i))
{
    a[++j]=i;
    co++;
}



        }
        
        cout<<"Case #"<<o<<": "<<co<<endl;
        
o++;
    }
    
    //getch();
return 0;         
}
