#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int R,C,W;
int main()
{
	int T;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		cin >> R >> C >> W;
		cout << "Case #"<<t<<": ";
		int p;
		if(C%W==0)
			p=0;
		else
			p=1;
		cout << R*(C/W)+p+W-1<<endl;
	}
	return 0;
}
