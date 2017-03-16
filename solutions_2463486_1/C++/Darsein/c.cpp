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

#define all(a) (a).begin(),(a).end()
using namespace std;

typedef long long ll;

vector<ll> ps;
ll a,b,ans;

void check(string s){
  stringstream ss,ss2;
  ss << s; ll num; ss >> num;

  num *= num; ss2 << num;
  s = ss2.str();

  bool f = true;
  for(int i=0;i<s.size();i++){
    if(s[i] != s[s.size()-1-i]){
      f = false; break;
    }
  }
  if(f)ps.push_back(num);
}

void rec(int l,int n,string s){
  if(2*l>=n){
    if(n&1)l--;
    for(int i=l-1;i>=0;i--)s += s[i];
    check(s); return;
  }

  for(int i=0;i<10;i++){
    if(l==0 && i==0)continue;
    s += (char)('0'+i);
    rec(l+1,n,s);
    s.erase(s.end()-1);
  }
}

int main(){
  int testcase;
  for(int i=1;i<=7;i++)rec(0,i,"");

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    cin >> a >> b;
    int ans = upper_bound(all(ps),b) - lower_bound(all(ps),a);
    cout << "Case #" << casenum << ": ";
    cout << ans << endl;
  }
}
