#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>

using namespace std;

#define LL long long int 
#define PII pair<int,int> 
#define PB push_back
#define MP make_pair
#define INF 1000000000

vector<int> a;

int getsum(int mask){
	int cur=0,sum=0;
	while(mask){
		if((mask&1))
			sum+=a[cur];
		cur++;
		mask>>=1;
	}
	return sum;
}
void print(int mask){
	int cur=0,sum=0;
	while(mask){
		if((mask&1))
			printf("%d ",a[cur]);
		cur++;
		mask>>=1;
	}
	printf("\n");

}
vector<vector<int> > same;
int main(){
	int i,n,t,x,ts=1,j,k;;
	scanf("%d",&t);
	while(t--){
		same.clear();
		same.resize((1<<21));
		a.clear();
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			a.PB(x);
		}
		printf("Case #%d: \n",ts++);
		for(i=0;i<(1<<n);i++){
			same[getsum(i)].PB(i);
		}
		for(i=0;i<(1<<n);i++){
			for(j=0;j<same[i].size();j++){
				for(k=0;k<same[i].size();k++){
					if((same[i][j]&same[i][k])==0 && i!=0 && j!=0){
						print(same[i][j]);
						print(same[i][k]);
						goto end;
					}
				}
			}
		}
end:;
	}
	return 0;
}
