#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
 freopen("B-small-attempt0 (1).in","r",stdin);
 freopen("B-small-attempt0 (1).out","w",stdout);
 int tes;
 scanf("%d",&tes);
 for(int tcase=1;tcase<=tes;tcase++){
	 int a,b,k;
	 
	 scanf("%d%d%d",&a,&b,&k);
	 
	 int ans = 0;
	 for(int i=0;i<a;i++){
	    for(int j=0;j<b;j++){
		    if((i&j) < k) ans++;		
		 }		
	 }
	 
	 printf("Case #%d: %d\n",tcase,ans);
 }
 
 fclose(stdin);
 fclose(stdout);
// system("pause");
 return 0;	
}
