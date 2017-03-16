#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair


typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi; 

void doit() {
  int *cnt;
  cnt=new int[2502]();
  int n;
  scanf("%d", &n);
  for(auto i=0;i<(2*n-1);i++){
    int t;
    for(auto j=0;j<n;j++){
    scanf("%d", &t);
    cnt[t]++;
    }
  }
  for(auto i=1;i<2501;i++)
  if(cnt[i]&1){
    printf("%d ",i);
  }
}

int main() {
  int tc;
  scanf("%d",&tc);
  for(int i=1;i<=tc;i++){
    printf("Case #%d: ",i);
    doit();
    cout<<endl;
  }
  return 0;
}
