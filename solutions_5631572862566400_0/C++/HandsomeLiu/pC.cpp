#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	freopen("inputC","r",stdin);
	freopen("outputC","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		printf("Case #%d: ",t);
		int n;
		scanf("%d",&n);
		int f[n];
		int in[n];
		for(int i=0;i<n;i++)in[i]=0;
		for(int i=0;i<n;i++){
			scanf("%d",&f[i]);
			f[i]--;
			in[f[i]]++;
		}
		int num_two_cycle=0;
		int idx_two_cycle[n];
		bool is_two_cycle[n];
		for(int i=0;i<n;i++){
			is_two_cycle[i]=false;
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(f[i]==j&&f[j]==i){
					is_two_cycle[i]=is_two_cycle[j]=true;
					idx_two_cycle[i]=idx_two_cycle[j]=num_two_cycle;
					num_two_cycle++;
				}
			}
		}
		int num[n];
		for(int i=0;i<n;i++){
			num[i]=0;
			if(is_two_cycle[i])num[i]=1;
		}
		for(int i=0;i<n;i++){
			if(is_two_cycle[i])continue;
			if(in[i]==0){
				bool vst[n];
				for(int j=0;j<n;j++)vst[j]=false;
				int len=0;
				int tmp=i;
				while(vst[tmp]==false){
					vst[tmp]=true;
					len++;
					if(is_two_cycle[tmp]){
						num[tmp]=max(num[tmp],len);
						break;
					}
					tmp=f[tmp];
				}
			}
		}
		for(int i=0;i<n;i++){
			if(!is_two_cycle[i]){
				bool vst[n];
				for(int j=0;j<n;j++)vst[j]=false;
				int tmp=f[i];
				int len=1;
				while(tmp!=i&&vst[tmp]==false){
					vst[tmp]=true;
					tmp=f[tmp];
					len++;
				}
				if(tmp==i)num[i]=len;
			}
		}
		int ans=0;
		for(int i=0;i<n;i++)if(is_two_cycle[i])ans+=num[i];
		for(int i=0;i<n;i++)ans=max(ans,num[i]);
		printf("%d\n",ans);
	}
}
