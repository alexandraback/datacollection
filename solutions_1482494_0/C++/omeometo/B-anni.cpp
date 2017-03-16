#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

pair<int,int> hoge[1010];

int a[2020];

main(){
	int casenum,totcase;
	scanf("%d",&totcase);
	for(int casenum=1;casenum<=totcase;casenum++){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&hoge[i].first,&hoge[i].second);
		}
		int ans=1010101010;
		for(int b=0;b<(1<<n);b++){
			vector<int> v;
			int tmp=2*n;
			for(int i=0;i<n;i++){
				if((b>>i)&1){
					v.push_back(hoge[i].second);
					tmp--;
				}else v.push_back(hoge[i].first);
				v.push_back(hoge[i].second);
			}
			sort(v.begin(),v.end());
			bool ok=true;
			for(int i=0;i<v.size();i++)if(v[i]>i)ok=false;
			if(ok)ans=min(ans,tmp);
		}
		if(ans==1010101010)printf("Case #%d: Too Bad\n",casenum);
		else printf("Case #%d: %d\n",casenum,ans);
	}
}