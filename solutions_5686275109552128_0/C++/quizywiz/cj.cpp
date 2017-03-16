#include <bits/stdc++.h>
using namespace std;
int t;
int d,p;
priority_queue<int> q[2];

int main() {
	// your code goes here
	cin>>t;
	for(int cc=1;cc<=t;++cc)
	{
		cout<<"Case #"<<cc<<": ";
		cin>>d;
		for(int i=0;i<d;++i)
		{
			cin>>p;
			q[0].push(p);
		}
		int maxans = q[0].top();
		int ans = q[0].top();
		int qu=0;
		int ov = 0;
		for(int i=0;i<maxans;++i)
		{
			if(q[qu].top() + ov<ans)ans=q[qu].top()+ov;
			++ov;
			auto x = q[qu].top();
			q[qu].pop();
			q[qu].push(x/2);
			q[qu].push(x - x/2);

		}
		cout<<ans<<endl;
	}	
	return 0;
}