#include <cstdio>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

int t[1001];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cases,n,i,j;
	scanf("%d",&cases);
	for(int casenum=1;casenum<=cases;casenum++){
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d",&t[i]);
		int sum=0;
		for(i=0;i<n;i++)sum+=t[i];
		map<int,vector<int> > m;
		for(i=1;i<(1<<n);i++){
			sum=0;
			for(j=0;j<n;j++)if(i&(1<<j))sum+=t[j];
			m[sum].push_back(i);
		}
		printf("Case #%d:\n",casenum);
		int f=0;
		for(map<int,vector<int> >::iterator it=m.begin(),ite=m.end();it!=ite && f==0;it++){
			int sz=it->second.size();
			for(i=0;i<sz && f==0;i++)
				for(j=i+1;j<sz && f==0;j++){
					if((it->second[i]&it->second[j])==0){
						for(int k=0;k<n;k++)if(it->second[i]&(1<<k))printf("%d ",t[k]);
						puts("");
						for(int k=0;k<n;k++)if(it->second[j]&(1<<k))printf("%d ",t[k]);
						puts("");
						f=1;
					}
				}
		}
		if(!f)puts("Impossible");
	}
	return 0;
}