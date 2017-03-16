#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

	int list[111],test,a,n,ans,c=1,i,temp;
	
	for( scanf("%d",&test) ; test-- ; printf("Case #%d: %d\n",c++,ans) ){
		scanf("%d%d",&a,&n);
		for( i=0 ; i<n ; i++ ) scanf("%d",&list[i]);
		sort(list,list+n);
		ans = 0;
		
		for( i=0 ; i<n && list[i]<a ; i++ ){
			a+=list[i];	
		}
		ans = n-i;
		if( a!=1 ){
			for( temp=1 ; i<n ; temp++ ){
				for( a+=a-1 ; i<n && list[i]<a ; i++ ){
					a+=list[i];	
				}
				ans = min(ans,temp+n-i);
			}	
		}
	}

	return 0;
}

