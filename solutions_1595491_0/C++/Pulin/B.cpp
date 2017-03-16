#include<iostream>

using namespace std;

int main()
{
  int T;
  cin>>T;
  
  int N,S,p;
  int M[100];
  int count;

  for(int i=0;i<T;i++)
  {
    cin>>N;
    cin>>S;
    cin>>p;
    count=0;
    for(int j=0;j<N;j++)
      cin>>M[j];
    for(int j=0;j<N;j++)
    {
      if(M[j]>=(3*p-2))
      {
	count++;
      }
      else if(S>0 && ((M[j]==(3*p-3)||M[j]==(3*p-4))&&p!=1))
      {
	S--;
	count++;
      }
    }
    cout<<"Case #"<<i+1<<": "<<count<<"\n";
    
    
  }
  return 0;
  
}
