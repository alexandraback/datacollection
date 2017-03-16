#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#define mp(a,b) make_pair((a),(b))
#define ff first
#define ss second

using namespace std;

int main(){
  int i,j,l,r,t;
  int a,b,k;
  
  scanf("%d",&t);
  
  for(l=1;l<=t;l++){
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&k);
    
    r=0;
    
    for(i=0;i<a;i++){
      for(j=0;j<b;j++){
	if((i&j)<k){
	  r++;
	}
      }
    }
    
    printf("Case #%d: %d\n",l,r);
  }
  
  return 0;
}
