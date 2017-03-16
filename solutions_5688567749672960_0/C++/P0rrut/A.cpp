#include<bits/stdc++.h>
#define ri(X) scanf("%d",&X)
#define rii(X,Y) scanf("%d %d",&X,&Y)
#define rf(X) scanf("%lf",&X)
#define rff(X,Y) scanf("%lf %lf",&X,&Y)
#define mp(X,Y) make_pair(X,Y)
#define pii pair<int,int>
#define FOR(i,j) for(int i=0;i<j;i++)
#define FORC(i,j,c) for(int i=0;i<j;i+=c)

using namespace std;
int T;

long long N;
vector<long long >v,c;
const long long mn = 1000000000000000LL;

void init(){
  long long tmp = 9LL;
  while(tmp<mn){
    v.push_back(tmp);
    tmp*=10LL;
    tmp+=9LL;
    c.push_back(0LL);
  }
  long long t1,t2;
  t1 = 9LL;
  c[0]=t1;
  FOR(i,v.size()){
    if(!i) continue;
    if(i%2==0){
      t1*=10LL;
      t1+=9LL;
    }
    if(i%2){
      c[i] = c[i-1]+t1+t1+1LL;
    }
    else{
      c[i]= c[i-1]+t1+t1/10+1LL;
    }
   // c[i]--;
  }
  
  //FOR(i,c.size()) cout << v[i] << " " << c[i] << endl;
}

long long rev(long long t1){
  long long ret = 0LL;
  while(t1){
    ret*=10LL;
    ret+=t1%10LL;
    t1/=10LL;
  }
  return ret;
}

long long qk(long long val, int k){
  long long ret = 0LL;
  long long t1 = 1LL;
  while(k--){
    ret+=t1*(val%10);
    t1*=10LL;
    val/=10;
  }
  return ret;
}

long long calc(long long val, long long vk){
  long long tmp = val;
  int tt = 0;
  long long v1,v2,v3,v4;
  long long pp = 1LL;
  while(tmp){
    tmp/=10LL;
    pp*=10LL;
    tt++;
  }
  v2 = qk(N,tt/2);
  v1 = val-v2;
  //cout << val << " " << vk << endl;
  long long mini = val-vk;
  if(v1==pp) mini = min(v2,mini);
   // cout << v1 << " " << v2 << endl;
  v1 = rev(v1);
  if(v2)
    mini = min(mini,v1+v2);
    
  if(v2%10LL)
    mini = min(v1-1LL+v2+2LL,mini);
//  cout << mini << endl;
  if(tt%2){

    v2 = qk(N,tt/2+1);
    v1 = val-v2;
    if(v1==pp) mini = min(v2,mini);
    v1 = rev(v1);
    if(v2)
      mini = min(mini,v1+v2);
    if(v2%10LL)
      mini = min(v1-1LL+v2+2LL,mini);
  }
  
  
  return mini;
}

long long memo[(int)1e6+10];
void cc(){
  memo[1]=1LL;
  for(int i=2;i<1e6+10;i++){
    memo[i]=memo[i-1]+1LL;
    if(rev(i)<i && rev(rev(i))==i){
      memo[i] = min(memo[i],1LL+memo[rev(i)]);
    }
  }
  
}
int main(){
  cin >> T;
  init();
  //cc();

  FOR(t,T){
    printf("Case #%d: ",t+1);
    cin >> N;
    long long tot = 0LL;
    int idx = 0;
    while(v[idx]<N){
      idx++;
    }
    idx--;
    if(idx<0){
      tot=N;
    }
    else{
      tot=c[idx]+1;
      tot+=calc(N,v[idx]+1);
    }
    printf("%lld\n",tot);
  }


	return 0;
}
