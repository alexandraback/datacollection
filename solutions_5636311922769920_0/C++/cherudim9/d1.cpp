#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main(){
  freopen("d.in","r",stdin);
  freopen("d.out","w",stdout);

  int T;
  cin>>T;
  for(int tt=1; tt<=T; tt++){

    printf("Case #%d: ",tt);
    int k,c,s;
    cin>>k>>c>>s;
    if (s==k){
      for(int i=0; i<k; i++){
        long long now=i;
        for(int j=0; j<c-1; j++)
          now=now*k+i;
        now++;
        cout<<now<<" ";
      }
      printf("\n");
    }else{
      printf("???????\n");
    }
  }
  
  return 0;
}
