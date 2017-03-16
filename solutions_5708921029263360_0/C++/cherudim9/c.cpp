#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

int J, P, S, K;
int ans_num;
int store_S[1010];

int main(){

  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);

  int T;
  cin>>T;
  for(int tt=1; tt<=T; tt++){
    printf("Case #%d: ",tt);
    
    cin>>J>>P>>S>>K;
    
    if (K>S)
      K=S;

    cout<<J*P*K<<endl;
    
    store_S[0]=0;
    for(int s=1; s<P; s++)
      store_S[s]=(store_S[s-1]+K)%S;
    for(int j=0; j<J; j++)
      for(int p=0; p<P; p++)
        for(int s=0; s<K; s++){
          cout << j+1 << " " << p+1 << " " << store_S[p]+1 << endl;
          store_S[p] = (store_S[p] + 1) % S;
        }
  }
  
  return 0;
}
