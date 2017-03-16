#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

long long a[105];
int main(){
  freopen("1.in","r",stdin);
  freopen("1.txt","w",stdout);
  int i, tt, c, d, v; 
  scanf("%d",&tt);
  for(int cas = 1; cas <= tt; ++cas){
    printf("Case #%d: ", cas);
    scanf("%d%d%d",&c,&d,&v);
    for(i=1;i<=d;++i) 
      cin >> a[i];
    sort(a+1,a+d+1);
    
    
    long long now=0;
    long long ans=0;
    for(i=1;i<=d&&now<v;++i){
      while(now+1 < a[i] && now < v){
        ans ++;
        now+=(now+1)*c;
      }
      now+=a[i]*c;
    }
    while(now<v){
      ans++;
      now+=(now+1)*c;
    }
    cout << ans << endl;
  }
  return 0;
}
