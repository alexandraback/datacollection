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
  int n,a[1010],b[1010];
  bool v[1010][2];

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    cin >> n;
    for(int i=0;i<n;i++){
      cin >> a[i] >> b[i];
      v[i][0] = v[i][1] = false;
    }

    int step = -1;
    int star = 0;
    for(;;){ 
      step++;
      int num = -1;
      for(int i=0;i<n;i++){
	if(!v[i][1] && b[i]<=star)num = i;
      }
 
      if(0<=num){
	if(v[num][0]){
	  star += 1;
	  v[num][1] = true;
	}else{
	  star += 2;
	  v[num][0] = v[num][1] = true;
	}
	continue;
      }
      
      for(int i=0;i<n;i++){
	if(!v[i][0] && a[i]<=star && (num<0 || b[num]<b[i]))num = i;
      }

      if(0<=num){
	star += 1;
	v[num][0] = true;
	continue;
      }
      break;
    }

    bool f = true;
    for(int i=0;i<n;i++)f &= v[i][0] & v[i][1];

    cout << "Case #" << casenum << ": ";
    if(f)cout << step << endl;
    else cout << "Too Bad\n";
  }
}
