#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int expand(int& t,int large)
{
	int ans=0;
	while(t <= large)
	{
		++ans;
		t += t-1;
	}
	t += large;
	return ans;
}
int Num[200];
int main()
{
	int T;
	cin >> T;
	int idx=0;
	while(T--)
	{
		++idx;
		int A,N;
		cin >> A >> N;
		for(int i=0;i<N;++i)
			cin >> Num[i];
		sort(Num,Num+N);
		if(A==1)
		{
			cout << "Case #"<<idx<<": "<<N<<endl;
			continue;
		}
		int fans = N;
		for(int last=N-1;last>=0;--last)
		{
			int tans=0,ts=A;
			for(int i=0;i<=last;++i)
				tans += expand(ts,Num[i]);
			tans += N-1-last;
			if(last==N-1 || tans<fans)
				fans = tans;
		}
		if(fans > N)fans=N;
		cout << "Case #"<<idx<<": "<<fans<<endl;
	}
}
