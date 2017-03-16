#include <cstdio>
#include <iostream>

using namespace std;

typedef long double ld;

int n,x,y;

ld przyp()
{
	cin >> n >> x >> y;
	if(x<0) x*= -1;
	int k=x+y;
	n-=(k-1)*(k>>1);
	if(n<=0) return 0.0;
	if(n>=((k<<1)+1)) return 1.0;
	if(x==0) return 0.0;
	x=k-x+1;
	int y=0;
	int z=0;
	for(int i=0;i<(1<<n);i++)
	{
		if(__builtin_popcount(i)>k || (n-__builtin_popcount(i))>k) continue;
		if(__builtin_popcount(i)>=x) y++;
		z++;
	}
	return static_cast<ld>(y)/z;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		cout.setf(ios::fixed);
		cout << "Case #" << i << ": " << przyp() << "\n";
	}
	return 0;
}
