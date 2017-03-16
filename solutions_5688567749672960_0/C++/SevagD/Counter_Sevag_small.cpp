#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;


int T, N;

int DP[1000005];

int invert(int n)
{
	int res = 0;
	while (n) {
		int digit = n%10;
		res = res*10 + digit;
		n/=10;
	}
	return res;
}

int getMin(int n) 
{
	if (n==N)
		return 1;
	if (n>N)
		return 1e9;

	if (DP[n]>-1)
		return DP[n];



	int val2 = 1e9;
	int reverse = invert(n);
	if (reverse>n)
		val2 = getMin(reverse) + 1;

		int val1 = getMin(n+1) + 1;

	DP[n] = min(val1,val2);
	return min(val1,val2);
}

int main() 
{
	ifstream cin;
	cin.open("A-small-attempt1.in");

ofstream cout;
cout.open("Counter_Sevag_Small.out");

	cin>>T;

	for (int t=1; t<=T; t++) 
	{
		cin>> N;

		fill(&DP[0], &DP[0]+1000005, -1);
		int ans = getMin(1);
	
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	
	return 0;
}