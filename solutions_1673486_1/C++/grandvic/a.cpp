#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
//	freopen("k:/input.txt", "rt", stdin);
	int N,T;

	cin>>T;

	for(int t=1; t<=T; ++t)
	{
		int A,B;
		cin>>A>>B;

		double x, PP = 1.0;
		vector<double> p;
		p.reserve(A+1);
		p.push_back(PP);

		for(int i=0; i<A; ++i)
		{
			cin>>x;
			p.push_back(PP*=x);
		}

		double av1 = p[A]*(B-A+1) + (1.0-p[A])*(2*B-A+2);
		double av3 = (B+2);
		double av2 = B*10;

		

		for(int i=A-1; i>=0; --i)
		{
			double pp = (p[i]*(B-i+1+A-i) + (1.0-p[i])*(B-i+1+A-i+B+1) );
			av2 = min(av2, pp);
//			cout<<">"<<i<<" "<<pp<<endl;
		}

//		cout<<"["<<av1<<" "<<av2<<" "<<av3<<"]"<<endl;

		double best = av1;
		if(best>av2)best = av2;
		if(best>av3)best = av3;

		printf("Case #%d: %.6f\n", t, best);
	}

	return 0;
}