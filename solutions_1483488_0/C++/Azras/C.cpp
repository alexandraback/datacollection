#include <cstdio>
#include <set>
#include <algorithm>
#define F first
#define S second
using namespace std;
int arr[100];
int main(){
  int t;
  scanf("%d",&t);
  for(int p=1; p<=t; p++){
    set<pair<int, int> > all;
    int a,b;
    scanf("%d %d", &a, &b);
    for(int i=a;i<=b;i++){
      int dig=0;
      int temp=i;
      while(temp){
        arr[dig]=temp%10;
        dig++;
        temp/=10;
      }
      reverse(arr,arr+dig);
      for(int st=1;st<dig;st++){
        int next=0;
        for(int j=st;j<dig;j++){
          next*=10;
          next+=arr[j];
        }
        for(int j=0;j<st;j++){
          next*=10;
          next+=arr[j];
        }
        if(next>=a && next<=b && next>i) all.insert(make_pair(i,next));
      }
    }
    printf("Case #%d: %d\n",p,all.size());
  }
  return 0;
}
