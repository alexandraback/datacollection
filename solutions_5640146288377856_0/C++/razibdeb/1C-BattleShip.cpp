#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;

	cin>>T;
	for (int t = 1; t <= T; t++)
	{
		int result = 0;
		int R,C,W;
		cin>>R>>C>>W;


		result += (C/W) * R;
		

		int mod = C % W;
		if (mod == 0)
		{
			result += W - 1;
		}
		else
		{
			result += 1 + W - 1;
		}
		
		cout<<"Case #"<<t<<": "<<result<<endl;

	}
	return 0;
}