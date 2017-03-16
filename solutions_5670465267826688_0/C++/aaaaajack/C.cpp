#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define N 10010
using namespace std;
char s[N];
int sum[N*4];
inline int unsigned_op(int a,int b){
	if(a==1||b==1) return a==1?b:a;
	if(a==b) return -1;
	if(a+1==b||a==4&&b==2) return 9-a-b;
	return a+b-9;
}
inline int op(int a,int b){
	if((a<0)^(b<0)) return -unsigned_op(abs(a),abs(b));
	return unsigned_op(abs(a),abs(b));
}
int main(){
	int cs,T,l,x,i;
	bool f1,f2,f3;
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++){
		f1=f2=f3=false;
		scanf("%d%d",&l,&x);
		scanf("%s",s);
		for(i=0;s[i];i++){
			s[i]-=('i'-2);
		}
		sum[0]=1;
		for(i=1;i<l*4;i++){
			sum[i]=op(sum[i-1],s[(i-1)%l]);
		}
		if(sum[l*(x%4)]==-1) f3=true;
		for(i=1;i<=l*min(x,8);i++){
			if(!f1){
				if(sum[i%(l*4)]==2) f1=true;
			}
			else if(sum[i%(l*4)]==4) f2=true;
		}
		if(f1&&f2&&f3) printf("Case #%d: YES\n",cs);
		else printf("Case #%d: NO\n",cs);
	}
	return 0;
}