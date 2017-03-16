#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int ta=1;ta<=t;++ta)
	{
		cout << "Case #" << ta << ": ";
		int n;
		cin >> n;
		int s=0;
		int r=0;
		for(int i=0;i<=n;++i)
		{
			char x;
			cin >> x;
			int y = x-'0';
			while(y>0 && i>s)
			{
				s++;
				r++;
			}
			s+=y;
		}
		cout << r << endl;
	}
}
