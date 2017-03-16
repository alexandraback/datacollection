#define DEB
#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }

typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fr<<','<<a.sc<<')';
    return out;
  }
}

const int INF=5e8;
char s[105];
int n;

void chk(int& len,int& sign,char s[105],int n){
  len=0;
  REP(i,n){
    int j=i;
    while(j<n && s[j]==s[i]) ++j;
    ++len;
    i=j-1;
  }
  sign=(s[0]=='+'?1:0);
}
int dp[105][2];
int rec(int len,int sign){
  int& res=dp[len][sign];
  if(~res) return res;
  if(len==1 && sign==1) return res=0;
  res=INF;
  REP(j,len){
    REP(i,len) s[i]=((sign^(i&1))?'+':'-');
    reverse(s,s+j+1);
    REP(k,j+1) s[k]=(s[k]=='+'?'-':'+');

    int len2,sign2;
    chk(len2,sign2,s,len);
    chmin(res,rec(len2,sign2)+1);
  }
  return res;
}
int main(){
  memset(dp,-1,sizeof(dp));
  int t;cin>>t;
  REP(setn,t){
    scanf("%s",s);
    n=strlen(s);
    int len,sign;
    chk(len,sign,s,n);

    int res=rec(len,sign);
    printf("Case #%d: %d\n",setn+1,res);
  }
  return 0;
}



