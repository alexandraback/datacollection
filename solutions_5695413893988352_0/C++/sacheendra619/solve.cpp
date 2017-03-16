
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi  vector<int>
#define pb  push_back
#define mp  make_pair
#define ALL(x) x.begin(),x.end()
#define M(a,x) memset(a,x,sizeof(a))
#define sci(x) scanf("%d",&x);
#define scl(x) scanf("%lld",&x);
#define scs(x) scanf("%s",x);
#define print(x) printf("%d",x);
#define nl printf("\n")
#define fr first
#define se second
#define printl(x) printf("%lld",x)
#define F(i,a,n) for(int i=a;i<n;i++)
#define INF 100000000000000000LL
#define LL long long

const int N = 1e5+5;
string s1,s2;
vector<string> v1,v2;
void gen(int pos,string s,vector<string> &v) {
  if(pos == s.size()) {
    v.pb(s);
    return ;
  }
  if(s[pos] == '?') {
    for(int j=0;j<=9;j++) {
      s[pos] = j+'0';
      gen(pos+1,s,v);
    }
  }
  else {
    gen(pos+1,s,v);
  }
}
int func(string temp1, string temp2) {
  int num1 = 0;
  int num2 = 0;
  for(int i = 0 ; i <temp1.size();i++) {
    num1= num1*10+(temp1[i]-'0');
  }
  for(int i = 0 ; i<temp2.size();i++) {
    num2 = num2*10+(temp2[i]-'0');
  }
  return abs(num1-num2);
}
int main() {
  freopen("Read.in","r",stdin);
  freopen("OUT.out","w",stdout);
  int cs = 0;
  int t;sci(t);
  while(t--) {
    v1.clear();
    v2.clear();
    cin >> s1 >> s2;
    gen(0,s1,v1);
    gen(0,s2,v2);
    int ans = MOD;
    string ans1,ans2;
    for(int i = 0;i<v1.size();i++) {
      for(int j=0;j<v2.size();j++) {
	int temp = func(v1[i],v2[j]);
	if(temp<ans) {
	  ans = temp;
	  ans1 = v1[i];
	  ans2 = v2[j];
	}
	else if(temp == ans) {
	  if(v1[i]<ans1) {
	    ans1 = v1[i];
	    ans2 = v2[j];
	  }
	  else if(v1[i] == ans1) {
	    if(v2[j]<ans2) {
	      ans2 = v2[j];
	    }
	  }
	}
      }
    }
    printf("Case #%d: ",++cs);
    cout<<ans1<<" "<<ans2<<endl;
  }
}
