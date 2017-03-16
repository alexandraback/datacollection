#include <cstdio>
int rnd=1,rr;
int r,c,w,ans,ac,base,rem;
void solve(){
	base=0;r=0;c=0;w=0;ac=0;
	scanf("%d %d %d",&r,&c,&w);
	ac=c-(w-1);
	base=ac/w;
	if(ac%w) base++;
	ans=base*(r-1);

	//printf("%d\n",ans);
	if(ac%w==1) base=ac/w+w;
	else if(ac%w==0) base=(ac/w)-1+w+1;
	else 	base=ac/w+w+1;
	ans+=base;
	if(w==1) ans=r*c;
	printf("CASE #%d: %d\n",rnd++,ans);
}
int main(){
	//freopen("output.out","w",stdout);
	//freopen("input.in","r",stdin);
	scanf("%d",&rr);
	while(rr--) solve();
	return 0;
}