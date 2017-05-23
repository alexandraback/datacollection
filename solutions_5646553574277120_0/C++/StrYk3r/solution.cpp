#include<bits/stdc++.h>
using namespace std;


bool isSubsetSum(int set[], int n, int sum)
{
   // Base Cases
   if (sum == 0)
     return true;
   if (n == 0 && sum != 0)
     return false;

   // If last element is greater than sum, then ignore it
   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);

   /* else, check if sum can be obtained by any of the following
      (a) including the last element
      (b) excluding the last element   */
   return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}



int main()
{
    int t,n,l,p;
    ifstream IF;
    ofstream OF;
    IF.open("input.txt");
    OF.open("output.txt");
    IF>>t;
    for(p=1;p<=t;p++)
    {
        int c,v,d,i,j=0;
        IF>>c>>d>>v;
        int a[10000];
        for(i=0;i<d;i++)
        {
            IF>>a[i];
        }
        for(i=1;i<=v;i++)
        {
            if(!isSubsetSum(a,d,i))
            {
                j++;
            a[d]=i;
            d++;}
        }
        OF<<"Case #"<<p<<": "<<j<<endl;
    }
    IF.close();
    OF.close();
    return 0;
}
