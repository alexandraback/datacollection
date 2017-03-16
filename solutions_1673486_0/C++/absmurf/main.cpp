#include<iostream>
#define REP(i,n) for(i=0;i<n;i++)

using namespace std;

int main()
{
	int T;
	cin>>T;
	int A,B;
	float* probs;
	float current;
	float mincase;
	float pn;
	int c,i,j,k,x;
	REP(c,T)
	{
		cin>>A>>B;
		probs=new float[B];
		REP(i,A)
			cin>>probs[i];
		pn=1;
		REP(x,A)
			pn*=probs[x];
		mincase=pn*(B-A+1)+(1-pn)*(2*B-A+2);
		for(k=1;k<=A;k++)
		{
			pn/=probs[A-k];
			current=pn*(2*k+B-A+1)+(1-pn)*(2*k+2*B-A+2);
			if(current<mincase)
				mincase=current;
		}
		current=2+B;
		if(current<mincase)
			mincase=current;
		printf("Case #%d: %.6f\n", c+1,mincase);
	}
	return 0;
}