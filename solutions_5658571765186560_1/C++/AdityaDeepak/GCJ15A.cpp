// adijimmy
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
#define MAX 1005
int X,R,C;
ll power(ll a,ll b){
 ll res = 1;
 while(b){
	if(b&1) res = (res*a)%mod;
	a = (a*a)%mod;
	b >>= 1;
 }
 return res;
}
bool solve(){
   if((R*C)%X) return false;
	if(X==1 | X==2) return true;
	else if(X == 3){
	  if((R==1 && C==3) || (R==3 && C==1)) return false;
	  return true;
	}
	else{
		if((C*R <= 8)|| (R==2 | C==2)) return false;
		return true;
	}
}
int main(){
	int t;
	freopen("D-large.in","r",stdin);
	freopen("ans.txt","w",stdout);
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
	  scanf("%d %d %d",&X,&R,&C);
	  printf("Case #%d: ",cas);
	  bool flag = solve();
	  if(!flag) puts("RICHARD");
	  else puts("GABRIEL");
	}
	return 0;
}
