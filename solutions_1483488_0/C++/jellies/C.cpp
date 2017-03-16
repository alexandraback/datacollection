#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<complex>
#define EPS (1e-10)
#define PI (3.141592653589793238)
#define MP make_pair
typedef long long ll;
using namespace std;

int a,b;
int dig,keta;

int doit(int n){
	vector<int> ans;

	int now=n;
	for(int i=1;i<keta;i++){
		int top=now/dig;
		int left=now%dig;
		now=left*10+top;
		if(n<now && now<=b)ans.push_back(now);
	}

	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());

	return ans.size();
}

int main(void){
	int casenum;
	scanf("%d",&casenum);
	for(int casecnt=1;casecnt<=casenum;casecnt++){

		scanf("%d %d",&a,&b);
		dig=1;keta=1;
		while(1){
			if(a<dig*10)break;
			dig*=10;
			keta++;
		}

		int ans=0;
		for(int i=a;i<=b;i++){
			ans+=doit(i);
		}

		printf("Case #%d: %d\n",casecnt,ans);
		fflush(stdout);
	}
	return 0;
}
