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


int main()
{
  int T;
  cin>>T;
  int cnt=1;
  while(T){
    int R,C,W;
    cin>>R>>C>>W;
    int ans=ceil((double)C/W)+W-1;
    ans*=R;
    printf("Case #%d: %d\n",cnt,ans);
    T--;cnt++;
  }

  
  return 0;
}
