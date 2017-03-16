#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

#define MX 4040

char S[MX];
char W[530500][100];
int wn;

pair<int,int> dp[MX];

pair<int,int> check(int a,int b,int c){
	int n=strlen(W[b]);
	int last=dp[a].second,vys=dp[a].first;
	for(int i=0;i<n;++i){
		if (S[a+i]!=W[b][i]){
			if (a+i-last<5) return make_pair(-1,0);
			vys++;
			last=a+i;
		}
	}
	return make_pair(vys,last);
}

int main()
{
	FILE *f=fopen("garbled_email_dictionary.txt","r");
	while(fscanf(f,"%s",W[wn])>0) ++wn;
	int T;
	scanf("%d\n",&T);
	for(int t=1;t<=T;++t){
		printf("Case #%d: ",t);
		scanf("%s",S);
		int n=strlen(S);
		for(int i=0;i<=n;++i){
			dp[i]=make_pair(-1,0);
		}
		dp[0]=make_pair(0,-10);
		for(int i=0;i<n;++i){
			if (dp[i].first!=-1){
				for(int j=0;j<wn;++j){
					pair<int,int> x=check(i,j,dp[i].second);
					if (x.first!=-1){
						//if (x.first<2)
						//	printf("%d %s %d %d\n",i,W[j],x.first,x.second);
						int n2=strlen(W[j]);
						if (dp[i+n2].first==-1||dp[i+n2]>x)
							dp[i+n2]=x;
					}
				}
			}
			/*for(int j=0;j<=n;++j){
				printf("(%2d %2d) ",dp[j].first,dp[j].second);
			}
			puts("");*/
		}
		printf("%d\n",dp[n].first);
	}
	return 0;
}
