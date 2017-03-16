#include<cstdio>
int N,S,P,nr[110],sol;
struct triplet{
	int a,b,c,pus;
}sur[40],norm[40];
int ss[110][110];
inline int modul(int x){
	if(x<0)
		return -x;
	return x;
}
inline int dif(int a,int b){
	return modul(a-b);
}
inline int max(int a, int b){
	return a>b?a:b;
}
void mareste(int i,int j,int k, triplet x){
	if(max(i,max(j,k))<=max(x.a,max(x.b,x.c)))
		return;
	x.a=i;
	x.b=j;
	x.c=k;
}
void precalc(){
	int i,j,k,s;
	for(i=10;i>=0;--i){
		for(j=10;j>=0;--j){
			if(dif(i,j)<2){
				for(k=10;k>=0;--k){
					if(dif(i,k)<2 && dif(j,k)<2){
						s=i+j+k;
						if(!norm[s].pus){
							norm[s].pus=1;
							norm[s].a=i;
							norm[s].b=j;
							norm[s].c=k;
						}
						else
							mareste(i,j,k,norm[s]);
					}
				}
			}
		}
	}
	for(i=10;i>=0;--i){
		for(j=10;j>=0;--j){
			if(dif(i,j)<=2){
				for(k=10;k>=0;--k){
					if(dif(i,k)<=2 && dif(j,k)<=2){
						if(dif(i,j)!=2 && dif(i,k)!=2 && dif(j,k)!=2)
							continue;
						s=i+j+k;
						if(!sur[s].pus){
							sur[s].pus=1;
							sur[s].a=i;
							sur[s].b=j;
							sur[s].c=k;
						}
						else
							mareste(i,j,k,sur[s]);
					}
				}
			}
		}
	}
}
int valid(triplet x){
	if(x.a>=P)
		return 1;
	if(x.b>=P)
		return 1;
	if(x.c>=P)
		return 1;
	return 0;
}
void solve(){
	sol=0;
	int i,j;
	for(i=1;i<=N;++i){
		for(j=0;j<=S && j<=i;++j){
			if(valid(norm[nr[i]]))
				ss[i][j]=ss[i-1][j]+1;
			else
				ss[i][j]=ss[i-1][j];
			if(nr[i]<2 || 28<nr[i])
				continue;
			if(!j)
				continue;
			if(valid(sur[nr[i]]))
				ss[i][j]=max(ss[i][j],ss[i-1][j-1]+1);
			else{
				ss[i][j]=max(ss[i][j],ss[i-1][j-1]);
			}
		}
	}
	sol=ss[N][S];
	for(i=0;i<=N;++i)
		for(j=0;j<=S;++j)
			ss[i][j]=0;
}
int main(){
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	precalc();
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i){
		scanf("%d%d%d",&N,&S,&P);
		for(int j=1;j<=N;++j)
			scanf("%d",&nr[j]);
		solve();
		printf("Case #%d: %d\n",i,sol);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
