#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long> nr;
int is_pal(long long X){
	long long ax=X,Xr=0;
	while(ax){
		Xr=Xr*10+ax%10;
		ax/=10;
	}
	return Xr==X;
}
void preproc(){
	const long long L=1LL*10000000*10000000;
	for(long long i=1;i*i<=L;++i){
		if(is_pal(i)){
			if(is_pal(i*i))
				nr.push_back(i*i);
		}
	}
}
int main(){
	freopen("fair.in","r",stdin);
	freopen("fair.out","w",stdout);
	preproc();
	int T;
	long long A,B;
	scanf("%d",&T);
	for(int test=1;test<=T;++test){
		scanf("%lld%lld",&A,&B);
		printf("Case #%d: %d\n",test,upper_bound(nr.begin(),nr.end(),B)-lower_bound(nr.begin(),nr.end(),A));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
