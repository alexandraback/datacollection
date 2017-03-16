#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
vector<int> fac[11];
int main(){
	int t,n,m,cnt=0;
	scanf("%d%d%d",&t,&n,&m);
	for(int i=0;i<(1<<14)&&ans.size()<m;i++){
		int tf[11];
		string now="1";
		for(int k=13;k>=0;k--){
			if(i&(1<<k)) now+="1";
			else now+="0";
		}
		now+="1";
		tf[0]=1;
		for(int j=2;j<=10;j++){
			long long r=j,tmp=1;
			for(int k=0;k<14;k++){
				if(i&(1<<k)){
					tmp+=r;
				}
				r*=j;
			}
			tmp+=r;
			tf[j]=0;
			if(tmp%2==0){
				tf[j]=2;
			}
			else{
				for(int k=3;1LL*k*k<=tmp;k+=2){
					if(tmp%k==0){
						tf[j]=k;
						break;
					}
				}
			}
			if(!tf[j]){
				tf[0]=0;
				break;
			}
		}
		if(tf[0]){
			ans.push_back(now);
			for(int j=2;j<=10;j++){
				fac[j].push_back(tf[j]);
			}
		}
	}
	puts("Case #1:");
	for(int i=0;i<m;i++){
		for(int j=0;j<n/16;j++){
			cout<<ans[i];
		}
		for(int j=2;j<=10;j++){
			printf(" %d",fac[j][i]);
		}
		puts("");
	}
	return 0;
}