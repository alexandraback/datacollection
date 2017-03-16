#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int main(){
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("A-small.out","w",stdout);
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int cases;
	cin>>cases;
	cin.ignore();
	for(int i=1;i<=cases;i++){
		int A,B;
		cin>>A>>B;
		double* p=new double[A];
		for(int j=0;j<A;j++){
			cin>>p[j];
		}
		double emin=B+2;
		double mp=1;
		for(int b=0;b<=A;b++){
			mp=(b==0?mp:mp*p[b-1]);
			double e=(1-mp)*(1+B) + (B-A+2*(A-b)+1);
			//printf("b=%d,e=%lf : %lf %lf \n",b,e,(double)((1-mp)*(1+B)),(double)(B-A+2*(A-b)+1) );
			if(e<emin)emin=e;
		}
		printf("Case #%d: %.6lf\n",i,emin);
	}
}