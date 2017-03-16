#include <iostream>
#include <vector>
using namespace std;

vector<long long> ok;

bool poly(long long k)
{
	int num[14];
	int i=0;
	while(k)
	{
		num[i++] = k%10;
		k/=10;
	}
	for(int j=0;i-j-1>j;j++)
	{
		if(num[j]!=num[i-j-1])
			return false;
	}
	return true;
}

bool check(long long i)
{
	if(poly(i) && poly(i*i))
		return true;
	return false;
}

void pre()
{
	for(long long i=1;i<=10000000;i++)
	{
		if(check(i))
			ok.push_back(i*i);
	}
}

int main()
{
	pre();
	//cout << ok.size() << endl;
	int T;
	cin >> T;
	for(int c=1; c<=T; c++)
	{
		long long A,B;
		cin >> A >> B;
		int start = 0,end;
		for(int i=0;i<ok.size();i++)
		{
			if(ok[i]<A)
				start = i+1;
			if(ok[i]<=B)
				end = i;
		}
		cout << "Case #" << c << ": " << end-start+1 << endl;
	}
}