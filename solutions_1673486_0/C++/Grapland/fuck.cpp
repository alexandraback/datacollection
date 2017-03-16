#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXA=200000;
int tp[1000];
double ts[MAXA];
double tsm[MAXA];


int main(){
	int T;
	cin>>T;
	for(int tt=0;tt<T;tt++){
		int A,B;
		cin>>A>>B;
		for(int i=0;i<A;i++)
			cin>>ts[i];
		double res=200.0*(double)(A+B);
		double pr=0;
		//directly press enter
		pr=2.0+B;
		if(pr<res)
			res=pr;
		//finish type and press enter
		double paw=1.0;
		for(int i=0;i<A;i++)
			paw*=ts[i];
		pr=paw*(double)(B-A+1)+(1.0-paw)*(double)(B-A+1+B+1);
		if(pr<res)
			res=pr;
		//type bksp [1,A] time(s) and type,fi,and enter
		tsm[0]=1.0;
		for(int i=0;i<A;i++)
			tsm[i+1]=tsm[i]*ts[i];
		for(int k=1;k<=A;k++){
			pr=tsm[A-k]*(double)(k+B-(A-k)+1)+(1.0-tsm[A-k])*(double)(k+B-(A-k)+1+B+1);
			if(pr<res)
				res=pr;
		}
		printf("Case #%d: %.6lf\n",tt+1,res);
	}
}
