#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<complex>
#define EPS (1e-10)
#define PI (3.141592653589793238)
#define MP make_pair
typedef long long ll;
using namespace std;

ll mypow(ll a,ll b){
	ll ans=1;
	for(int i=0;i<b;i++)ans*=a;
	return ans;
}

vector<ll> zensum(const vector<ll> &ve){
	vector<ll> ans;
	int n=ve.size();
	for(int i=0;i<(1<<n);i++){
		ll sum=0;
		for(int j=0;j<n;j++){
			if((i&(1<<j))!=0)sum+=ve[j];
		}
		ans.push_back(sum);
	}
	return ans;
}

vector<ll> choice(const vector<ll> &ve,vector<bool> &old_check,vector<bool> &new_check,int num){
	int n=ve.size();
	vector<ll> ans;
	new_check.clear();
	new_check.resize(n);
	while(ans.size()<num){
		int p=rand()%n;
		if(old_check[p])continue;
		if(new_check[p])continue;
		new_check[p]=true;
		ans.push_back(ve[p]);
	}
	return ans;
}

int main(void){

	srand(765);

	int casenum;
	scanf("%d",&casenum);
	for(int casecnt=1;casecnt<=casenum;casecnt++){

		int n;
		vector<ll> val;

		scanf("%d",&n);
		for(int i=0;i<n;i++){
			ll v;
			scanf("%lld",&v);
			val.push_back(v);
		}

		int num=20;

		vector<bool> fai(n);

		vector<ll> ansa,ansb;
		hajimata:
		while(1){
			vector<bool> check;
			vector<ll> a=choice(val,fai,check,num);
			vector<ll> asum=zensum(a);
			map<ll,int> ma;
			for(int i=0;i<asum.size();i++){
				if(asum[i]==0)continue;
				ma[asum[i]]=i;
			}

			for(int t=0;t<100;t++){
				vector<bool> tmp;
				vector<ll> b=choice(val,check,tmp,num);
				vector<ll> bsum=zensum(b);
				for(int j=0;j<bsum.size();j++){
					if(bsum[j]==0)continue;
					if(ma.count(bsum[j])!=0){
						int i=ma[bsum[j]];
						for(int k=0;k<a.size();k++){
							if((i&(1<<k))!=0)ansa.push_back(a[k]);
						}
						for(int k=0;k<b.size();k++){
							if((j&(1<<k))!=0)ansb.push_back(b[k]);
						}
						for(int p=0;p<ansa.size();p++)for(int q=0;q<ansb.size();q++){
							if(ansa[p]==ansb[q]){
								printf("oh!\n");
								ansa.clear();
								ansb.clear();
								goto hajimata;
							}
						}
						goto owata;
					}
				}
			}
		}
		owata:

		printf("Case #%d:\n",casecnt);
		for(int i=0;i<ansa.size();i++){
			printf("%lld%c",ansa[i],i+1==ansa.size()?'\n':' ');
		}
		for(int i=0;i<ansb.size();i++){
			printf("%lld%c",ansb[i],i+1==ansb.size()?'\n':' ');
		}
		fflush(stdout);
	}
	return 0;
}
