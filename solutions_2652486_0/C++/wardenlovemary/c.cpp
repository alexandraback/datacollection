#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int R,n,m,k;
int v[22];
vector<int>a,ans_v;

int chk(){
	int visd[1<<12],found[22],res=0;
	memset(visd,0,sizeof visd);
	memset(found,false,sizeof found);
	for(int mask=0;mask<(1<<n);mask++){
		int mul=1;
		for(int j=0;j<n;j++)
			if(mask&(1<<j))mul*=a[j];
		for(int j=0;j<k;j++)
			if(v[j]==mul){
				found[j]=true;
				visd[j]++;
				res++;
			}
	}
	for(int i=0;i<k;i++)
		if(!found[i])return -1;
	return res;
}

int main(){
	printf("Case #1:\n");
	scanf("%d",&R);
	scanf("%d%d%d%d",&R,&n,&m,&k);
	for(;R--;){
		for(int i=0;i<k;i++)
			scanf("%d",&v[i]);
		int ans=0;
		a.clear();ans_v.clear();
		a.resize(3);ans_v.resize(3);
		for(a[0]=2;a[0]<=5;a[0]++)
			for(a[1]=a[0];a[1]<=5;a[1]++)
				for(a[2]=a[1];a[2]<=5;a[2]++){
					int likelihood=chk();
					if(likelihood>ans){
						ans=likelihood;
						ans_v=a;
					}
				}
		for(int i=0;i<3;i++)
			printf("%d",ans_v[i]);
		printf("\n");
	}

	return 0;
}