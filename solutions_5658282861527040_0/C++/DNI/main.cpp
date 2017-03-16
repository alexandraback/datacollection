#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>


using namespace std;


int main()
{

	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int tt;
	cin >> tt;
	for(int t = 1; t <= tt; t++)
	{
		int a, b, k;
		cin >> a >> b >> k;
		int answ  =0;
		for(int i = 0; i < a; i++)
			for(int j = 0; j < b; j++)
				if((i & j) < k)
					answ++;
		printf("Case #%d: %d\n", t, answ);
	}


	return 0;
}