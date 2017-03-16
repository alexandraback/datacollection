#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[20];

int main(){
  int jcase;
  int N;
  int A;
  int ct;
  int min, temp;
  
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);
  //freopen("A-large.in", "r", stdin);
  //freopen("A-large.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(int icase=0; icase<jcase; icase++){
    scanf("%d", &A);
    scanf("%d", &N);
    
    for(int i=0; i<N; i++) scanf("%d", &arr[i]);
    sort(arr, arr+N);
    
    min = N;
    temp = N;
    if(A > 1){
      for(int i=0; i<N; i++){
        while(A <= arr[i]){
          A *= 2;
          A--;
          temp++;
        }
        A += arr[i];
        temp--;
        if(temp < min) min = temp;
      }
    }
    printf("Case #%d: %d\n", icase+1, min);
  }
  return 0;
}
