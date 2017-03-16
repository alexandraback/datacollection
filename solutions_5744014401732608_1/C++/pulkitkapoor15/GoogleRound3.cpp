#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    freopen("inputfile.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int testCase, testCases, num1;
	long long num2, s;
	int arrs[60][60], i, j;
	cin>>testCases;
	for(testCase=1; testCase<=testCases; ++testCase)
	{
		cin>>num1>>num2;
		s=1;
		for(i=1; i<=num1-2; ++i) s*=2;
		if(num2>s) { cout<<"Case #"<<testCase<<": IMPOSSIBLE\n"; continue; }
		cout<<"Case #"<<testCase<<": POSSIBLE\n";
		for(i=1; i<=num1; ++i)
		{
			for(j=1; j<=i; ++j)
			arrs[i][j]=0;
			for(j=i+1; j<num1; ++j)
			arrs[i][j]=1;
		}
		if(num2==s)
		{
			for(i=1; i<num1; ++i) arrs[i][num1]=1;
		}
		else
		{
			arrs[1][num1]=0;
			for(i=2; i<num1; ++i)
			{
				arrs[i][num1]=(num2%2);
				num2/=2;
			}
		}
		for(i=1; i<=num1; ++i)
		{
			for(j=1; j<=num1; ++j)
			{
			cout<<arrs[i][j];
			}
			printf("\n");
		}
	}
}
