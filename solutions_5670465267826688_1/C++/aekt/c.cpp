#include <cstdio>

int i,j,k,t,T,l;
long long x;
char s[10010];
bool f,I,J,K;

int map[4][4]={{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};

int sub(char o){
	int p;
	if(o=='1')p=1;
	if(o=='i')p=2;
	if(o=='j')p=3;
	if(o=='k')p=4;
	return p;
}

int sig(int o){
	if(o<0){
		f=!f;
		o=-o;
	}
	return o;
}

int main(){
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d%lld",&l,&x);
		scanf("%s",s);
		for(j=0,k=1,f=0;j<l;j++){
			k=sig(map[k-1][sub(s[j])-1]);
		}
		K=(x%2&&k==1&&f)||(x%4==2&&k!=1);
		for(I=0,i=j=0,k=1,f=0;j<i+4*l&&!I&&K;j++){
			if(j&&j%l==0){
				x--;
				if(x==0){
					break;
				}
			}
			k=sig(map[k-1][sub(s[j%l])-1]);
			if(k==2&&!f){
				I=1;
			}
		}
		for(J=0,i=j,k=1,f=0;j<i+4*l&&x&&!J&&I&&K;j++){
			if(j%l==0){
				x--;
				if(x==0){
					break;
				}
			}
			k=sig(map[k-1][sub(s[j%l])-1]);
			if(k==3&&!f){
				J=1;
			}
		}
		printf("Case #%d: %s\n",t,I&&J&&K?"YES":"NO");
	}
	return 0;
}
