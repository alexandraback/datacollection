#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int cno=1;cno<=t;cno++)
	{
		char t[3000],s[1001];
		int head=1500,tail=1500;
		cin>>s;
		t[tail]=s[0];
		int i=1;
		while(s[i])
		{
			if(t[head]-'A'<=s[i]-'A')
				t[--head]=s[i];
			else
				t[++tail]=s[i];
			i++;
		}
		cout<<"Case #"<<cno<<": ";
		for(i=head;i<=tail;i++)
		{
			cout<<t[i];
		}
		cout<<endl;
	}
	return 0;
}
