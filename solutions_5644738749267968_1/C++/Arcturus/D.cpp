#include <stdio.h>
#include <algorithm>

using namespace std;

double arr1[1010], arr2[1010];

int main(){
  int jcase;
  int N;
  int ans1, ans2;
  
  freopen("D-large.in", "r", stdin);
  freopen("D-large.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(int icase=0; icase<jcase; icase++){
    ans1 = ans2 = 0;
    
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%lf", &arr1[i]);
    for(int i=0; i<N; i++) scanf("%lf", &arr2[i]);
    sort(arr1, arr1+N);
    sort(arr2, arr2+N);
    arr2[N] = 10;
    
    int ct=0;
    for(int i=0; i<N; i++){
      if(arr1[i] > arr2[ct]){
        ans2++;
        ct++;
      }
    }
    
    ct = 0;
    for(int i=0; i<N; i++){
      while(arr2[ct] < arr1[i]){
        ct++;
      }
      ct++;
      if(ct > N){ 
        ct = N;
        ans1++;
      }
    }
    
    printf("Case #%d: %d %d\n", icase+1, ans2, ans1);
  }
  return 0;
}
