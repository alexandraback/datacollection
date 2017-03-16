#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n;
string arr[11];
int visited[11];
vector <string> tp;

int vals(string s)
{
	string tps="";
	int index=0;
	tps += s[0];
	for(int i=0;i<s.length();i++)
	{
		if( tps[index]==s[i] );
		else
		{
			tps += s[i];
			index += 1;
		}
	}
	int alp[26];
	for(int i=0;i<26;i++) alp[i]=0;
	for(int i=0;i<tps.length();i++)
	{
		if(alp[tps[i]-'a']==1) return 0;
		alp[tps[i]-'a']=1;
	}
}

long long an(int index)
{
	long long toret=0;
	visited[index]=1;
	tp.push_back(arr[index]);
	
	int alp[26];
	for(int i=0;i<26;i++) alp[i]=0;
	
	
	string lols="";
	// validate tp vector	
	for(int i=0;i<tp.size();i++)
	{
		lols += tp[i];
	}
	
	if(!vals(lols)) 
	{
		visited[index]=0;
		tp.pop_back();
		return 0;
	}
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0) toret += an(i);
	}
	
	if(tp.size()==n) toret = 1;
	
	visited[index]=0;
	tp.pop_back();
	return toret;
}


int main()
{
	int t;
	cin>>t;
	for(int tc=1;tc<=t;tc++)
	{
		long long ans = 0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			visited[i]=0;
		}
		for(int i=0;i<n;i++)
		{
			ans += an(i);
		}
		cout<<"Case #"<<tc<<": "<<ans%1000000007<<"\n";
	}
	return 0;
}
