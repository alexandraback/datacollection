#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("b_large.in", "r", stdin);
	freopen("b_large.out", "w", stdout);
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	for (int case_num = 1; case_num <= t; ++case_num)
	{
		int d;
		cin>>d;
		vector <int> A(d);
		for (int i = 0; i < d; ++i)
		{
			cin>>A[i];
		}
		int fans=1000000000;
		for (int i = 1; i <= 1000; ++i)
		{
			int et=0;
			for (int j = 0; j < d; ++j)
			{
				et+=(A[j]-1)/i;
			}
			fans=min(fans,i+et);
		}
		cout<<"Case #"<<case_num<<": "<<fans<<"\n";
	}
	return 0;
}