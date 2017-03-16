#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int A , N ;

int a[1000];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int task;
	cin >> task;
	for (int cases = 1; cases <= task; cases++)
	{
		cin >> A >> N;
		for (int i = 0; i < N; i++)
			cin >> a[i];
		sort(a , a + N);
		int ans = N;
		if (A != 1)
		for (int del = N; del >= 0; del--)
		{
			int tmp = N - del;
			int s =  A;
			int i = 0;
			while (i < del)
			{
				if (a[i] < s)
				{
					s = s + a[i] ; 
					i++;
				} else
				{
					s = s * 2 - 1;
					tmp++;
				}
			}
			if (tmp < ans) ans = tmp;
		}
		cout << "Case #" << cases << ": " << ans << endl;
	}
	
	return 0;
}