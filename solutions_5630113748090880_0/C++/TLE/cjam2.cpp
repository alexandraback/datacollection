#include <bits/stdc++.h>
using namespace std;

int w[5000];

int main()
{
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	int T;
	cin>>T;
	for (int ts=1;ts<=T;ts++)
	{
		cout<<"Case #"<<ts<<": ";
		int N; cin>>N;
		memset(w,0,sizeof(w));
		for (int i=1;i<N*2;i++)
		for (int j=1;j<=N;j++)
		{
			int x;
			cin>>x;
			w[x]++;
		}
		vector<int> t;
		for (int i=1;i<=5000;i++)
		{
			if (w[i]%2==1)
				t.push_back(i);
		}
		sort(t.begin(),t.end());
		for (int i=0;i<t.size();i++)
			cout<<t[i]<<" ";
		cout<<endl;
	}



	return 0;
}