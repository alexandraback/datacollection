#include <stdio.h>
#include <set>
#include <cstring>

using namespace std;

int main(){
	int tc,num, n;
	scanf("%d",&tc);
	for(int k=1; k<=tc; k++){
		set<int> appeared;
		int h[2502];
		memset(h,0,sizeof h);
		scanf("%d",&n);
		int lines = 2*n-1;
		while(lines--){
			for(int i=0; i<n; i++){
				scanf("%d",&num);
				//printf("%d\n",num );
				appeared.insert(num);
				h[num]++;
			}
		}
		printf("Case #%d:", k);
		for (set<int>::iterator it=appeared.begin(); it!=appeared.end(); it++){
			if(h[*it]%2!=0) printf(" %d",*it);
			//printf("%d\n",*it );
		}
		printf("\n");

	}
}