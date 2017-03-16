#include<bits/stdc++.h>
using namespace std;

ifstream goo;
ofstream gle;
string s;
deque<char> q;

void solve()
{
	char c,a;
	goo>>s;
	for(int i=0; i<s.size(); i++)
	{
		c=s[i];
		a=q.front();
		if(c>=a) q.push_front(c);
		else q.push_back(c);
	}
	while(!q.empty())
	{
		c=q.front();
		gle<<c;
		q.pop_front();
	}
	gle<<"\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	goo.open("C:\\Users\\Mateusz\\Downloads\\A-large (1).in");
	gle.open("C:\\Users\\Mateusz\\Desktop\\gle.out");
	int t;
	goo>>t;
	for(int i=1; i<=t; i++)
	{
		gle<<"Case #"<<i<<": ";
		solve();
	}
	goo.close();
	gle.close();
	return 0;
}
