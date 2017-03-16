#include <iostream>

using namespace std;

typedef long long ll;
ll a[1000005];

int main() {
  int tc, n;
  ll A, cur, best, sofar;
  cin>>tc;
  for(int t=1; t<=tc; t++) {
    cin>>A>>n;
    for(int i=0; i<n; i++)
      cin>>a[i];
    sort(a, a+n);
    cur = A;
    best = n; 
    sofar=0;
    if (A<=1 && a[0]>=1) {
      best = n;
    } else {
      for(int i=0; i<n;) {
        while(i<n && a[i]<cur) {
          cur += a[i];
          i++;
        }
        best = min(best, sofar+(n-i));
        cur += cur-1;
        sofar++;
      }
    }
    cout<<"Case #"<<t<<": "<<best<<endl;
  }
  return 0;
}
