#include <stdlib.h>
#include <iostream>
using namespace std;

#define N 1001

int nPeople[N];
int S;

int nInvites()
{
	int nStanding(0);
	int nMore(0);
	for (int i=0; i<=S; ++i)
	{
		if (i > nStanding)
		{
			nMore += i-nStanding;
			nStanding = i;
		}
		nStanding += nPeople[i];
	}
	return nMore;
}

void readCase()
{
	char str[2*N];
	cin>>S;
	cin.get(str, 2*N);
	for (int i=1; i<=S+1; ++i)
		nPeople[i-1] = str[i]-'0';
}

int main()
{
	int T;
	cin>>T;
	for (int i=0; i < T; ++i)
	{
		readCase();
		cout<<"Case #"<<i+1<<": "<<nInvites()<<endl;
	}
	return 0;
}