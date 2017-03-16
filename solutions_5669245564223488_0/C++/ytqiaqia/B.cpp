#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#include <map>
using namespace std;

const long long mod = 1000000007L;

bool jd(string& ss)
{
	string sb = "";
	set<char> sa;
	if(ss.size()<=1)return true;
	sa.insert(ss[0]);
	sb += ss[0];
	for(int i = 1; i < ss.size(); ++i)
	{
		if(ss[i]!=ss[i-1])
		{
			if(sa.find(ss[i])!=sa.end())
				return false;
			sa.insert(ss[i]);
			sb+=ss[i];
		}
	}
	ss = sb;
	return true;
}
int T,N;
string s[101];
long long ans;
bool flag;

long long A[102] = {1};

bool hb()
{
	sort(s, s+N);
	//bool fff=true;
	vector<string> v;
	map<string, int> m;
	for(int i = 0; i< N;++i)
	{
		m[s[i]]++;
		//v.push_back(s[i]);
	}

	for(map<string,int>::iterator it=m.begin();it!=m.end();++it)
	{
		if(it->second>1&&it->first.size()>1)return false;
		v.push_back(it->first);
		ans= (ans*A[it->second])%mod;
	}
	while(true)
	{
		bool vis[101];
		memset(vis,false, sizeof(vis));
		bool ff = true;
		vector<string> vv;
		for(int i = 0; i < v.size()-1;++i)
		{
			if(vis[i])continue;
			for(int j = i+1; j < v.size(); ++j)
			{
				if(vis[j])continue;
				if(v[i][0]==v[j][v[j].size()-1])
				{
					if(v[i].size()==1&&v[j].size()==1)
					{
						ans=(ans*2)%mod;
						vv.push_back(v[i]);
						ff = false;
					}
					else
					{
						string ssss= v[j]+v[i];
						if(jd(ssss)==false) {flag=false; return false;}
						vv.push_back(ssss);
						ff = false;
					}
					vis[i]=vis[j]=true;break;
				}
				else if(v[j][0]==v[i][v[i].size()-1])
				{
						string ssss= v[i]+v[j];
						if(jd(ssss)==false) {flag=false; return false;}
						vv.push_back(ssss);
						ff = false;
						vis[i]=vis[j]=true;break;
				}
			}
		}
		for(int i = 0; i < v.size();++i)
		{
			if(vis[i]==false)vv.push_back(v[i]);
		}
		if(ff)break;
		v = vv;
		//for(int i = 0;i < v.size(); ++i)
		//{
			//cout<<"test: "<<v[i]<<endl;
		//}
	}
	string sx = "";
	for(int i = 0; i< v.size();++i)
		sx+=v[i];
	if(jd(sx)==false) return false;
	ans=(ans*A[v.size()])%mod;
	return true;
}


int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("B-small-attempt2.out","w",stdout);
	//freopen("A-large.in","r",stdin);
	//freopen("A-large.out","w",stdout);
	for(int i = 1; i< 101; ++i)
		A[i] = (A[i-1]*i)%mod;
	scanf("%d\n",&T);
	for(int cas = 1; cas <= T; ++cas)
	{
		ans = 1;
		scanf("%d",&N);
		flag = true;
		for(int i = 0; i < N; ++i)
		{
			cin>>s[i];
			if(jd(s[i])==false)flag = false;
		}
		if(!flag)
			printf("Case #%d: %d\n", cas, 0);
		else
		{
			if(hb()==false)
			{
				printf("Case #%d: %d\n", cas, 0);
			}
			else
			{
				printf("Case #%d: %d\n", cas, ans);
			}
		}
	}
	return 0;
}