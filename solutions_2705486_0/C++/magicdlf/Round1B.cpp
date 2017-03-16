// Round1B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "string.h"
#include "stdio.h"
#include "fstream"

using namespace std;
	
vector<string> dict;

struct node
{
	int idx;
	int len;
	int changed;
};

int visited[4005][4005]={};
int check(int &idx, string &word, string &str, int &cur)
{
	if(cur+word.size()>str.size())
		return -1;
	int changed=0;
	for(int i=0;i<word.size();i++,cur++)
	{
		if(str[cur]!=word[i])
		{
			if(idx==4004)
			{
				idx=cur;
				changed++;
			}
			else if(cur-idx>=5)
			{
				idx=cur;
				changed++;
			}
			else
			{
				return -1;
			}
		}
	}
	return changed;
}

int bfs(string str)
{
	memset(visited,-1,sizeof(visited));
	node start={4004,0,0};
	vector<node> queue;
	queue.push_back(start);
	int p=0,q=1;
	while(p<q)
	{
		int idx=queue[p].idx;
		int len=queue[p].len;
		int changed=queue[p].changed;
		for(int i=0;i<dict.size();i++)
		{
			int idx2=idx,len2=len;
			int ret=check(idx2,dict[i],str,len2);
			if(ret<0) continue;
			if(visited[len2][idx2]==-1 || visited[len2][idx2]>changed+ret)
			{
				visited[len2][idx2]=changed+ret;
				node next={idx2,len2,changed+ret};
				queue.push_back(next);
			}
		}
		p++;
		if(p==q)
		{
			q=queue.size();
		}
	}
	int best=str.size();
	for(int i=0;i<4005;i++)
	{
		if(visited[str.size()][i]==-1) continue;
		best=min(best,visited[str.size()][i]);
	}
	return best;
}

int main()
{
	ifstream fin("garbled_email_dictionary.txt");
	while(!fin.eof())
	{
		string str;
		fin>>str;
		dict.push_back(str);
	}
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		string str;
		cin>>str;
		int ans=bfs(str);
		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}
	return 0;
}