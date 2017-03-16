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
        int J,P,S,K;
        cin>>J>>P>>S>>K;
        int answer = J * P * min(K,S);
        cout<<"Case #"<<gh<<": "<<answer<<endl;
        for(int i=1;i<=J;i++)
        {
          for(int j=1;j<=P;j++)
          {
            for(int k=1;k<=min(K,S);k++)
            {
              cout<<i<<" "<<j<<" "<<k<<endl;
            }
          }
        }

   }
  return 0;
}
