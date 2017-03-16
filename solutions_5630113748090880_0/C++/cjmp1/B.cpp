#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ans;
int chk[2555];
int main(){
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  int T; scanf("%d",&T);
  for(int i1 = 1 ; i1 <= T; i1++){
    ans.clear();
    printf("Case #%d: ",i1);
    int N; scanf("%d",&N);
    for(int i = 1; i <= 2*N-1; i++){
      for(int j =  1; j <= N; j++){
        int a;
        scanf("%d",&a);
        chk[a]++;
      }
    }
    for(int i = 1; i <= 2500; i++){
      if(chk[i]%2 == 1){
        ans.push_back(i);
      }
      chk[i] = 0;
    }
    sort(ans.begin(),ans.end());
    for(int i =0; i < ans.size(); i++){
      printf("%d ",ans[i]);
    }
    printf("\n");
  }
  return 0;
}