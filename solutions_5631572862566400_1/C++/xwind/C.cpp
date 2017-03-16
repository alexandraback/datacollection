#include<bits/stdc++.h>
using namespace std;

const int maxn=1001;
const int inf=1e9+100;
int go[maxn],ind[maxn],dis[maxn];
bool vis[maxn],on[maxn];
vector<int> mp[maxn];
stack<int> st;
deque<int> q,nq,sq;
bool dfs(int u)
{
	st.push(u);
	vis[u]=true;	
	if(!vis[go[u]])
	{
		if(dfs(go[u]))return true; 
		return false;
	}
	else
	{
		while(st.top()!=go[u])
		{
			dis[st.top()]=0;
			q.push_back(st.top());
			st.pop();
		}
		dis[st.top()]=0;
		q.push_back(st.top());
		st.pop();
		return true;
	}
}
int main()
{
	int n,T,u,v;
	scanf("%d",&T);
	for(int cas=1;cas<=T;++cas)
	{
		memset(ind,0,sizeof(ind));
		memset(vis,0,sizeof(vis));
		//cerr<<cas<<endl;
		scanf("%d",&n);
		if(cas==45)cerr <<n<<endl;
		for(int i=1;i<=n;++i)mp[i].clear();
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&go[i]);
			if(cas==45)cerr <<go[i]<<" ";
			++ind[go[i]];
			mp[go[i]].push_back(i);
		}
		if(cas==45)cerr<<endl;
		int res=0,tmp,dist=0,rd=0,num=0;
		for(int i=1;i<=n;++i)
			if(!vis[i])
			{
				while(!nq.empty())nq.pop_front();
				while(!q.empty())q.pop_front();
				while(!sq.empty())sq.pop_front();
				while(!st.empty())st.pop();
				dfs(i);
				memset(on,0,sizeof(on));
				memset(dis,0,sizeof(dis));
				tmp=q.size();
				for(deque<int>::iterator it=q.begin();it!=q.end();++it)vis[*it]=true,sq.push_back(*it),on[*it]=true;
				while(!sq.empty())
				{
					u=sq.front();sq.pop_front();
					if(ind[u]==0)nq.push_back(u);
					vis[u]=true;
					for(int i=0;i<mp[u].size();++i)
					{
						v=mp[u][i];
						if(!on[v])sq.push_back(v);
					}
				}
				if(tmp==2)
				{
					dist=0;
					//for(deque<int>::iterator it=nq.begin();it!=nq.end();++it)cout <<*it<<" ";cout <<endl;
					while(!nq.empty())
					{
						u=nq.front();
						nq.pop_front();
						v=go[u];
						if(dis[v]<dis[u]+1)
						{
							dis[v]=dis[u]+1;
							if(!on[v])nq.push_back(v);
						}
					}
					bool flag=false;
					for(deque<int>::iterator it=q.begin();it!=q.end();++it)
					{
						if(!dis[*it])flag=true;
						dist+=dis[*it];
					}
					//for(deque<int>::iterator it=q.begin();it!=q.end();++it)cout <<"it:"<<*it<<" "<<dis[*it]<<endl;
					//cout <<q.size()<<" "<<dist<<endl;
					if(flag)
						num+=(2+dist);
					else 
					{
						num+=2;
						rd=max(rd,dist); 
					}
				}
				else res=max(res,tmp);
			}
		if(cas==45)cerr <<res<<" "<<num+rd<<" "<<num<<endl;
		printf("Case #%d: %d\n",cas,max(res,num+rd));
	}
	return 0;
}
