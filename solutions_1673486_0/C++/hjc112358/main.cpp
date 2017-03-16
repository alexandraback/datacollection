#include <iostream>
#include <fstream>
#include <iomanip>

#define DEBUG 0
#define NUMBER 100

using namespace std;

int main(int argc, char *argv[])
{
	int i,j,k;
	int t;
	double p[NUMBER];
	double di,dj,dk;
	int a,b;
	double case1;
	double case2_a[NUMBER];
	double case2;
	double case3;
	double result;
	ifstream inFile("A-small-attempt0.in");
	ofstream outFile("result.out");

	inFile>>t;
	for (i=0; i<t; i++)
	{
		cout<<"Case #"<<i+1<<endl;
		outFile<<"Case #"<<i+1<<": ";
		inFile>>a>>b;
		for (j=0;j<a;j++)
			inFile>>p[j];
		//case 1
		di = 1;
		for (j=0;j<a;j++)
			di = di*p[j];
		case1 = di*(b-a+1) + (1.0-di)*(2*b+2-a);
		//case2
		for (j=0;j<a;j++)//back j chars
		{
			di = 1;
			for (k=0;k<a-j;k++)
				di = di*p[k];
			case2_a[j] = di*(2*j+b-a+1)+(1.0-di)*(2*j+b-a+1+b+1);
		}
		case2 = case2_a[0];
		for (j=1;j<a;j++)
			if (case2_a[j]<case2)
				case2 = case2_a[j];
		//case3
		case3 = 2.0+b;
		//result
		result = case1<case2 ? case1 : case2;
		result = result<case3 ? result : case3;
		outFile<<fixed<<setprecision(6)<<result<<endl;
	}


#if DEBUG
	cin>>i;
#endif
	return 0;
}