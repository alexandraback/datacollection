#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
#define mem(a) memset(a,0,sizeof(a))
#define pd(a) printf("%.10f\n",a)
#define pb(a) push_back(a)
#define in(a) insert(a)
#define pi M_PI
#define R cin>>
#define F first
#define S second
#define C class
#define ll long long
#define ln cout<<'\n'
#define _(_1,_2,_3,N,...)N
#define pr(...) _(__VA_ARGS__,pr3,pr2,pr1)(__VA_ARGS__)
template<C T>void pr1(T a){cout<<a;ln;}
template<C T,C T2>void pr2(T a,T2 b){cout<<a<<' '<<b;ln;}
template<C T,C T2,C T3>void pr3(T a,T2 b,T3 c){cout<<a<<' '<<b<<' '<<c;ln;}
template<C T>void PR(T a,int n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}
bool check(int n,int m,int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1000000007,MAXL=1LL<<60,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<int,int> P;

void Main() {
  string a[10]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
  int T;
  R T;
  REP(tt,1,T+1) {
    cout << "Case #" << tt << ": ";
    string s;
    R s;
    int c[26];
    mem(c);
    rep(i,s.size()) c[s[i]-'A']++;
    string t="";
    while(c['Z'-'A']) {
      bool f=1;
      rep(i,a[0].size()) if(!c[a[0][i]-'A']) f=0;
      if(!f) break;
      rep(i,a[0].size()) c[a[0][i]-'A']--;
      t+='0';
    }
    while(c['W'-'A']) {
      bool f=1;
      rep(i,a[2].size()) if(!c[a[2][i]-'A']) f=0;
      if(!f) break;
      rep(i,a[2].size()) c[a[2][i]-'A']--;
      t+='2';
    }
    while(c['U'-'A']) {
      bool f=1;
      rep(i,a[4].size()) if(!c[a[4][i]-'A']) f=0;
      if(!f) break;
      rep(i,a[4].size()) c[a[4][i]-'A']--;
      t+='4';
    }
    while(c['X'-'A']) {
      bool f=1;
      rep(i,a[6].size()) if(!c[a[6][i]-'A']) f=0;
      if(!f) break;
      rep(i,a[6].size()) c[a[6][i]-'A']--;
      t+='6';
    }
    while(c['V'-'A']) {
      bool f=1;
      rep(i,a[7].size()) if(!c[a[7][i]-'A']) f=0;
      if(c['E'-'A']<2) f=0;
      if(!f) break;
      rep(i,a[7].size()) c[a[7][i]-'A']--;
      t+='7';
    }
    while(c['G'-'A']) {
      bool f=1;
      rep(i,a[8].size()) if(!c[a[8][i]-'A']) f=0;
      if(!f) break;
      rep(i,a[8].size()) c[a[8][i]-'A']--;
      t+='8';
    }
    while(c['H'-'A']) {
      bool f=1;
      rep(i,a[3].size()) if(!c[a[3][i]-'A']) f=0;
      if(c['E'-'A']<2) f=0;
      if(!f) break;
      rep(i,a[3].size()) c[a[3][i]-'A']--;
      t+='3';
    }
    while(c['O'-'A']) {
      bool f=1;
      rep(i,a[1].size()) if(!c[a[1][i]-'A']) f=0;
      if(!f) break;
      rep(i,a[1].size()) c[a[1][i]-'A']--;
      t+='1';
    }
    while(c['F'-'A']) {
      bool f=1;
      rep(i,a[5].size()) if(!c[a[5][i]-'A']) f=0;
      if(!f) break;
      rep(i,a[5].size()) c[a[5][i]-'A']--;
      t+='5';
    }
    while(c['N'-'A']) {
      bool f=1;
      rep(i,a[9].size()) if(!c[a[9][i]-'A']) f=0;
      if(c['N'-'A']<2) f=0;
      if(!f) break;
      rep(i,a[9].size()) c[a[9][i]-'A']--;
      t+='9';
    }
    sort(all(t));
    pr(t);
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  Main();return 0;
}
