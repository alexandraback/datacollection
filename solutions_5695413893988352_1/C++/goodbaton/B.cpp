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

vector<pair<int,int> > calc(string A,string B){
  vector<int> vec;
  vector<pair<int,int> > res(5,{-1,-1});

  int min_a = INF,max_a = 0,min_b = INF,max_b = 0;
  
  for(int i=0;i<1000;i++){
    char order[20], a2[20];
    sprintf(order,"%%0%dd",3);
    sprintf(a2,order,i);

    bool flag = true;
    for(int k=0;k<3;k++){
      if(A[k]!=a2[k] && A[k]!='?') flag = false;
    }

    if(flag){
      vec.push_back(i);
      min_a = min(min_a,i);
      max_a = max(max_a,i);
    }
  }
  
  int min_d[3] = {INF,INF,INF};
  
  for(int i=0;i<1000;i++){
    char order[20], b2[20];
    sprintf(order,"%%0%dd",3);
    sprintf(b2,order,i);
    
    bool flag = true;
    for(int k=0;k<3;k++){
      if(B[k]!=b2[k] && B[k]!='?') flag = false;
    }
    
    if(flag){
      min_b = min(min_b,i);
      max_b = max(max_b,i);
      
      auto it = lower_bound(vec.begin(),vec.end(),i);
      //<-
      
      if(it != vec.begin()){
	it--;
	if(min_d[0] > abs(*it-i)){
	  min_d[0] = abs(*it-i);
	  res[0] = {i,*it};
	}
	it++;
      }

      if(*it == i){
	if(it != vec.end()){
	  if(min_d[1] > abs(*it-i)){
	    min_d[1] = abs(*it-i);
	    res[1] = {i,*it};
	  }
	  it++;
	}
      }

      if(it != vec.end()){
	if(min_d[2] > abs(*it-i)){
	  min_d[2] = abs(*it-i);
	  res[2] = {i,*it};
	}
	it++;
      }
    }
  }

  res[3] = {min_b,max_a};
  res[4] = {max_b,min_a};
  
  return res;
}

void solve(){
  string C,J;
  vector<int> vec;

  cin >> C >> J;

  int l = C.size();

  for(int i=l;i<18;i++){
    C = "0" + C;
    J = "0" + J;
  }


  vector<pair<int,int> > res_a = calc(C.substr(0,6), J.substr(0,6));
  vector<pair<int,int> > res_b = calc(C.substr(3,6), J.substr(3,6));
  vector<pair<int,int> > res_c = calc(C.substr(6,6), J.substr(6,6));
  vector<pair<int,int> > res_d = calc(C.substr(9,6), J.substr(9,6));
  vector<pair<int,int> > res_e = calc(C.substr(12,6),J.substr(12,6));
  vector<pair<int,int> > res_f = calc(C.substr(15,6),J.substr(15,6));

  ll ans_c,ans_j,diff = LLINF;
  
  for(int i=0;i<5;i++){
    if(res_a[i].first==-1) continue;
    for(int j=0;j<5;j++){
      if(res_b[j].first==-1) continue;
      for(int k=0;k<5;k++){
	if(res_c[k].first==-1) continue;
	for(int i2=0;i2<5;i2++){
	  if(res_d[i2].first==-1) continue;
	  for(int j2=0;j2<5;j2++){
	    if(res_e[j2].first==-1) continue;
	    for(int k2=0;k2<5;k2++){
	      if(res_f[k2].first==-1) continue;
	
	      ll p1 = 1000000000000000LL;
	      ll p2 = 1000000000000LL;
	      ll p3 = 1000000000LL;
	      ll p4 = 1000000LL;
	      ll p5 = 1000LL;
	      
	      ll a =
		res_a[i].first * p1  + res_b[j].first * p2  + res_c[k].first * p3 +
		res_d[i2].first * p4 + res_e[j2].first * p5  + res_f[k2].first;
	      ll b =
		res_a[i].second * p1 + res_b[j].second * p2 + res_c[k].second * p3 +
		res_d[i2].second * p4 + res_e[j2].second * p5 + res_f[k2].second;
	      
	      if(diff > abs(a-b) || (diff == abs(a-b) && ans_c>a) ||
		 (diff == abs(a-b) && ans_c==a && ans_j > b)){
		diff = abs(a-b);
		ans_c = b;
		ans_j = a;
	      }
	    }
	  }
	}
      }
    }
  }
  

  char order[20];
  sprintf(order,"%%0%dlld %%0%dlld\n",l,l);
  printf(order,ans_c,ans_j);
}


int main(){
  int T;

  scanf("%d",&T);

  for(int i=1;i<=T;i++){

    fprintf(stderr,"Case #%d\n",i);
    printf("Case #%d: ",i);

    solve();
  }
  
  return 0;
}
