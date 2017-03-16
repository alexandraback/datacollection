#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

int R,n,m,k;
long long v[22],ans,count=0;
vector<int>a,ans_v,rec[22222];
map<long long int,int> mp[22222];
map<long long int,int>::iterator it;

int chk(){
	int found[22],res=0;
	memset(found,false,sizeof found);
	
	long long x=1;
	for(int i=0;i<n;i++)
		x*=a[i];
	
	for(int mask=0;mask<(1<<n);mask++){
		long long mul=1;
		for(int j=0;j<n;j++)
			if(mask&(1<<j))mul*=a[j];
		for(int j=0;j<k;j++)
			if(v[j]==mul){
				found[j]=true;
				res++;
			}
	}
	for(int i=0;i<k;i++)
		if(!found[i])return -1;
	return res;
}

void record(){
	rec[count]=a;
	for(int i=0;i<(1<<n);i++){
		long long mul=1;
		for(int j=0;j<n;j++)
			if(i&(1<<j))mul*=a[j];
		it=mp[count].find(mul);
		if(it==mp[count].end())mp[count][mul]=1;
		else (*it).second++;
	}
}

void dfs(int dep,int last){
	if(dep==12){
		record();
		count++;
		return;
	}
	for(int i=last;i<=8;i++){
		a[dep]=i;
		dfs(dep+1,i);
	}
}

int main(){
	for(int i=0;i<20000;i++)
		mp[i].clear();
	printf("Case #1:\n");
	scanf("%d",&R);
	scanf("%d%d%d%d",&R,&n,&m,&k);
	a.clear();a.resize(12);
	dfs(0,2);
	for(;R--;){
		for(int i=0;i<k;i++)
			scanf("%I64d",&v[i]);
		ans=0;
		ans_v.clear();ans_v.resize(12);
		for(int i=0;i<12;i++)
			ans_v[i]=2;
		
		for(int i=0;i<count;i++){
			//if(i>7500&&i<count-7500)continue;
			int likelihood=0;
			for(int j=0;j<k;j++){
				it=mp[i].find(v[j]);
				if(it==mp[i].end()){
					likelihood=-1;
					break;
				}
				likelihood+=(*it).second;
			}
			if(likelihood>ans){
				ans=likelihood;
				ans_v=rec[i];
			}
		}
		
		for(int i=0;i<12;i++)
			printf("%d",ans_v[i]);
		printf("\n");
	}

	return 0;
}