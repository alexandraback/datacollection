#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MODV 1000000007

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi; 
void domod(int &a, ll b){a=(a+b)%MODV;}

void doit() {
  char s[1005];
  int n;
  scanf("%s", s);
  n=strlen(s);
  string res="";
  res+=s[0];
  for(int i=1;i<n;i++){
    if(s[i]>=res[0]){
      res = s[i] + res;
    }else res = res + s[i];
  }
  cout<<res;

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
