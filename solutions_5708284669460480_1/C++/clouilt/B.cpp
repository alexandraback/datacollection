#include <iostream>
#include <cstdio>
using namespace std;

int next[103];
char master[103];
char keyboard[103];

double dp[103][103];

int T,K,L,S;

void make_fail(char* master, int len, int* next){
	int i=0;
	int j=-1;
	for(;i<len; ++i, ++j){
		next[i]=j;
		while(j!=-1 && master[i] != master [j])
			j=next[j];
	}
	next[i]=j;
}

int main(){
	cin>>T;
	int cnt[30];
	double p[30];
	for(int cs=1; cs<=T; ++cs){
		cin>>K>>L>>S;
		cin>>keyboard;
		cin>>master;
		make_fail(master, L, next);
	//	cout<<next[L]<<endl;
		int mx=(S-next[L])/(L-next[L]);

		memset(cnt, 0, sizeof(cnt));
		for(int i=0;i<K;++i){
			++cnt[keyboard[i]-'A'];
		}

		int flag=1;
		for(int i=0;i<L; ++i)
			if( !cnt[ master[i]-'A' ])
				flag=0;
		if(flag == 0)
			mx=0;


		for(int i=0;i<30;++i)
			p[i]=((double)cnt[i])/K;

		double res=0;
		memset(dp, 0, sizeof(dp));
		dp[0][0]=1;
		for(int i=1;i<=S;++i){
			dp[i][0]=1;
			for(int j=1; j<=L; ++j){
				dp[i][j]=dp[i-1][j-1]*p[master[j-1]-'A'];
			}
			res+=dp[i][L];
		}
	//	cout<<mx<<' '<<res<<endl;
	//	cout<<"Case #"<<cs<<": "<<(mx-res)<<endl;
		printf("Case #%d: %.7lf\n", cs, mx-res);
	}
	return 0;
}
