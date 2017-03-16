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
  long long ans;
  int a,b;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    ans = 0;
    cin >> a >> b;

    int len = 0,tmp = b;
    while(tmp>0){
      len++;
      tmp/=10;
    }

    int k = 1;
    for(int i=1;i<len;i++)k*=10;

    for(int m=b;m>=a;m--){
      int n=m;
      map<int,bool> num;
      for(int i=1;i<len;i++){
	tmp = n%10;
	n/=10;
	n += tmp*k;

	if(a<=n && n<m && !num[n]){
	  num[n] = true;
	  ans++;
	}
      }
    }	

    cout << "Case #" << casenum << ": ";
    cout << ans << endl;
  }
}
