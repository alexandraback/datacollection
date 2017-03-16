#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int arr[2505];
vector<int> v;
int main(){
  int t, n, a;
  scanf("%d",&t);
  for(int i = 0; i < t; i++){
    v.clear();
    scanf("%d",&n);
    memset(arr, 0, sizeof(arr));
    for(int j = 0; j < 2*n-1; j++){
      for(int k = 0; k < n; k++){
        scanf("%d", &a);
        arr[a]++;
      }
    }
    for(int j = 0; j < 2501; j++){
      if(arr[j]&1){
        v.push_back(j);
      }
    }
    sort(v.begin(), v.end());
    printf("Case #%d: ", i+1);
    for(int j = 0; j < v.size(); j++){
      printf("%d ", v[j]);
    }
    printf("\n");
  }
}
