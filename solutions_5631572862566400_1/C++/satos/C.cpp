#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)

int n;
int gone[1005];
vector<int> vs[1005];
int bf[1005];

int gld(int no){
	gone[no]=1;
	int res = 0;
	rep(i,vs[no].size()){
		int to=vs[no][i];
		if(gone[to])continue;
		res = max(res,gld(to));
	}
	return res+1;
}

int ngo[1005];
int namo(int no){
	memset(ngo,0,sizeof(ngo));
	int d = 1;
	int res = -1;
	for(;;){
		if(ngo[no]){
			res = d - ngo[no];
			break;
		}
		ngo[no]=d;
		no = bf[no];
		d++;
	}
	
	gld(no);
	return res;
}

int solve(){
	memset(gone,0,sizeof(gone));
	memset(bf,0,sizeof(bf));
	rep(i,1005)vs[i] = vector<int>();
	
	rep(i,n){
		int a;
		scanf("%d",&a); a--;
		bf[i]=a; vs[a].push_back(i);
	}
	
	int ans = -1;
	{
		int na = 0;
		rep(i,n){
			if(bf[i]>i && bf[bf[i]]==i){
				gone[i]=gone[bf[i]]=1;
				na += gld(i) + gld(bf[i]);
			}
		}
		ans = max(ans,na);
	}
	
	{
		rep(i,n){
			if(gone[i])continue;
			ans = max(ans,namo(i));
		}
	}
	
	return ans;
}

int main(void){
	int qn;
	scanf("%d",&qn);
	reg(qqq,1,qn){
		printf("Case #%d: ",qqq);
		scanf("%d",&n);
		printf("%d\n",solve());
	}
	return 0;
}




