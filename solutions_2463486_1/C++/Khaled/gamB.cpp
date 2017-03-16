#include<stdio.h>
#include<vector>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAX 1000000000
#define pb push_back
typedef long long ll;
vector<ll> vc;

char s[20];
int check(ll n){

	sprintf(s,"%lld",n);
	int i=0,j=strlen(s)-1;
	
	while(i<j){
		if(s[i]!=s[j]) return 0;
		i++;
		j--;
	}
	
	return 1;
}

void gen(){
	ll p=10000000;
	//printf("%lld\n",p);
	ll i;
	//p=MAX;
	for(i=1;i<=p;i++){
		
		if(check(i) && check(i*i)) vc.pb(i);
	}
}

int main(){
	int t,i,k;
	ll x,y;
	freopen("C-large-1.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	gen();
//	for(i=0;i<vc.size();i++) printf("%lld ",vc[i]);
//	puts("");
	//t=0;
	for(k=1;k<=t;k++){
		scanf("%lld%lld",&x,&y);
		y = (ll)sqrt(y);
		x = (ll)ceil(sqrt(x));
		x = upper_bound(vc.begin(),vc.end(),y) - lower_bound(vc.begin(),vc.end(),x);
		
		printf("Case #%d: %lld\n",k,x);
	}
	return 0;
}
