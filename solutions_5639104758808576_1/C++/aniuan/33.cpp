#include<iostream>
using namespace std;
const int maxN=110010;
char s[maxN];
char calc(char a,char b){
	int t;
	t=1;
	if(a<0) t=-t,a=-a;
	if(b<0) t=-t,b=-b;
	
	if(a=='1') return t*b;
	if(b=='1') return t*a;
	if(a=='i')
		if(b=='i') return '1'*(-t);
		else
		if(b=='j') return 'k'*t;
		else return 'j'*(-t);
	else
	if(a=='j')
		if(b=='i') return 'k'*(-t);
		else
		if(b=='j') return '1'*(-t);
		else return 'i'*t;
	else
		if(b=='i') return 'j'*t;
		else
		if(b=='j') return 'i'*(-t);
		else return '1'*(-t);
};
#include<cmath>
int main(){
	freopen("C-small-attempt1.in","r",stdin);
	freopen("b.txt","w",stdout);
	int T,kase,i,j,n,mark;
	long long x,l,r;
	char tmp,base;
	scanf("%d",&T);
	for(kase=1;kase<=T;kase++){
		scanf("%d%I64d",&n,&x);
		scanf("%s",s);
		if(x<=10){
			for(i=1;i<x;i++)
				for(j=0;j<n;j++) s[i*n+j]=s[j];
			n=n*x;
			tmp=s[0];
			for(i=1;i<n;i++) tmp=calc(tmp,s[i]);
			
			mark=1;
			if(tmp!='1'*(-1)) mark=0;
			else{
				tmp=s[0];
				for(i=1;i<n&&tmp!='i';i++)	tmp=calc(tmp,s[i]);
				tmp=s[n-1];
				for(j=n-2;j>=0&&tmp!='k';j--) tmp=calc(s[j],tmp);
				mark=i<=j;
			}
		}
		else{
			base='1';
			for(i=0;i<n;i++) base=calc(base,s[i]);
			tmp='1';
			for(i=0;i<x%4;i++) tmp=calc(tmp,base);
			mark=1;
			if(tmp!='1'*(-1)) mark=0;
			else{
				tmp='1';
				for(i=1;i<=4;i++)
					for(j=0;j<n;j++) s[i*n+j]=s[j];
				for(i=0;i<4*n&&tmp!='i';i++) tmp=calc(tmp,s[i]);
				l=i+1;
				tmp='1';
				for(i=4*n-1;i>=0&&tmp!='k';i--) tmp=calc(s[i],tmp);
				r=4*n-i+1;
			//	cout<<l<<'\t'<<r<<endl;
				mark=(l+r<x*(long long)n)&&(l<=4*n)&&(r<=4*n);
			}
		}
		printf("Case #%d: %s\n",kase,(mark?"YES":"NO"));
	}
	return 0;
}
