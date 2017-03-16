#include <iostream>
using namespace std;

bool test(int X,int R,int C)	//0 Gabe wins, 1 Richard wins
{
	if(R>C) swap(R,C);
	if((R*C)%X) return 1;
	if(X>=7) return 1;
	if(X==1) return 0;
	if(X==2) return 0;
	if(X==3)
		return (R<2)||(C<3);
	if(X==4)
		return (R<3)||(C<4);
	if(X==5)
		return (R<4)||(C<5);
	if(X==6)
		return (R<4)||(C<6);
}

int main()
{
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\input.txt","r",stdin);
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\output.txt","w",stdout);
	int T;
	cin >> T;
	int x,r,c;
	for(int i=0;i<T;i++)
	{
		cin >> x >> r >> c;
		cout << "Case #" << i+1 << ": ";
		if(test(x,r,c))
			cout << "RICHARD\n";
		else
			cout << "GABRIEL\n";
	}
}