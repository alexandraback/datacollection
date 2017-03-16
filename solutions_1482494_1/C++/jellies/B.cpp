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

int main(void){
	int casenum;
	scanf("%d",&casenum);
	for(int casecnt=1;casecnt<=casenum;casecnt++){

		int n;
		scanf("%d",&n);

		vector<int> one(n),two(n);
		for(int i=0;i<n;i++){
			scanf("%d %d",&one[i],&two[i]);
		}

		int stars=0;
		vector<int> goal(n);
		int ans=0;
		while(stars<2*n){
			bool changed=false;
			for(int i=0;i<n;i++){
				if(goal[i]==0 && two[i]<=stars){
					goal[i]=2;
					stars+=2;
					ans++;
					changed=true;
				}
				if(goal[i]==1 && two[i]<=stars){
					goal[i]=2;
					stars+=1;
					ans++;
					changed=true;
				}
			}
			if(changed)continue;

			int maxi=-1,maxipos=-1;
			for(int i=0;i<n;i++){
				if(goal[i]==0 && one[i]<=stars && stars<two[i]){
					if(maxi<two[i]){
						maxi=two[i];
						maxipos=i;
					}
				}
			}
			if(maxipos==-1)break;
			goal[maxipos]=1;
			stars++;
			ans++;
		}

		printf("Case #%d: ",casecnt);
		if(stars<2*n)printf("Too Bad\n");
		else printf("%d\n",ans);

		fflush(stdout);
	}
	return 0;
}
