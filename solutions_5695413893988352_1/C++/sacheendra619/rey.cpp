
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

int main() {
  int cs = 0;
  freopen("inp.in","r",stdin);
  freopen("out.out","w",stdout);
  int t;
  cin >> t;
  while(t--) {
    string s1,s2;
    cin >> s1 >> s2;
    int pos = 0;
    long long num1 =0;
    long long num2 = 0;
    for(int i = 0 ; i < s1.size();i++) {
      if(s1[i] == '?' && s2[i] == '?') {
	s1[i] = '0'; s2[i]='0';
	num1 = num1*10;
	num2 = num2*10;
	continue;
      }
      if(s1[i]!='?' || s2[i]!='?') {
	pos = i;
	break;
      }
    }
    for(int i = pos ; i <s1.size();i++) {
      if(s1[i]=='?' && s2[i]!='?') {
	num1 = num1*10;
	num2 = num2*10;
	s1[i] = s2[i];
	continue;
      }
      if(s2[i] == '?' && s1[i]!='?') {
	s2[i] = s1[i];
	continue;
      }
      else if(s1[i] == '?' && s2[i] =='?') {
	if(num1<=num2) {
	  s1[i] = '9';
	  s2[i] = '0';
	  num1 = num1*10+9;
	  num2 = num2*10+0;
	}
	else {
	  s1[i] = '0';
	  s2[i] = '9';
	  num1 = num1*10;
	  num2 = num2*10+0;
	}
      }
    }
    printf("Case #%d: ",++cs);
    cout<<s1<<" "<<s2<<endl;
  }
}
