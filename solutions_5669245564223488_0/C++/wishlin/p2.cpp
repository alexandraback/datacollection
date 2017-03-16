#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int cas, N, ind;
int used[200];
int cntsame[26];
long long ans;
string arr[200];
string res;

char st(const string& s) {return s[0];}
char ed(const string& s) {return s[s.size()-1];}

long long fac(long long x) {
  if (x==1) return 1;
  else return (x*fac(x-1))%1000000007;
}

int sol0() {
  int cnt=0;
  for (int i=0; i<N; ++i) if (!used[i]) {
    for (int j=0; j<N; ++j) if (i!=j && !used[j] && st(arr[j])==ed(arr[j])) {
      if (ed(arr[i])==st(arr[j])) {
        arr[i]+=arr[j]; used[j]=1; ++cnt;
      }
    }
  }
  return cnt;
}

int sol() {
  int cnt=0;
  for (int i=0; i<N; ++i) if (!used[i]) {
    for (int j=0; j<N; ++j) if (i!=j && !used[j]) {
      if (ed(arr[i])==st(arr[j])) {
        arr[i]+=arr[j]; used[j]=1; ++cnt;
      }
    }
  }
  return cnt;
}

void cal() {
  int flg[1000]={0};
  ans=0;
  for (int i=0; i<res.size(); ++i) {
    if (!flg[res[i]]) {
      flg[res[i]]=1;
      while (i+1<res.size() && res[i]==res[i+1]) ++i;
    }
    else return;
  }
  ans=fac(ind);
  for (int i=0; i<26; ++i) {
    if (cntsame[i])
      ans=(ans*fac(cntsame[i]))%1000000007;
  }
}

int main() {
  scanf("%d",&cas);
  for (int k=1; k<=cas; ++k) {
    scanf("%d",&N);
    for (int i=0; i<26; ++i) {
      cntsame[i]=0;
    }
    for (int i=0; i<N; ++i) {
      cin>>arr[i]; used[i]=0;
      if (st(arr[i])==ed(arr[i])) {
        ++cntsame[st(arr[i])-'a'];
      }
    }
    while (sol0());
    while (sol());
    ind=0; res="";
    for (int i=0; i<N; ++i) if (!used[i]) {
      ++ind; res+=arr[i];
    }
    cal();
    printf("Case #%d: %lld\n",k,ans);
  }
  return 0;
}
