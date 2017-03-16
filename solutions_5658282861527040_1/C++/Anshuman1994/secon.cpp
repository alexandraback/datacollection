#include <iostream>
using namespace std;
int main()
{
int testcases;
long int A;
long int B;
long int C;
long long int answer=0;

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
		//if (A>C && B>C)
		cout <<"Case #"<<i+1<<": "<<A*B-answer<<"\n";
		//else cout <<

	}




}
