#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int ta=1;ta<=t;++ta)
	{
		cout << "Case #" << ta << ": ";
		int x,r,c;
		cin >> x >> r >> c;
		if(r>c) swap(r,c);
		bool valid = true;
		if(x>=7) valid = false;
		if(x>c) valid = false;
		if((r*c)%x!=0) valid = false;
		
		if(x>=2*r+1) valid = false;
		if(x>2 && x==2*r) valid = false;
		if(x==5 && r==3) valid = false;
		
		cout << (valid?"GABRIEL":"RICHARD") << endl;
	}
}
