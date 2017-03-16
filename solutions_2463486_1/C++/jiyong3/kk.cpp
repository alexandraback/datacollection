#include <iostream>
#include <math.h>
using namespace std;

_int64 d[20];
_int64 fair[50];
int f=0;

int isPalindromes(int t)
{
	int digit;
	digit=-1;
	while(t/d[++digit]);

	if(digit==1)
		return 1;

	int i,j;
	for(i=0;i<=digit/2;i++)
	{
		j=digit-i-1;

		int ii=(t%d[i+1])/d[i];
		int jj=(t%d[j+1])/d[j];

		if(ii!=jj)
			return 0;
	}
	return 1;
}

void process(int Case)
{
	_int64 A,B;
	int result=0;
	cin >> A >> B;

	for(int i=0;i<f;i++)
		if(fair[i]>=A && fair[i]<=B)
			result++;
	cout << "Case #" << Case << ": " << result << endl;
}

void main()
{
	int T;
	cin >> T;

	_int64 t=1;
	for(int i=0;i<=15;i++)
	{
		d[i]=t;
		t*=10;
	}

	_int64 n=0;
	int digit;



	while(1)
	{
		n++;
		t=n*n;
		if(t>100000000000000)
			break;
		
		digit=-1;
		while(t/d[++digit]);

		if(digit==1)
		{
			fair[f++]=t;
			continue;
		}

		int i,j;
		for(i=0;i<=digit/2;i++)
		{
			j=digit-i-1;

			int ii=(t%d[i+1])/d[i];
			int jj=(t%d[j+1])/d[j];

			if(ii!=jj)
				break;
		}

		if(i>digit/2)
		{
			if(!isPalindromes(n))
				continue;
			fair[f++]=t;
		}
	}

	for(int i=1;i<=T;i++)
		process(i);
}