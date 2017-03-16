#include<iostream>
using namespace std;
const int maxN=10010;
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
	freopen("a.txt","w",stdout);
	int T,kase,i,j,n,x,mark;
	char tmp;
	scanf("%d",&T);
	for(kase=1;kase<=T;kase++){
		scanf("%d%d",&n,&x);
		x=x*100000;
		scanf("%s",s);
		for(i=1;i<x;i++)
			for(j=0;j<n;j++) s[i*n+j]=s[j];
		//cout<<s<<endl;
	//	cout<<(char)fabs(calc(s[0],s[1]))<<endl;
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
		printf("Case #%d: %s\n",kase,(mark?"YES":"NO"));
	}
	return 0;
}
