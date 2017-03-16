#include<iostream>
#include<string>
#include<queue>
using namespace std;

int T=0;
int num=0;
void Gao()
{
	string s;
	deque<char> q;
	printf("Case #%d: ",++num);
	cin>>s;
	for (int i=0;i<s.length();i++)
	{
		if (i==0)
		{
			q.push_front(s[i]);
		}
		else
		{
			if (s[i]>=q.front())
				q.push_front(s[i]);
			else
				q.push_back(s[i]);
		}
	}
	while (!q.empty())
	{
		cout<<q.front();
		q.pop_front(); 
	}
	cout<<endl;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	cin>>T;
	while (T--)
		Gao();
} 
