#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#define int long long

//*******************
//*******************

void read() {
	int B, M; cin>>B>>M;
	if ( 1UL<<(B-2) < M)
		{ cout<<"IMPOSSIBLE"<<endl; return; }
	cout<<"POSSIBLE"<<endl;

	if(M == 1UL<<(B-2))
	{
		cout<<0;
		for(int i=0; i<B-1; i++)
			cout<<1;
		cout<<endl;
	}
	else
	{
		stack <int > s;
		while( M > 0)
		{
			s.push(M%2);
			M/=2;
		}
		for(int i=0; i<B - s.size() - 1; i++)
			cout<<0;
		while(!s.empty())
		{
			int u = s.top(); s.pop();
			cout<<u;
		}
		cout<<0<<endl;
		// cout<<endl;
	}
	
	for(int i=2; i<=B; i++)
	{
		for(int j=1; j<=i; j++)
			cout<<0;
		for(int j=i+1; j<=B; j++)
			cout<<1;
		cout<<endl;
	}
}

void solve() {

}

void clean() {
	
}

 main() {
	ios::sync_with_stdio(false);
	int z;
	cin >> z;
	for(int zz=1; zz<=z; zz++)
	{

	cout<<"Case #"<<zz<<": ";
		read();
		solve();
		clean();
	}
  return 0;
}