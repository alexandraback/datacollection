#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int test_num=1;test_num<=T;test_num++)
	{
		int X, R, C;
		cin >> X >> R >> C;
		bool ok = true;
		if (C > R) swap(C, R);
		if (R*C % X) ok = false;
		else if (X == 3)
		{
			if (C == 1) ok = false;
			else if (R < 3 && C < 3) ok = false;
		}
		else if (X == 4)
		{
			if (R < 4 && C < 4) ok = false;
			else if (C < 3) ok = false;
		}
		printf("Case #%d: %s\n", test_num, ok?"GABRIEL":"RICHARD");	
	}
	
	return 0;
}
