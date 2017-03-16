#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;
long powk(long n,long k);

int main(){
  long  j, k, i, l,m, A, B;
  long lay, num, C,N, M, T, S, p, score, flag;
  long lawn [100][100],rowmax[100],colmax[100];
  for (j=0;j<100;j++)
    for (k=0;k<100;k++)
      lawn[j][k]=0;
  
  cin >> T;
  j=0;
  k=0;
  
  for(i=0;i<T;i++){
    num=0;
    cout<<"Case #"<<i+1<<": ";
    cin >>N>>M;    
    for (j=0;j<N;j++)
      for (k=0;k<M;k++)
	cin>> lawn[j][k];
    for (j=0;j<N;j++)
      rowmax[j]=0;
    for (k=0;k<M;k++)
      colmax[k]=0;
    for (j=0;j<N;j++)
      for (k=0;k<M;k++){
	if (rowmax[j]<lawn[j][k])
	  rowmax[j]=lawn[j][k];
      }

    for (k=0;k<M;k++)
      for (j=0;j<N;j++){
	if (colmax[k]<lawn[j][k])
	  colmax[k]=lawn[j][k];
      }
    flag = 0;
    for (j=0;j<N;j++)
      for (k=0;k<M;k++){
	if (lawn[j][k]<colmax[k]&&lawn[j][k]<rowmax[j])
	  flag=1;
      }
    if (flag==0)
      cout <<"YES\n";
    else
      cout<<"NO\n";
  }	
  return 0;
}
