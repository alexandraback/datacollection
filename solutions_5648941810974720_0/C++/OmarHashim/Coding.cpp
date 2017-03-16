#include<bits/stdc++.h>
using namespace std;

#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define ll long long
#define lop(i,n) for(int i=0;i<n;++i)
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

int t,cnt[128],res[15];
string x;
string arr[]={"EROZ","NEO","TOW","HREET","FOUR","IVEF","SIX","EVENS","EIHTG","NNEI"};
int ord[]={0,6,7,8,2,3,4,5,1,9};

int main(){
#ifndef ONLINE_JUDGE
	freopen("i.txt","r",stdin);
	freopen("o.txt","w",stdout);
#endif
	cin>>t;
	lop(C,t){
		memset(cnt,0,sizeof cnt);
		memset(res,0,sizeof res);
		cin>>x;
		lop(i,x.size())++cnt[x[i]];
		lop(i,10){
			int num=ord[i];
			res[num]=cnt[arr[num][arr[num].size()-1]];
			lop(j,arr[num].size())cnt[arr[num][j]]-=res[num];
		}
		printf("Case #%d: ",C+1);
		lop(i,10)lop(j,res[i])printf("%d",i);
		puts("");
	}
};
