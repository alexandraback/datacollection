#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define LL long long
#define P 1000000007
#define N 100005

int t,f[1000][1000];
LL l,x;
char s[N];

int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	
	scanf("%d",&t);
	f[1][1]=1;
	f[1]['i']='i';
	f[1]['j']='j';
	f[1]['k']='k';
	f['i'][1]='i';
	f['i']['i']=-1;
	f['i']['j']='k';
	f['i']['k']=-'j';
	f['j'][1]='j';
	f['j']['i']=-'k';
	f['j']['j']=-1;
	f['j']['k']='i';
	f['k'][1]='k';
	f['k']['i']='j';
	f['k']['j']=-'i';
	f['k']['k']=-1;
	
	rep(tcase,1,t){
		printf("Case #%d: ",tcase);
		scanf("%I64d%I64d",&l,&x);
		scanf("%s",s+1);
		if(l==1){puts("NO");continue;}
		rep(i,1,l) s[i+l]=s[i],s[i+l+l]=s[i],s[i+l+l+l]=s[i];
		int a=1,b=min(l*x,l*4),u=s[1],v=s[l];
		if(u!='i')
		for(a=2;a<=min(l*x,l*4);a++){
			u=u<0?-f[-u][s[a]]:f[u][s[a]];
			if(u=='i') break;
		}
		if(v!='k')
		for(b=min(l*x,l*4)-1;b>=1;b--){
			v=v<0?-f[s[b]][-v]:f[s[b]][v];
			if(v=='k') break;
		}
		if(a==min(l*x,l*4)+1 || b==0){puts("NO");continue;}
		if(a+1>=l*x-(min(l*x,l*4)-b)){puts("NO");continue;}
		//if(a>=b){puts("NO");continue;}
		u=s[1];
		rep(i,2,l) u=u<0?-f[-u][s[i]]:f[u][s[i]];
		if(u==1){puts("NO");continue;}
		if(u==-1 && x%2==1 || u!=-1 && x%2==0 && x/2%2==1){
			puts("YES");
		}else puts("NO");
	}
}
