#include <iostream>
#define abs(X) ((X)>0?(X):(-(X)))

using namespace std;


int fact(int x)
{
	if(x<2)
		return 1;
	int n=1;
	while(x>1)
	{
		n*=x;
		x--;
	}
	return n;
}


void submain()
{
	int n;
	int x,y;
	cin >> n >> x >> y;
	int level= abs(x)+abs(y);
	int i;
	int tot=0;
	cout.setf ( std::ios::showpoint );

	for(i=0;tot<n;i++)
		tot+=4*i+1;
	i--;
	tot-=4*i+1;
	int upcoming=n-tot;
	if((level/2)>i)
	{
		cout << 0.0 << endl;
		return;
	}
	if((level/2)<i)
	{
		cout << 1.0 << endl;
		return;
	}

	if(upcoming==4*i+1)
	{
		cout << 1.0 << endl;
		return;
	}
	int oneedge=2*i;
	int l,r;
	int allcases=0,goodcases=0;
	int allfact=fact(upcoming);
	for(int j=0;j<=upcoming;j++)
	{
		l=j;
		r=upcoming-j;
		if (l>oneedge || r> oneedge)
			continue;
		int cases=allfact/(fact(l)*fact(r));
		allcases+=cases;
		if(l>=y+1)
			goodcases+=cases;
	}
	cout << (double)goodcases/allcases << endl;
}


int main()
{
	int t;
	cin >> t;
	for (int a=0;a<t;a++)
	{
		cout << "Case #" << a+1 << ": ";
		submain();
	}
	return 0;
}
