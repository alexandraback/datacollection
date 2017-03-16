#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)


int main()
{
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		string s;
		cin>>s;
		string t;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]+t >t+s[i])
				t=s[i]+t;
			else
				t=t+s[i];
		}
		cout<<"Case #"<<test<<": "<<t<<endl;
	}
	return 0;
}
