#include<bits/stdc++.h>
using namespace std;
int noOfBits(long long int m)
{
  int count=0;
  while(m)
  {
    count++;
    m>>=1;
  }
  return count;
}
int main()
{
  int t;
  cin>>t;
  for(int gh=1;gh<=t;gh++)
  {
        int b;

        long long int m;
        cin>>b>>m;
        bool matrix[b][b];
        memset(matrix,0,b*b*sizeof(bool));
        int get1 = noOfBits(m-1);
        int get2 = noOfBits(m);
        long long int temp=m;
        if(get1<=(b-2))
        {
          cout<<"Case #"<<gh<<": "<<"POSSIBLE"<<endl;
          int start = b - 2 - get2 + 1;
            for(int i=start;i<b;i++)
            {
                for(int j=i+1;j<b;j++)
                  matrix[i][j]=1;
            }
            if(get1==get2)
            {
               for(int i=b-2;i>=1;i--)
               {
                 int bitValue = (int) temp&1;
                 if(bitValue)
                 {
                   matrix[0][i]=1;
                 }
                 temp>>=1;
               }
            }
            if(start!=0)
              matrix[0][start]=1;
            for(int i=0;i<b;i++)
            {
              for(int j=0;j<b;j++)
              {
                if(matrix[i][j])
                  cout<<"1";
                else
                  cout<<"0";
              }
              cout<<endl;
            }

        }
        else
        {
          cout<<"Case #"<<gh<<": "<<"IMPOSSIBLE"<<endl;
        }


  }
  return 0;
}
