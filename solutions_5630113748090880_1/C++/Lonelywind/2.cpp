#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int tt;
	cin>>tt;

	int n,a[205][205];
	int cnt[2505];
	for (int cs=1;cs<=tt;cs++){
		printf("Case #%d:",cs);
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		//cerr<<"XXX: "<<sizeof(cnt)<<endl;
		for (int i=1;i<=2*n-1;i++){
			//idx[i]=i;
			for (int j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
				cnt[a[i][j]]++;
			}
		}
		vector<int> ans;
		for (int i=1;i<=2500;i++)
			if (cnt[i]%2==1) ans.push_back(i);
		sort(ans.begin(),ans.end());
		for (int i=0;i<ans.size();i++)
			printf(" %d",ans[i]);
		printf("\n");
	}

	return 0;
}