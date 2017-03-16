#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int N=16;
const int J=50;
const unsigned long long maxP=100000+1000;
vector<unsigned long long> p;
unsigned long long min_div[maxP+10];
int nPrime=0;

int a[100];
int ans[200][200];

unsigned long long testIt(int base){
  unsigned long long now=0;
  for(int i=0; i<N; i++)
    now = now * (unsigned long long) base + (unsigned long long) a[i];
  for(int i=1; i<=nPrime; i++)
    if (now % p[i] == 0 && now>p[i])
      return p[i];
  return 0;
}

bool equal(int j){
  for(int i=0; i<N; i++)
    if (a[i]!=ans[j][i])
      return 0;
  return 1;
}

int main(){
  
  p.resize(maxP);
  for(unsigned long long i=2; i <= maxP; i++){
    if (min_div[i]==0){
      p[++nPrime]=i;
    }
    for(int j=1; j<=nPrime; j++){
      unsigned long long x = i * p[j];
      if ( x > maxP )
        break;
      min_div[x]=p[j];
      if (i % p[j]==0)
        break;
    }
  }

  freopen("c.out","w",stdout);

  printf("Case #1:\n");

  for(int jj=0; jj<J; jj++){
    a[0]=1;
    a[N-1]=1;

    while(1){
      for(int i=1; i<N-1; i++)
        a[i]=rand()%2;

      bool flag=true;
      for(int i=2; i<=10; i++)
        if (testIt(i)==0)
          flag=false;
      
      for(int j=0; j<jj; j++)
        if (equal(j))
          flag=false;
      
      if (flag)
          break;

    }

    for(int i=0; i<N; i++)
      cout<<a[i];
    cout<<" ";
    for(int i=2; i<=10; i++)
      cout<<testIt(i)<<" ";
    cout<<endl;

    for(int i=0; i<N; i++)
      ans[jj][i]=a[i];
  }

  return 0;
}
