#include<cstdio>
#include<cstring>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define N 10001
#define LL __int64
int t[8][8]={
	{0,1,2,3,4,5,6,7},
	{1,0,3,2,5,4,7,6},
	{2,3,1,0,6,7,5,4},
	{3,2,0,1,7,6,4,3},
	{4,5,7,6,1,0,2,3},
	{5,4,6,7,0,1,3,2},
	{6,7,4,5,3,2,1,0},
	{7,6,5,4,2,3,0,1}
};
int L[N];
int pow(int a,LL b){
	int res=0;
	while(b>0){
		if(b&1) res=t[res][a];
		a=t[a][a];
		b>>=1;
	}
	return res;
}
char getChar(){
	char ch=getchar();
	while(ch!='i' && ch!='j' && ch!='k') ch=getchar();
	return ch;
}
LL n,m;
int main(){
	freopen("C.out","w",stdout);
	int T,tt=0;
	LL i,j,iPos,kPos;
	int mul,tmp,flag;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d",&n,&m);
		for(i=0;i<n;++i){
			char ch=getChar();
			switch(ch){
			case 'i':L[i]=2;break;
			case 'j':L[i]=4;break;
			case 'k':L[i]=6;break;
			}
		}
		mul=L[0];
		for(i=1;i<n;++i) mul=t[mul][L[i]];
		if(pow(mul,m)!=1){
			flag=0;
		}
		else{
			iPos=-1;
			// find i
			tmp=0;
			for(i=0;i<MIN(n*m,n*(LL)5);++i){
				j=i%n;
				tmp=t[tmp][L[j]];
				if(tmp==2){
					iPos=i;
					break;
				}
			}
			kPos=-1;
			// find k
			tmp=0;
			for(i=n*m-1;i>=MAX(0,n*m-n*(LL)5);--i){
				j=i%n;
				tmp=t[L[j]][tmp];
				if(tmp==6){
					kPos=i;
					break;
				}
			}
			if(iPos!=-1 && kPos!=-1){
				if(iPos<kPos){
					flag=1;
				}
				else{
					flag=0;
				}
			}
			else{
				flag=0;
			}
		}
		printf("Case #%d: ",++tt);
		if(flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*
5
2 1
ik
3 1
ijk
3 1
kji
2 6
ji
1 10000
i
 */
