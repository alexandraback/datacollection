#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int T,R,C,W;

int main(){
	scanf("%d",&T);
	for(int caso=1;caso<=T;caso++){
		scanf("%d %d %d",&R,&C,&W);
		int resp=(R-1)*(C/W) + (C/W) + W;
		if(C%W == 0) resp--;	
		printf("Case #%d: %d\n",caso,resp);	
	}	

}
