#include<bits/stdc++.h>
using namespace std;
int A[3000];
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int T,count = 1;
  cin>>T;
  int N,num;
  while(T--)
  {
    cout<<"Case #"<<count++<<": ";
    cin>>N;
    memset(A,0,sizeof(A));
    for(int i=0;i<2*N-1;i++)
    {
      for(int j=0;j<N;j++)
      {
        cin>>num;
        A[num]++;
      }
    }
    for(int i=1;i<=2500;i++)
    {
      if(A[i]%2)
      {
        cout<<i<<" ";
        N--;
        if(N == 0)
            cout<<endl;
      }
    }


  }
  
  return 0;
}