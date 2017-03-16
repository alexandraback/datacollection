#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string s;
int ans;

bool record[110][2][110];

void dfs(int i, int current_state, int cost){
  if (cost>ans || record[i][current_state][cost])
    return;

  record[i][current_state][cost]=1;

  if (i==s.size()){
    if (current_state==0)
      ans=cost;
    return;
  }

  int coin=0;
  if (s[i]=='-')
    coin=1;

  if (current_state != coin){
    dfs(i+1, 1-current_state, cost+1);
    dfs(i+1, current_state, cost+2);
  }else{
    dfs(i+1, current_state, cost);
    dfs(i+1, 1-current_state, cost+1);
  }
}

int main(){
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);

  int T;
  cin>>T;
  for(int tt=0; tt<T; tt++){
    printf("Case #%d: ",tt+1);

    memset(record, 0, sizeof record);
    cin>>s;

    ans=s.size();

    int cost_up=0, cost_down=0;
    if (s[0]=='+')
      cost_down=1;
    else
      cost_up=1;

    dfs(1, 0, cost_up);
    dfs(1, 1, cost_down);

    cout<<ans<<endl;
  }

  return 0;
}
