#include<bits/stdc++.h>
using namespace std;
int mat[100][100];

int main()
{
    ifstream IF;
    IF.open("input.txt");
    ofstream OF;
    OF.open("output.txt");
    int t,i;

    IF >> t;
   int b;
   long long m;

    
   
    for(int tc=1;tc<=t;tc++)
    {
      OF <<"Case #"<<tc<<": ";
      memset(mat,0,sizeof mat);

      IF>>b>>m;

      long long g = (1LL<<(b-2));

      if(m>g)
        OF<<"IMPOSSIBLE\n";
      else
      {
        OF<<"POSSIBLE\n";
        long long diff = g-m;

        int arr[100]={0};
        int j=0;

        while(diff)
        {
            arr[j++]=diff%2;
            diff/=2;
        }

        for(i=0;i<b;i++)
        {
          for(j=0;j<b;j++)
             {
              if(i<j)
                 mat[i][j]=1;
             }
        }



        int ctr=b-2;

        for(i=0;i<j;i++)
        {
           if(arr[i]==1)
           {
              mat[0][ctr]=0;
           }
           ctr--;

        }

        for(i=0;i<b;i++)
        {
          for(j=0;j<b;j++)
              OF<<mat[i][j];
            OF<<endl;


        }




      }





      

    }

    OF.close();
    IF.close();
}
