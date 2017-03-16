#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

bool palind(int x)
{
	int  r[100]={-1};
	int num=0;
	while (x>0)
	{
		r[num]=x % 10;
		x=x/10;
		num++;
	}
	for (int i=0;i<(num/2);i++)
	{
		if (r[i] != r[num-i-1]) return false;
	}
	return true;
}

bool square(int x)
{
	int m=sqrt (double(x));
	
	if (x==(m*m) && palind(m) ) return true; else return false;
}

int main()
{
	freopen ("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int T;
	cin >> T;
	for (int qq=1;qq<=T;qq++)
	{
		int a,b;
		cin >> a>>b;
		int total=0;
		for (int t=a;t<=b;t++)
		{
			if (square(t) && palind(t)) 
				total++; 
		}
		cout <<"Case #"<<qq<<": "<< total<<endl;
	}
	return 0;
}