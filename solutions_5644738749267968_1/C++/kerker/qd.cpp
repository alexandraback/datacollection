#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

double a[1005],b[1005];
int is[1005];

int main()
{
    freopen("D-large.in","r",stdin);
	//freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T;
	cin >> T;
	for(int t=0,N;t<T && cin >> N;t++){
		for(int i=0,x,y;i<N && scanf(" %lf",&a[i])==1;i++);
		for(int i=0,x,y;i<N && scanf(" %lf",&b[i])==1;i++)
		sort(a,a+N);
		sort(b,b+N);
		/*for(int i=0;i<N;i++)
			printf("%d %d\n",a[i],b[i]);
		printf("------------------\n");*/
		int ans1 = 0, ans2 = 0;
		memset(is,0,sizeof(is));
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(is[j]==1)	continue;
				//printf("b : %.2lf , a : %.2lf\n",b[j],a[i]);
				if(b[j]>a[i]){
					//printf("b > a\n\n");
					is[j] = 1;
					ans2++;
					break;
				}
			}
		}
		ans2 = N-ans2;
		int aed = N-1, bst = 0, bed = N-1;
		memset(is,0,sizeof(is));
		for(int i=0;i<=aed;i++){
			if(a[i]>b[bst]){
				ans1++;
				bst++;
			}else{
				bed--;
			}
		}
		printf("Case #%d: %d %d\n",t+1,ans1,ans2);
		
	}
    
    return 0;
}