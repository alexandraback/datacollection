#include<stdio.h>
#define scan(ReprN) scanf("%d",&ReprN)
#define scanLL(ReprN) scanf("%I64d",&ReprN)
#define PRINTT(Iterat,Finalll,Condit) for(Iterat=0;Iterat<=Finalll;Iterat++)putchar(start++?(Iterat==Finalll?'\n':(Condit?'.':'*')):'c')

int main()
{
//	freopen("C-small.in","r",stdin);
//	freopen("C-small_out.txt","w",stdout);
	int Test,Case,i,j,k;
	int R,C,M;
	bool start,yo;
	scanf("%d",&Test);
	for(Case=1;Case<=Test;Case++)
	{
		scan(R); scan(C); scan(M);
		M = R*C - M;
		printf("Case #%d: \n",Case);
		start=yo=0;
		if(R==1 || C==1){
			for(i=0;i<R;i++) PRINTT(j,C,i+j<M);
		}
		else if(M==1){
			for(i=0;i<R;i++) PRINTT(j,C,0);
		}
		else if(M==2 || M==3 || M==5 || M==7) puts("Impossible");
		else if((R==2 || C==2) && M%2==1) puts("Impossible");
		else if(R==2){
			PRINTT(i,C,i<M/2);
			PRINTT(i,C,i<M/2);
		}
		else if(C==2){
			for(i=0;i<M/2;i++) PRINTT(k,2,1);
			for(;i<R;i++) PRINTT(k,2,0);
		}
		else{
			while(M>=C*3)
			{
				PRINTT(i,C,1);
				M = M-C;
				R--;
				yo=1;
			}
			if(M==C+C+1 && yo)
			{
				PRINTT(i,C,1);
				PRINTT(i,C,i<C-1);
				PRINTT(i,C,i<2);
			}
			else if(M==C+C || M>C+C+1)
			{
				PRINTT(i,C,1);
				PRINTT(i,C,1);
				if(M==C+C) R++;
				else PRINTT(i,C,i<M-C-C);
			}
			else{
				k = (M-6)/2;
				if(k<0) k=0;
				k+=2;
				if(k>C) k=C;
				PRINTT(i,C,i<k);
				PRINTT(i,C,i<k);
				PRINTT(i,C,i<M-k-k);
			}
			while((R--)-3>0) PRINTT(i,C,0);
		}
	}
	return 0;
}
