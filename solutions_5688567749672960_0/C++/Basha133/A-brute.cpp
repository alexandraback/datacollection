#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#define mp(a,b) make_pair((a),(b))
#define ff first
#define ss second

using namespace std;

int mini(int a, int b){
  if(a<=b){
    return a;
  }else{
    return b;
  }
}

int rev(int n){
  int i,j,k;
  vector<int> dig,rdig;
  
  for(k=n;k>0;k/=10){
    dig.push_back(k%10);
  }
  
  j=0;
  
  for(i=0;i<dig.size();i++){
    j*=10;
    j+=dig[i];
  }
  
  for(k=j;k>0;k/=10){
    rdig.push_back(k%10);
  }
  
  if(rdig.size()!=dig.size() || j==n){
    return -1;
  }
  
  return j;
}

int mincount(int n, vector<int> &seen){
  if(seen[n]!=-1){
    //printf("found %d: %d\n",n,seen[n]);
    return seen[n];
  }
  if(rev(n)<n && rev(n)!=-1){
    seen[n] = mini(mincount(n-1,seen),mincount(rev(n),seen))+1;
  }else{
    seen[n] = mincount(n-1,seen)+1;
  }
  //printf("new  %d: %d\n",n,seen[n]);
  return seen[n];
}


int main(){
  int i,j,k,l,m,n,t,T;
  vector<int> seen;
  
  scanf("%d",&T);
  
  for(t=0;t<T;t++){
    scanf("%d",&n);
    //printf("%d\n",rev(n));
    
    seen.resize(n+1,-1);
    seen[0] = 0;
    
    k=mincount(n,seen);
    
    //for(i=0;i<n;i++){printf("seen[%d] == %d\n",i,seen[i]);}
    
    printf("Case #%d: %d\n",t+1,k);
  }
    
  return 0;
}