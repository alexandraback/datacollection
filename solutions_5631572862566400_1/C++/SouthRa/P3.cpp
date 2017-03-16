#include<cstdio>
#include<vector>

using namespace std;

int love[1005];
bool cnt[1005];
int ko[1005];

vector<int> k;

void init()
{
	int i, j;
	for(i=0;i<1003;i++){
		cnt[i]=0;
		ko[i]=0;
	}
	k.clear();
}

int circle_detect(int a)
{
	bool used[1005];
	vector<int> v;
	int i, tmp, ans;
	for(i=0;i<1003;i++) used[i]=0;
	used[a]=1;
	ans=1;
	v.push_back(a);
	tmp=love[a];
	while(tmp!=a){
		if(used[tmp]){
			break;
		}
		v.push_back(tmp);
		used[tmp]=1;
		tmp=love[tmp];
		ans++;
	}
	if(tmp==a&&v.size()>2){
		for(i=0;i<v.size();i++) cnt[v[i]]=1;
		return ans;
	}
	else return -1;
}

int chain_detect(int a)
{
	int tmp=a, ans=1, i;
	bool used[1005];
	for(i=0;i<1003;i++) used[i]=0;
	while(love[love[tmp]]!=tmp){
		if(used[tmp]) break;
		used[tmp]=1;
		tmp=love[tmp];
		ans++;
	}
	if(love[love[tmp]]==tmp){
		if(ko[tmp]==0){
			ko[tmp]=ans;
			k.push_back(tmp);
		}
		else if(ko[tmp]<ans) ko[tmp]=ans;
	}
	else ans=-1;
	return ans;
}

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int t, n, cases, i, j, tmp, ans;
	int circle_max, chain_max;
	scanf("%d",&t);
	for(cases=1;cases<=t;cases++){
		scanf("%d", &n);
		circle_max=0;
		chain_max=0;
		init();
		for(i=1;i<=n;i++){
			scanf("%d", &tmp);
			love[i]=tmp;
		}
		for(i=1;i<=n;i++){
			if(cnt[i]==1) continue;
			tmp=circle_detect(i);
			if(tmp>circle_max) circle_max=tmp;
		}
		for(i=1;i<=n;i++){
			if(cnt[i]==1) continue;
			tmp=chain_detect(i);
		}
		for(j=0;j<k.size();j++) chain_max+=ko[k[j]];
		if(circle_max>chain_max) ans=circle_max;
		else ans=chain_max;
		printf("Case #%d: %d\n", cases, ans);
	}
	return 0;
}
