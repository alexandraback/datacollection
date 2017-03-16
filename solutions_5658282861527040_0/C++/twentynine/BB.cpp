#include<iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
int main(){
	freopen("B-small-attempt0 (1).in","r",stdin); 
	freopen("B-small-attempt0 (1).out","w",stdout);
	int ii,tc;
	scanf("%d",&tc);
	for(ii=1;ii<=tc;ii++){
		int n,m,k,i,j,ans=0;
		scanf("%d %d %d",&n,&m,&k);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				//printf("%d %d  %d\n",i,j,i&j);
				if((i&j)<k)ans++;
			}
		}
		printf("Case #%d: %d\n",ii,ans);
	}
				
				
		
		
		
         
             
         
         
	
	return 0;
}
