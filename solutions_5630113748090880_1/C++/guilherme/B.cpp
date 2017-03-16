#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include<cassert>
using namespace std;
int tab[110][110];
int lis[110][110];
int foi[110];
int n;
int id;
/*void solve(int col){
  if(col==n)verify();
  if(col==0){
    pair<int,int> men = make_pair(9999,9999);
    for(int i=0;i<2*n-1;i++){
      men=min(men,make_pair(lis[i][0],i));
    }
    for(int i=0;i<n;i++){
      tab[0][i]=lis[men.second][i];
    }
    foi[men.second]=1;
  }
  else {
    bool found = false;
    for(int i=0;i<2*n-1;i++){
      if(foi[i]==0 && list[i][0]==tab[0][i]){
	
      }
    }
  }
  }*/
int cc [9999];
int ret[9999];
int main(){
  int tt;
  scanf("%d",&tt);
  for(int rr=1;rr<=tt;rr++){
    scanf("%d",&n);
    memset(cc,0,sizeof(cc));
    for(int i=0;i<2*n-1;i++){
      for(int j=0;j<n;j++){
	scanf("%d",&lis[i][j]);
	cc[lis[i][j]]++;
      }
    }
    int r=0;
    for(int i=0;i<9999;i++){
      if(cc[i]%2==1)ret[r++]=i;
    }
    assert(r==n);
    printf("Case #%d:",rr);
    for(int i=0;i<r;i++){
      printf(" %d",ret[i]);
    }
    printf("\n");
    //    solve(0);
  }
  return 0;
}
