#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<complex>
#include<map>
#include<list>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;

int main(){
  int testcase;
  int ans;
  int a,b;
  double p[100000];

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    cin >> a >> b;
    for(int i=0;i<a;i++)cin >> p[i];

    double ans = (double)(b+2);
    double cor = 1.0;
    for(int i=0;i<a;i++){
      ans = min(ans,cor*(a-i + b-i+1) + (1.0-cor)*(a-i + 2*b-i+2));
      cor *= p[i];
    }

    ans = min(ans,cor*(b-a+1)+(1.0-cor)*(2*b-a+2));

    cout << "Case #" << casenum << ": ";
    printf("%.6lf\n",ans);
  }
}
