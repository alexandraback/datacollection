#include<stdio.h>
#include<string.h>
#include<vector>
int k,n;
char s[100005];
int data[100005];
int tot[100005];
std::vector<int> list;

void solve()
{
	int i;
	long long ans=0;
	n=strlen(s+1);
	for(i=1;i<=n;i++){
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')data[i]=0;
		else data[i]=1;
	}
	for(i=1;i<=n;i++){
		if(data[i]==0)tot[i]=0;
		else tot[i]=tot[i-1]+1;
	}
	for(i=n;i>=1;i--)if(tot[i]>=k)list.push_back(i);
	for(i=1;i<=n;i++){
		if(list.empty())break;
		ans+=n-list.back()+1;
		if(list.back()==k+i-1)list.pop_back();
	}
	printf("%lld\n",ans);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,T;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%s%d",s+1,&k);
		printf("Case #%d: ",t);
		solve();
	}
}