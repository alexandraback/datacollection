#include <iostream>

using namespace std;

int ileCyfr(int x)
{
	int wyn=0;
	while (x)
	{
		++wyn;
		x/=10;
	}
	return wyn;
}

int baza;

void setBaza(int cyfr)
{
	baza=1;
	for (int i=1; i<cyfr; ++i) baza*=10;
}

int next(int x)
{
	int b=baza;

	int last=x%10;
	x=last*baza+x/10;
	while (last==0)
	{
		last=x%10;
		x=last*baza+x/10;
	}
	return x;
}

int main()
{
	ios::sync_with_stdio(0);

	int Testow; cin>>Testow;
	for (int test=1; test<=Testow; ++test)
	{
		int A,B;
		cin>>A>>B;
		int digits=ileCyfr(A);
		setBaza(digits);

		int cnt=0;
		for (int x=A; x<=B; ++x)
		{
			int y=next(x);
			while (y!=x)
			{
				if (y>x && y<=B) ++cnt;
				y=next(y);
			}			
		}
		
		cout<<"Case #"<<test<<": "<<cnt<<endl;
	}

	return 0;
}