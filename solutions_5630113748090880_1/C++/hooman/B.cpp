#include<iostream>
#include<cstdio>
#include<set>

using namespace std;

int main()
{
	int T;
	scanf("%d ", &T);
	for(int t=1; t<=T; t++)
	{
		int N, n;
		set<int> l;
		scanf("%d ", &N);
		N = (2*N*N-N);
		while(N--)
		{
			scanf("%d ", &n);
			if(l.find(n) == l.end())
				l.insert(n);
			else
				l.erase(n);
		}
		cout<<"Case #"<<t<<":";
		for(set<int>::iterator it = l.begin(); it != l.end(); it++)
			cout << ' ' << *it;
		cout<<endl;
	}
	return 0;
}
