#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int TT,l,r;
char s[5000],tp[5000];
map<int,int> nums;
vector<int> res;

int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&TT);
	for	(int T=1;T<=TT;++T){
		printf("Case #%d:",T);
		int n;
		scanf("%d",&n);
		nums.clear();
		for	(int i=1;i<=n*2-1;++i)
			for	(int j=1;j<=n;++j){
				int te;
				scanf("%d",&te);
				nums[te]++;
			}
		res.clear();
		for	(map<int,int>::iterator it=nums.begin();it!=nums.end();it++)
			if	((*it).second&1==1){
				res.push_back((*it).first);
			}
		sort(res.begin(),res.end());
		for	(int i=0;i<res.size();++i)	printf(" %d",res[i]);
		printf("\n");
	}
} 
