#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <string.h>

using namespace std;

struct node
{
	int height;
	int x,y;
	bool operator <(const node & o) const
	{
		return o.height<height ||
			o.height==height && o.x<x ||
			o.height==height && o.x==x && o.y<y;
	}
	node(int x_=0,int y_=0):
		x(x_),y(y_)
	{}
};


int caseNumber;

long long lowSmall,highSmall;

bool checkSmall(long long num)
{
	string s="";
	while(num)
	{
		s+=num%10;
		num/=10;
	}
	int len=s.length();
	for(int i=0;i<len/2;++i)
	{
		if(s[i]!=s[len-1-i])
			return false;
	}
	return true;
}
void inputSmall()
{
	cin>>lowSmall>>highSmall;
}
void solveSmall()
{
	long long l=(long long)sqrt(lowSmall),h=(long long)sqrt(highSmall);
	if(l*l<lowSmall && (l+1)*(l+1)>=lowSmall)
		l=l+1;
	if(h*h>highSmall && (h-1)*(h-1)<=highSmall)
		h=h-1;
	
	int cnt=0;
	for(long long x=l;x<=h;++x)
	{
		long long y=x*x;
		if(checkSmall(x) && checkSmall(y))
		{
			cnt++;
		}
	}
	cout<<cnt<<endl;
}
int main()
{
	cin>>caseNumber;
	for(int caseId=1;caseId<=caseNumber;++caseId)
	{
		cout<<"Case #"<<caseId<<": ";
		inputSmall();
		solveSmall();
	}
	return 0;
}