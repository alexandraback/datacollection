#include <cstdio>

int i,j,k,t,T,m,s[2];
char ss[1010];
int main(){
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		k=0;
		scanf("%d %s",&m,ss);
		s[0]=ss[0]-'0';
		for(i=1;ss[i];i++){
			s[i%2]=ss[i]-'0'+s[(i-1)%2];
			if(s[(i-1)%2]+k<i){
				k=i-s[(i-1)%2];
			}
		}
		printf("Case #%d: %d\n",t,k);
	}
	return 0;
}
