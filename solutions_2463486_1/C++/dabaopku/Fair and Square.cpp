#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <string.h>
#include <ctime>
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
			cout<<x<<" "<<y<<endl;
		}
	}
	cout<<cnt<<endl;
}

long long resultMiddle[][2]={
	{1, 1},
	{2, 4},
	{3, 9},
	{11, 121},
	{22, 484},
	{101, 10201},
	{111, 12321},
	{121, 14641},
	{202, 40804},
	{212, 44944},
	{1001, 1002001},
	{1111, 1234321},
	{2002, 4008004},
	{10001, 100020001},
	{10101, 102030201},
	{10201, 104060401},
	{11011, 121242121},
	{11111, 123454321},
	{11211, 125686521},
	{20002, 400080004},
	{20102, 404090404},
	{100001, 10000200001},
	{101101, 10221412201},
	{110011, 12102420121},
	{111111, 12345654321},
	{200002, 40000800004},
	{1000001, 1000002000001},
	{1001001, 1002003002001},
	{1002001, 1004006004001},
	{1010101, 1020304030201},
	{1011101, 1022325232201},
	{1012101, 1024348434201},
	{1100011, 1210024200121},
	{1101011, 1212225222121},
	{1102011, 1214428244121},
	{1110111, 1232346432321},
	{1111111, 1234567654321},
	{2000002, 4000008000004},
	{2001002, 4004009004004},
	{10000001, 100000020000001},
	{10011001, 100220141022001},
	{10100101, 102012040210201},
	{10111101, 102234363432201},
	{11000011, 121000242000121},
	{11011011, 121242363242121},
	{11100111, 123212464212321},
	{11111111, 123456787654321},
	{20000002, 400000080000004}
};

void solveMiddle()
{
	int start=0;
	int end=0;
	for(int i=0;i<50;++i)
	{
		if(resultMiddle[i][1]<lowSmall)
			start++;
		if(resultMiddle[i][1]<=highSmall)
			end++;
	}
	cout<<end-start<<endl;
}

int main()
{
	cin>>caseNumber;
	for(int caseId=1;caseId<=caseNumber;++caseId)
	{
		cout<<"Case #"<<caseId<<": ";
		inputSmall();
		solveMiddle();
	}
	return 0;
}