#include<bits/stdc++.h>
using namespace std;

int maxcount(int *A,int N)
{
  int count = 0;
    int maxCount = 0;
  for(int i=1;i<=N;i++)
  {
    int cur = A[i],first = i;
    vector<bool> visited(N+1,false);
    count = 0;
    while(cur != first && !visited[cur])
    {
      visited[cur] = true;
      cur = A[cur];
      count++;
    }
    cout<<count<<" ";
    maxCount = max(maxCount,count);
  }
  return maxCount;
}


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
    int A[N+1];
    for(int i=1;i<=N;i++)
        cin>>A[i];
    cout<<maxcount(A,N)<<endl;

  }
  
  return 0;
}