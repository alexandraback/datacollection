#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<cmath>
#include<cassert>
#include<map>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long i64;typedef i64 int64;
typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)


void rec(int n,int sum,const vector<int> &coin,vector<bool> &flg){
  if(n==coin.size())return;
  
  if(sum<=30)
    flg[sum]=true;
  if(sum+coin[n]<=30)
    flg[sum+coin[n]]=true;
  rec(n+1,sum,coin,flg);
  rec(n+1,sum+coin[n],coin,flg);
}

int main()
{
  int T;
  cin>>T;
  int cnt=1;
  while(T){
    int C,D,V;
    cin>>C>>D>>V;
    vector<int> coin(D);
    rep(i,D)cin>>coin[i];
    
    vector<bool> flg(31,false);
    flg[0]=true;
    rec(0,0,coin,flg);

    rep(i,V+1){
      //      cout<<"t "<<i<<" "<<flg[i]<<endl;
    }
    
    int ans=0;
    rep(i,V+1){
      if(flg[i]==false){
        ans++;//iを足す
        for(int j=V;j>=i;j--)if(flg[j-i])flg[j]=true;
      }
    }
    
    printf("Case #%d: %d\n",cnt,ans);
    T--;cnt++;
  }



  
  return 0;
}
