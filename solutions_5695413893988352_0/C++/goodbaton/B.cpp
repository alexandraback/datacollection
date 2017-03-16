#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 10000

void solve(){
  char c[20], j[20], c2[20], j2[20];
  vector<int> vec;

  scanf("%s%s",c,j);

  int lc = strlen(c);
  int lj = strlen(j);
  
  for(int i=0;i<(int)(pow(10,lj));i++){
    char order[20];
    sprintf(order,"%%0%dd",lj);
    sprintf(j2,order,i);

    bool flag = true;
    for(int k=0;k<lj;k++){
      if(j[k]!=j2[k] && j[k]!='?') flag = false;
    }

    if(flag) vec.push_back(i);
  }

  sort(vec.begin(),vec.end());

  int ans_c,ans_j,min_d = INF;
  
  for(int i=0;i<(int)(pow(10,lc));i++){
    char order[20];
    sprintf(order,"%%0%dd",lc);
    sprintf(c2,order,i);

    bool flag = true;
    for(int k=0;k<lc;k++){
      if(c[k]!=c2[k] && c[k]!='?') flag = false;
    }

    if(flag){
      auto it = lower_bound(vec.begin(),vec.end(),i);

	if(it != vec.begin()){
	  it--;
	  if(min_d > abs(*it-i)){
	    min_d = abs(*it-i);
	    ans_j = *it;
	    ans_c = i;
	  }
	  it++;
	}
	
	if(it != vec.end()){
	  if(min_d > abs(*it-i)){
	    min_d = abs(*it-i);
	    ans_j = *it;
	    ans_c = i;
	  }
	}
    }
  }

  char order[20];
  sprintf(order,"%%0%dd %%0%dd\n",lc,lj);
  printf(order,ans_c,ans_j);
}


int main(){
  int T;

  scanf("%d",&T);

  for(int i=1;i<=T;i++){

    printf("Case #%d: ",i);

    solve();
  }
  
  return 0;
}
