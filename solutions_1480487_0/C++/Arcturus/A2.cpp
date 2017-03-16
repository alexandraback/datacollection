#include <stdio.h>
#include <limits.h>
#include <conio.h>
#include <algorithm>

using namespace std;
struct SS{
  int a;
  int idx;
};

bool f1(SS a, SS b){
  return a.a < b.a;
}
bool f2(SS a, SS b){
  return a.idx < b.idx;
}

int main(){
  int jcase;
  int N;
  SS arr[200];
  int sum, avg, sum2;
  double ans[200];
  int count[200];

  freopen("A-small-attempt2.in", "r", stdin);
  freopen("A-small-attempt2.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(int icase=0; icase<jcase; icase++){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
      scanf("%d", &arr[i].a);
      count[i] = 0;
      arr[i].idx = i;
    }
    sort(arr, arr+N, f1);
    
    sum = 0;
    for(int i=0; i<N; i++){
      sum += arr[i].a;
      count[i] = 0;
    }
    sum2 = sum;
    
    //for(int i=0; i<N; i++) printf("%d ", arr[i]);
    //puts("");
    
    int dif, num;
    while(1){
      for(int i=0; i<N; i++){
        if(i==N-1){
//          printf("i==%d\n", i);
          num = N;
          dif = sum/num;
          break;
        }
        else if(arr[i].a < arr[i+1].a){
//          printf("else i=%d\n",  i);
          dif = arr[i+1].a-arr[i].a;
          num = i+1;
          break;
        }
      }
//      printf("sum=%d dif=%d num=%d\n", sum, dif, num);
      if(sum < num*dif) dif = sum/num;
      sum -= num*dif;
      for(int j=0; j<num; j++){
        arr[j].a += dif;
        count[j]+= dif;
      }
      
      for(int i=0; i<N; i++){
        if(i==N-1) num = N;
        else if(arr[i].a < arr[i+1].a) num = i+1;
      }
      
      if(sum == num-1){
        for(int i=0; i<num; i++){
          arr[i].a++;
          count[i]++;
        }
      }
      if(sum < num) break;
    }
    for(int i=0; i<N; i++) arr[i].a = count[i];
    sort(arr, arr+N, f2);
    
    printf("Case #%d:", icase+1);
    for(int i=0; i<N; i++){
      printf("% lf", (double)arr[i].a*100.0/sum2);
    }
    puts("");
  }
  return 0;  
}
