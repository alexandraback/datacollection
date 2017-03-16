#include <fstream>
#include <cstring>
#include<iostream>
#include <algorithm>
using namespace std;
double ken [1002];
double naomi [1002];
int main()
{
  ifstream f("input.txt");
  ofstream w("output.txt");
  int T;
  f>>T;
  
 
  for (int ti=1;ti<=T;ti++)
  {
    memset(ken,0,1002*sizeof(double));
    memset(naomi,0,1002*sizeof(double));
    int N;
    f>>N;
    for (int i=0;i<N;i++) f>>naomi[i];
    for (int i=0;i<N;i++) f>>ken[i];
    sort(naomi,naomi+N);
    sort(ken,ken+N);
    int war=0;
    int dwar=0;
    int j=0;
    for (int i=0;i<N;i++)
    {
      while (j<N&&ken[j]<naomi[i])j++;
      //cout<<ken[j]<<" "<<naomi[i]<<endl;
      if (j==N){
	war=N-i;
	break;
      }
      j++;
    }
    
    int nst=0;
    int nfs=N-1;
    int kst=0;
    int kfs=N-1;
    int loose=0;
    while (loose+dwar<N){
      if (ken[kst]>naomi[nst])
      {
	loose++;
	kfs--;
	nst++;
      } else{
	kst++;
	nst++;
	dwar++;
      }
    }
  
    
  
    w<<"Case #"<<ti<<": "<<dwar<<" "<<war<<endl; 
      
    
  }
  
  
  return 0;
}