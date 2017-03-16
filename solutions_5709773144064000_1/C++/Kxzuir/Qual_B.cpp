#include<cstdio>
#include<iostream>
#define LD double
using namespace std;

//calc max{Sum[A_i,{i,0,n}]+X/(2+n*F)} (A[0]=0,A[i]=C/(2+(i-1)*F)(i>0))
int T,m,n;
LD c,f,x;
LD a(int x){if(x==0) return 0.0;else return (c)/(2+(x-1)*f);}
int main()
{
	//freopen("Qual_B.in","r",stdin);
	//freopen("Qual_B.out","w",stdout);
	cin>>T;
	for(int Case=1;Case<=T;Case++){
		printf("Case #%d: ",Case);
		scanf("%lf%lf%lf",&c,&f,&x);
		LD curtime=0.0,rec=100010.0/2;
		for(int i=0;;i++){
			curtime+=a(i);
			LD endhere=curtime+x/(2+i*f);
			if(rec>endhere) rec=endhere;
			else {printf("%.7lf\n",rec);break;}
		}
	}
}

			

			

		


