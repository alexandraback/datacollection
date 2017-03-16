#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<functional>
#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const int MN = 20;

char buf1[MN],buf2[MN];
ll tp[MN];
pll ans;

ll mabs(ll a){
	if(a<0)return -a;
	return a;
}

void relax(pll cand){
	if(mabs(ans.first-ans.second)>mabs(cand.first-cand.second)){
		ans=cand;
		return;
	}
	if(mabs(ans.first-ans.second)==mabs(cand.first-cand.second) && (ans.first>cand.first || (ans.first==cand.first && ans.second>cand.second))){
		ans=cand;
		return;
	}
}
ll minv[MN][2];
ll maxv[MN][2];

void f(int n,ll prefix){
	if(n==-1){
		relax(pll(prefix,prefix));
		return;
	}
	int s1=0,s2=0,e1=9,e2=9;
	if(buf1[n]!='?')s1=e1=buf1[n]-'0';
	if(buf2[n]!='?')s2=e2=buf2[n]-'0';
	bool sflag=false;
	for(int d1=s1;d1<=e1;d1++)for(int d2=s2;d2<=e2;d2++){
		ll a=prefix+d1*tp[n];
		ll b=prefix+d2*tp[n];
		if(d1<d2){
			if(n>0)	relax(pll(a+maxv[n-1][0],b+minv[n-1][1]));
			else relax(pll(a,b));
		}
		else if(d1>d2){
			if(n>0)	relax(pll(a+minv[n-1][0],b+maxv[n-1][1]));
			else relax(pll(a,b));
		}
		else if(!sflag){
			sflag=true;
			f(n-1,prefix+d1*tp[n]);
		}
	}
}

int dig(ll n){
	if(n<10)return 1;
	return dig(n/10)+1;
}

void print(int L,ll n){
	for(int rest=L-dig(n);rest>0;rest--)printf("0");
	printf("%lld",n);
}

int main(){
	freopen("B-small-attempt0.in","r",stdin),freopen("output.txt","w",stdout);
	tp[0]=1;
	for(int i=1;i<MN;i++)tp[i]=10*tp[i-1];
	
	II(T);
	for(int tc=1;tc<=T;tc++){
		ans=pll(1e18,0);
		scanf("%s%s",buf1,buf2);
		int L=strlen(buf1);
		reverse(buf1,buf1+L);
		reverse(buf2,buf2+L);
		for(int i=0;i<L;i++){
			if(i>0){
				minv[i][0]=minv[i-1][0];
				minv[i][1]=minv[i-1][1];
				maxv[i][0]=maxv[i-1][0];
				maxv[i][1]=maxv[i-1][1];
			}
			else{
				minv[i][0]=minv[i][1]=maxv[i][0]=maxv[i][1]=0;
			}

			if(buf1[i]=='?'){
				maxv[i][0]+=9*tp[i];
			}
			else{
				minv[i][0]+=(buf1[i]-'0')*tp[i];
				maxv[i][0]+=(buf1[i]-'0')*tp[i];
			}
			if(buf2[i]=='?'){
				maxv[i][1]+=9*tp[i];
			}
			else{
				minv[i][1]+=(buf2[i]-'0')*tp[i];
				maxv[i][1]+=(buf2[i]-'0')*tp[i];
			}
		}
		f(L-1,0);
		printf("Case #%d: ",tc);
		print(L,ans.first);
		printf(" ");
		print(L,ans.second);
		printf("\n");
	}
	return 0;
}