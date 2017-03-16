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

#define MAX 2100000

int n;
int val[100];
vector<int> data[MAX];

int main(void){
	int casenum;
	scanf("%d",&casenum);
	for(int casecnt=1;casecnt<=casenum;casecnt++){

		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&val[i]);

		for(int i=0;i<MAX;i++)data[i].clear();

		for(int i=0;i<(1<<n);i++){
			int sum=0;
			for(int j=0;j<n;j++){
				if((i&(1<<j))!=0)sum+=val[j];
			}
			data[sum].push_back(i);
		}

		printf("Case #%d:\n",casecnt);

		bool ok=false;
		vector<int> ans[2];
		for(int i=0;i<MAX;i++){
			if(data[i].size()<2)continue;

			ok=true;

			int a=data[i][0];
			int b=data[i][1];

			for(int j=0;j<n;j++){
				if((a&(1<<j))!=0 && (b&(1<<j))!=0){
					a^=(1<<j);
					b^=(1<<j);
				}
			}

			for(int j=0;j<n;j++){
				if((a&(1<<j))!=0)ans[0].push_back(val[j]);
			}
			for(int j=0;j<n;j++){
				if((b&(1<<j))!=0)ans[1].push_back(val[j]);
			}
			break;
		}

		if(ok){
			for(int i=0;i<2;i++){
				for(int j=0;j<ans[i].size();j++){
					printf("%d%c",ans[i][j],j+1==ans[i].size()?'\n':' ');
				}
			}
		}else{
			printf("Impossible\n");
		}

		fflush(stdout);
	}
	return 0;
}
