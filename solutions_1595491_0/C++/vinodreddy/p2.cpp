#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int checks(int n,int p)
{
	int x;
	if(n%3 == 2)
	{
		x = (n/3)+2;
	}
	else x = (n/3)+1;
	if(x < p)return 0;
	return 1;
}
int checkn(int n,int p)
{
	int x = (n/3)+(n%3 != 0);
	if(x < p) return 0;
	return 1;
}
int main()
{
	int t;
	cin >> t;
	int nt = 1;
	while(nt++ <= t)
	{
		cout << "Case #" << nt-1 << ": ";
		int n,s,p;
		cin >> n >> s >> p;
		vector<int> A(n,0);
		for(int i = 0;i < n;i++)
		{
			cin >> A[i];
		}
		sort(A.begin(),A.end());
		int i= 0;
		int count = 0;
		int ts = 0;
		for(;i < n;i++)
		{
			int cs = checks(A[i],p);
			int cn = checkn(A[i],p);
			if(A[i] == 0)
			{
				if(p == 0) count += 1;
				continue;
			}
			if(cn)
			{
				count += 1;
				continue;
			}
			if(cs)
			{
				if(ts < s)
				{
					count += 1;
					ts += 1;
					continue;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}
