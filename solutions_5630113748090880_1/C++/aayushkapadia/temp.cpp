#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  for(int gh=1;gh<=t;gh++)
  {
    int n;
    cin>>n;
    int heights[3001];
    memset(heights,0,sizeof(heights));
    for(int i=1;i<(2*n);i++)
    {
      for(int j=0;j<n;j++)
      {
        int temp;
        cin>>temp;
        heights[temp]++;
      }
    }
    cout<<"Case #"<<gh<<": ";
    for(int i=0;i<=3000;i++)
    {
      if((heights[i]%2)!=0)
      {
        cout<<i<<" ";
      }
    }
    cout<<endl;
  }
  return 0;
}
