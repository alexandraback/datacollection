#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip> 

using namespace std;

int main()
{
	freopen ("B-small-attempt0.in","r", stdin);
	//freopen("test","r",stdin);
	freopen ("out.txt","w",stdout);
	int k;
	cin >> k;
	for(int s = 0; s < k; s++)
	{
		cout << "Case #" << s + 1 << ": ";
		int A,B,K;
		cin >> A >> B >> K;
		//cout << A << " " << B << " " << K << endl;
		int res = 0;
		for(int i = 0; i < A; i++)
			for(int j = 0; j < B; j++)
			{
				int n = i & j;
				if(n < K)
				{
					res++;
				}
			}
		
		cout << res << endl;
	}
}
