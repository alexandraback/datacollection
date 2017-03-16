#include <cstdio>
#include <cstring>

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cases;
	scanf("%d",&cases);
	int n,i,sum,s[201];
	for(int casenum=1;casenum<=cases;casenum++){
		scanf("%d",&n);
		sum=0;
		for(i=0;i<n;i++){
			scanf("%d",&s[i]);
			sum+=s[i];
		}
		printf("Case #%d: ",casenum);
		for(i=0;i<n;i++){
			double ans=.5;
			double d=.25;
			for(int z=0;z<300;z++,d/=2){
				int b=1;
				double Y=ans;
				double G=s[i]+ans*sum;
				for(int j=0;j<n;j++){
					if(i==j)continue;
					if(G>s[j])Y+=(G-s[j])/sum;
					if(Y>1.0){
						b=0;
						break;
					}
				}
				if(b)ans+=d;
				else ans-=d;
			}

			printf("%.12lf",ans*100);
			if(i<n-1)printf(" ");
			else puts("");
		}
	}
	return 0;
}