#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int main(){
	freopen("A-small-attempt4.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin >> T;
	int C;
	int R;
	int W;
	for(int t = 1;t<=T;t++)
	{
		cout << "Case #" << t << ": ";
		cin >> R;
		cin >> C;
		cin >> W;
		int a = C/W;
		
	
		
		a = a*R;
		a = a + W-1;
		if(!(C % W==0) && W!=1)
		{
			 a = a + 1;
		}
		/*if(C%W ==0)
		{
			a = a -1;
		}*/
		cout << a << endl;

	}

	return 0;
}