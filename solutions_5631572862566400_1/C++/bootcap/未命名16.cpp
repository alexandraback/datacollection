#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

int num[1510],lab[1510],vis[1510];
int max_lab[1510];

int ans;
bool search(int x){
	if(lab[1] == 2 && lab[2] ==3 && lab[3]==4){
		printf("searching %d\n",x);
		getchar();
	}
	if(num[lab[x]] == lab[1]){
		ans = x;
		return true;
	}
	if(lab[1] == 2 && lab[2] ==3 && lab[3]==4){
		printf("ANS %d\n",ans);
	}
	if(num[lab[x]] == lab[x-1] || num[lab[x]] == lab[x+1]){
		if(search(x+1))
			return true;
		if(num[lab[x]] == lab[x-1]){
			ans = x;
			if(lab[1] == 2 && lab[2] ==3 && lab[3]==4 && x==3){
				printf("wtf?? %d\n",ans);
			}
			return true;
		}
	}
	return false;
}

int main(){
	freopen("C-large.in","r",stdin);
	freopen("A.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		for(int i=1;i<=n;i++)
			max_lab[i]=1;
		
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				vis[j]=0;
			int p=i,label=1;
			vis[p]=1;
			while(vis[num[p]]==0){
				p=num[p];label++;
				vis[p]=label;
			}
			ans = max(ans,label-vis[num[p]]+1);
			int end=num[p];p=i;
			while(p!=num[end]){
				max_lab[p]=max(max_lab[p],vis[p]);
				//printf("%d %d \n",p,max_lab[p]);
				p=num[p];
			}
			//printf("\n%d!!  %d\n",i,ans);
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			//printf("%d ",max_lab[i]);
			if(num[num[i]]==i)
				sum+=max_lab[i];
		}
		ans = max(ans,sum);
		//printf("\nsum!!! %d\n",sum);
		printf("Case #%d: %d\n",cas,ans);
		
		/*/
		for(int i=1;i<=n;i++)
			lab[i]=i;
		int final_ans=0;
		do{
			ans=0;
			//for(int j=1;j<=n;j++)
			//	cout<<lab[j]<<"  ";
			//cout<<endl;
			if(search(1))
				final_ans = max(final_ans,ans);
			//printf("%d!!!!",ans);
			if(lab[1] == 2 && lab[2] ==3 && lab[3]==4){
				printf("wtf?? %d\n",ans);
			}
		}while(next_permutation(lab+1,lab+1+n));
		//*/
	}
	return 0;
}
