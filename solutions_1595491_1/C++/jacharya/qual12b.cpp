#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;
long powk(long n,long k);

int main(){
  long  j, k, i, l,m, A, B;
  long lay, num, C,N, T, S, p, score;
  cin >> T;
  j=0;
  for(i=0;i<T;i++){
    num=0;
    cout<<"Case #"<<i+1<<": ";
    cin >>N>>S>>p;
    
    for (j=0;j<N;j++)
    {
      cin>> score;
      if (p==0)
	num++;
      if (p==1&&score>=1)
	num++;
      if (p>1){
	if (score>3*(p-1))
	  num++;
	if (score==3*(p-1)&&S>0)
	{
	  num++;
	  S--;
	}
	if (score==3*(p-1)-1&&S>0)
	{
	  num++;
	  S--;
	}
      } 
  }
  cout <<num<<"\n";
  }	
  return 0;
}