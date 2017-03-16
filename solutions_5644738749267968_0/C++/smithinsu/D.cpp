#include<bits/stdc++.h>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LL long long
#define VI vector < int >
#define PII pair < int , int >

int getNum() {
  string str;
  cin>>str;
  str = str.substr(2,10);
  while(str.size() < 5) {
    str = str + '0';
  }
  int ret = 0;
  for(int i=0;i<5;i++) {
    ret = ret*10 + (str[i]-'0');
  }
  return ret;
}

int main() {
  int n, T, kase = 0, a[1024], b[1024];
  cin>>T;
  while(T--) {
    cin>>n;
    for(int i=0;i<n;i++) {
      a[i] = getNum();
    }
    for(int i=0;i<n;i++) {
      b[i] = getNum();
    }
    sort(a, a+n);
    sort(b, b+n);
    int ind = 0;
    int ans1 = 0, ans2 = 0;
    for(int i=0;i<n;i++) {
      while(ind < n && (!(a[i] < b[ind]))) {
        ind++;
      }
      if(ind >= n || a[i] > b[ind]) {
        ans1++;
      }
      ind++;
    }
    
    int ind1 = 0, ind2 = n-1;
    for(int i=0;i<n;i++) {
      if(a[i] > b[ind1]) {
        ans2++;
        ind1++;
      } else {
        ind2--;
      }
    }
    printf("Case #%d: %d %d\n",++kase, ans2, ans1);
  }
  return 0;
}
