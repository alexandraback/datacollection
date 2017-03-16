#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#define mk make_pair
#define ps push_back
#define lw lower_bound
using namespace std;

int t,q[3000],at,n;

int main(){
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			for(int j=0;j<2*n-1;j++){
				scanf("%d",&at);
				q[at]++;
			}
		}
		printf("Case #%d: ",tt);
		for(int i=0;i<=2500;i++){
			if(q[i]%2==1){
				printf("%d ",i);
				q[i]++;
			}
		}
		printf("\n");
	}
	return 0;
}
