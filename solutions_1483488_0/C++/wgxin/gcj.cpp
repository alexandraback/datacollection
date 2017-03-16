#include<iostream>
#include<string>
#include<set>
#include<cmath>
using namespace std;
const int maxn = 101;

int getDigitNum(int num)
{
	int count = 0;
	while(num)
	{
		count++;
		num/=10;
	}

	return count;
}

int process(int num, const int& A, const int& B)
{
	set<int> seen;
	seen.insert(num);

	int len = getDigitNum(num);
	
	int div, multi, l;
	for(l=1, div=10, multi=pow(10.0, len-1); l<len;l++, div*=10, multi/=10)
	{
		int newNum = (num%div)*multi + num/div;
		if(newNum>=A && newNum<=B)
			seen.insert(newNum);
	}

	return seen.size()-1;
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	int T;
	int A, B;
	int ans;
	cin>>T;
	
	for(int cas=1;cas<=T;cas++)
	{
		ans = 0;
		cin>>A>>B;
		for(int i=A;i<=B;i++)
		{
			ans += process(i, A, B);
		}
		cout<<"Case #"<<cas<<": "<<ans/2<<endl;;
	}
}