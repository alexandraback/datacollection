#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<stack>
#include<limits>
using namespace std;

int main()
{
	int t,i,j;
	stack<double> mults;
	
	cin >> t;
	
	for(i=0; i<t; i++)
	{
		int a,b;
		double mult = 1.0, aux, md, tpd=0.0, tst = 0.0;
		cin >> a;
		cin >> b;
		
		mults.push(mult);
		
		for(j=0; j<a; j++)
		{
			tpd+=1.0;
			cin >> aux;
			mult*=aux;
			mults.push(mult);
		}
		
		mult = numeric_limits<float>::infinity();
		
		double mult2;
		
		
		while(mults.size())
		{
			double x = mults.top();
			mults.pop();
			
			mult2 = x*(b-tpd+1) + (1-x)*(2*b-tpd+2) + tst;
			mult = min(mult, mult2);	
			tst+=1.0;
			tpd-=1.0;
		}
		cout << "Case #" << i+1 << ": ";
		printf("%.6lf\n", min(mult, b+2.0));
	}
	
	return 0;
}
