#include<bits/stdc++.h>
using namespace std;
int n,ans;
vector<string> data;
//void dfs(int i,vector<bool> used,string s)
//{
//	if(i==n)
//	{
//	}
//	string tmp;
//	for(int j=0;j<n;j++)
//	{
//		if(used[j]==0)
//		{
//			tmp=s; tmp+=data[j];
//			used[i]=1;
//			dfs(i+1,used,tmp);
//			used[i]=0;
//		}
//	}
//}
bool check(string s)
{
	bool used[256]={0};
	used[s[0]]=1;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]!=s[i-1] && used[s[i]]==1)
			return 0; 
		used[s[i]]=1;
	}
	return 1;
}
int main()
{
	int T;
	cin>>T;
	for(int no=1;no<=T;no++)
	{
		cin>>n;
		data.resize(n);
		for(int i=0;i<n;i++){
			cin>>data[i];
			data[i]+=char(i+1);
		}
		ans=0;
//		vector<bool> used(n);
//		dfs(0,used,"");
		sort(data.begin(),data.end());
		do
		{
			string temp="";
			for(int i=0;i<n;i++){
				temp+=data[i];
				temp.resize(temp.size()-1);
			}
			if(check(temp)){
				ans++;
//				clog<<"-----"<<temp<<endl;
			}
		}while(next_permutation(data.begin(),data.end()));
		printf("Case #%d: %d\n",no,ans);
	}
}

