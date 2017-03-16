#include <stdio.h>
char S[200001];
int CL[200001],CR[200001];
struct XD {
	bool neg;
	char c;
	XD& operator*=(XD o){
		neg^=o.neg;
		c= c=='1' ? o.c :
		   o.c=='1' ? c :
		   c==o.c ? (neg=!neg,'1'):
		   c=='i'&&o.c=='j' ? 'k':
		   c=='i'&&o.c=='k' ? (neg=!neg,'j'):
		   c=='j'&&o.c=='i' ? (neg=!neg,'k'):
		   c=='j'&&o.c=='k' ? 'i':
		   c=='k'&&o.c=='i' ? 'j':
		   c=='k'&&o.c=='j' ? (neg=!neg,'i'):'X';
		return *this;
	}
	bool operator==(XD o){
		return neg==o.neg && c==o.c;
	}
	bool operator!=(XD o){
		return !operator==(o);
	}
} LL,R,tmp;
int main(){
	int i,j,k;
	int L,X,T,TN,N;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d%d%s",&L,&X,S);
		if(X>12){
			X-=4*(X/4-3);
		}
		for(i=0;i<L;i++){
			for(j=1;j<X;j++){
				S[j*L+i]=S[i];
			}
		}
		N=L*X;
		S[N]=0;
		//printf("%s\n",S);
		LL.neg=false;
		LL.c='1';
		CL[0]=0;
		for(i=0;i<N;i++){
			LL*=(XD){false,S[i]};
			//printf("%c%c\n"," -"[LL.neg],LL.c);
			CL[i+1]=(LL==(XD){0,'i'}) || CL[i];
		}
		if(LL!=(XD){1,'1'}){
			goto NO;
		}
		R.neg=false;
		R.c='1';
		CR[N]=0;
		for(i=N-1;i>=0;i--){
			tmp=(XD){0,S[i]};
			tmp*=R;
			R=tmp;
			CR[i]=(R==(XD){0,'k'}) || CR[i+1];
			//printf("%c%c\n"," -"[R.neg],R.c);
		}
		for(i=0;i<N-1;i++){
			//N=10
			//CL[4] CR[5]
			if(CL[i+1]&&CR[i+2]){
				goto YES;
			}
		}
		NO:printf("Case #%d: NO\n",T);
		if(0){
			YES:printf("Case #%d: YES\n",T);
		}
	}
}
	
