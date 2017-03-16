#include <iostream>
using namespace std;
int main()
{
int testcases;
int A;
int B;
int C;
long long answer=0;

	cin >> testcases;
	for (int i=0;i<testcases;i++)
	{
		answer=0;
		cin >> A;
		cin >> B;
		cin >> C;
		for (int j=C-1;j<A;j++)
		{
			for (int k=C-1;k<B;k++)
			if ((j&k)>=C) answer++;
		}
	cout <<"Case #"<<i+1<<": "<<A*B-answer<<"\n";

	}




}
