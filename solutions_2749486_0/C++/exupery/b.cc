#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=1; i<=T; i++) {
		int gx,gy,sx=0,sy=0,idx=0;
		char s[555]="";
		scanf("%d%d",&gx,&gy);
		if(gx<0){sx=1;gx=-gx;}
		if(gy<0){sy=1;gy=-gy;}
		for(int j=0;j<gx;j++){
			if(sx){
				s[idx++]='E';
				s[idx++]='W';
			}
			else{
				s[idx++]='W';
				s[idx++]='E';
			}
		}
		for(int j=0;j<gy;j++){
			if(sy){
				s[idx++]='N';
				s[idx++]='S';
			}
			else{
				s[idx++]='S';
				s[idx++]='N';
			}
		}

		printf("Case #%d: %s\n", i, s);
	}

	return 0;
}
