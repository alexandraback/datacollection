#include<bits/stdc++.h>
using namespace std;
int buck[5000];

int main()
{
    ifstream IF;
    IF.open("input.txt");
    ofstream OF;
    OF.open("output.txt");
    int t,i,j,n,x,k;

    IF >> t;
    for(int tc=1;tc<=t;tc++)
    {
        IF>>n;
        memset(buck,0,sizeof buck);
         OF <<"Case #" << tc << ": ";

         for(i=0;i<2*n-1;i++)
         {
           for(j=0;j<n;j++)
           {
             IF>>x;
             buck[x]++;
           }
         }

         for(i=0;i<5000;i++)
         {
            if(buck[i]!=0 && buck[i]%2!=0)
            {
              OF<<i<<" ";
            }
         }
         OF<<endl;



    }

    OF.close();
    IF.close();
}
