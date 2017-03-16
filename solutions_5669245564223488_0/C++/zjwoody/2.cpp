#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
	
	freopen("d:\\2.in", "r", stdin);
	freopen("d:\\2.txt", "w", stdout);
	
	int T;
	cin>>T;
	for(int kase = 1; kase <= T; ++kase)
	{
		int n;
		cin>>n;
		vector<string> str;
		for(int i = 0; i < n; ++i)
		{
			string tmp;
			cin>>tmp;
			
			string cur = "";
			cur += tmp[0];
			for(int i = 1; i < tmp.size(); ++i)
				if(tmp[i] != tmp[i-1])
					cur += tmp[i];			
			str.push_back(cur);
		}
		
		int order[100];
		for(int i = 0; i < n; ++i)
			order[i] = i;
		
		int ans = 0;
		do
		{
			string cur = "";
			for(int i = 0; i < n; ++i)
				cur += str[order[i]];
			
			bool vis[200];
			memset(vis,false, sizeof(vis));
			vis[cur[0]] = true;
			bool ok = true;
			for(int i = 1; i < cur.size(); ++i)
			{
				if(cur[i] != cur[i-1] && vis[cur[i]])
				{
					ok = false;
					break;
				}
				vis[cur[i]] = true;
			}
			if(ok)
				ans++;
		}while(next_permutation(order, order+n));
		
		cout<<"Case #"<<kase<<": "<<ans<<endl;
	}
	
	return 0;
}
