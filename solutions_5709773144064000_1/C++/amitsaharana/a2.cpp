#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define gc getchar_unlocked
#define pc putchar_unlocked

#define eps 1e-10

int main() {  
  //ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  for(int z=0; z<t; z++) {
    cout<<"Case #"<<(z+1)<<": ";
    double c,f,x;
    cin>>c>>f>>x;
    double res = 1e18;
    int k = 1;
    double tot = 0.0;
    double ans = x/2.0;
    while(true) {
      tot = tot+c/(2.0+(k-1)*f);
      double temp = x/(2.0+k*f)+tot;
      if(temp>ans) break;
      else ans = temp;
      k++;
    }
    printf("%.9f\n",ans);
  }


  return 0;
}
