#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 #define DN 105
#define LL long long
LL t,n,m;
long long tp[2][DN],cant[2][DN],bst[DN][DN],rez;
 
inline void back(int i,int j,LL cst) {
	if(rez<cst)
		rez=cst;
   // rez=max(rez,cst);
    if(cst<bst[i][j]) return;
    bst[i][j]=cst;
    if(i>n || j>m) return;
    if(tp[0][i]==tp[1][j]) {
		LL cc;
		if(cant[0][i]<cant[1][j])
			cc=cant[0][i];
		else
			cc=cant[1][j];
       // LL cc=min(cant[0][i],cant[1][j]);
        if(cant[0][i]<cant[1][j]) {
            cant[1][j]-=cc;
            back(i+1,j,cst+cc);
            cant[1][j]+=cc;
        }
        else if(cant[0][i]==cant[1][j]) back(i+1,j+1,cst+cc);
        else {
            cant[0][i]-=cc;
            back(i,j+1,cst+cc);
            cant[0][i]+=cc;
        }
    }
    back(i+1,j,cst);
    back(i,j+1,cst);
}
 
int main()
{
	FILE *in,*out;
	in=fopen("1c3.in","r");
	out=fopen("1c3.out","w");
fscanf(in,"%lld",&t);
    for(int k=1; k<=t; ++k) {
		fscanf(in,"%lld%lld",&n,&m);
        memset(bst,0,sizeof(bst));
		//fprintf(out,"%d\n",k);
        memset(bst,0,sizeof(bst));
        for(int i=1; i<=n; ++i) fscanf(in,"%lld%lld",&cant[0][i],&tp[0][i]);
        for(int i=1; i<=m; ++i)fscanf(in,"%lld%lld",&cant[1][i],&tp[1][i]);
        rez=0;
        back(1,1,0);
		fprintf(out,"Case #%ld: %lld\n",k,rez);
       // cout<<"Case #"<<k<<": "<<rez<<'\n';
        //char c;
    }
    return 0;
}
