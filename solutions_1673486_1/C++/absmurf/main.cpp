#include<iostream>
#define REP(i,n) for(i=0;i<n;i++)

using namespace std;

int main()
{
	int T;
	cin>>T;
	int A,B;
	float input;
	float current;
	float mincase;
	float pn;
	int c,i,j,k,x;
	REP(c,T)
	{
		cin>>A>>B;
		pn=1;
		mincase=0;
		REP(x,A+1)
		{
			k=A-x;
			current=pn*(2*k+B-A+1)+(1-pn)*(2*k+2*B-A+2);
			if(current<mincase||mincase==0)
				mincase=current;
			//cout<<k<<" "<<current<<endl;
			if(x!=A) 
			{
					cin>>input;
					pn*=input;
			}
		}
		current=2+B;
		if(current<mincase)
			mincase=current;
		printf("Case #%d: %.6f\n", c+1,mincase);
	}
	return 0;
}