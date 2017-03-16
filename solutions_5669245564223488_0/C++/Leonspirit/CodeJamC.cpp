#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#define Ari using
#define ganteng namespace
#define banget std

#define ll long long
#define ul unsigned long long
#define pb push_back
#define mp make_pair
#define lcm(a,b) a*b/__gcd(a,b)
#define lsb(a) (a & (-a))
#define ft first
#define sc second
#define inf 10000000
#define mod 1000000007

#define STRtoINT(a,b) istringstream(a)>>b
#define INTtoSTR(a,b) b=static_cast<ostringstream*>(&(ostringstream()<<a))->str()

//set -> pair <set<int>::iterator,bool> pa; pa=set.insert(x); pa.second return bool;

template<typename t>
t getnum()
{
 t res=0;
 char c;
 int sign=1;
 while(1){
	c=getchar();
	if(c==' '||c=='\n')continue;
	else break;}
 if(c=='+'){}
 else if(c=='-')sign=-1;
 else res=c-'0';
 while(1){
	c=getchar();
	if(c>='0'&&c<='9')res=res*10+c-'0';
	else break;}
return res*sign;
}

Ari ganteng banget;

int parent[50];
ll fakt[105];

int cek(int id)
{
	if(parent[id]==id)return id;
	else return parent[id]=cek(parent[id]);
}

int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("output.txt","w",stdout);
	fakt[0]=0;
	fakt[1]=1;
	for(ll x=2;x<=102;x++)
	{
		fakt[x]=fakt[x-1]*x;
		fakt[x]%=mod;
		//cout<<fakt[x]<<endl;
	}
	
	int testcase=getnum<int>();
	for(int tc=1;tc<=testcase;tc++)
	{
		int ketemu[50][50];
		memset(ketemu,0,sizeof ketemu);
		bool g=true,visited[50];
		memset(visited,false,sizeof visited);
		char ss[105][105];
		int train=getnum<int>();
		
		for(int x=0;x<train;x++)
		{
			scanf("%s",ss[x]);
			bool pemisah=false;
			int t1=ss[x][0]-'a',t2=ss[x][strlen(ss[x])-1]-'a';
			for(int y=0;y<strlen(ss[x]);y++)
			{
				//cout<<visited[ss[x][y]-'a']<<endl;
				if(ss[x][y]-'a' ==t1){if(visited[ss[x][y]-'a']==true)g=false;}
				else if(ss[x][y]-'a' ==t2){if(visited[ss[x][y]-'a']==true)g=false;}
				else {if(visited[ss[x][y]-'a']==true)g=false; 
				if(ss[x][y]!=ss[x][y+1])visited[ss[x][y]-'a']=true;
				pemisah=true;}
			}
			//cout<<endl;
			if(pemisah==true && t1==t2)g=false;
			ketemu[ss[x][0]-'a'][ss[x][strlen(ss[x])-1]-'a']++;
		}

		for(int x=0;x<=27;x++)
		{
			for(int y=0;y<=27;y++)
			{
				if(x!=y)
				{
					if(ketemu[x][y]>1)g=false;
				}
			}
		}
		for(int x=0;x<=27;x++)
		{
			for(int y=x+1;y<=27;y++)
			{
				if(ketemu[x][y]>=1 && ketemu[y][x]>=1)g=false;
			}
		}
		for(int x=0;x<=27;x++)
		{
			int temp=0;
			for(int y=0;y<=27;y++)
			{
				if(x!=y)temp+=ketemu[x][y];		
			}
			if(temp>1)g=false;
		}
		for(int x=0;x<=27;x++)
		{
			int temp=0;
			for(int y=0;y<=27;y++)
			{
				if(x!=y)temp+=ketemu[y][x];
			}
			if(temp>1)g=false;
		}
		//if(train==1)printf("Case #%d: 1\n",tc);
		if(g==false)printf("Case #%d: 0\n",tc);
		else
		{
			ll res=1;
			int found=0;
			ll ans[50];
			
			for(int x=0;x<=27;x++)
			{
				ans[x]=fakt[ketemu[x][x]];
				//cout<<x<<" "<<ans[x]<<endl;
			}
			for(int x=0;x<=27;x++)parent[x]=x;
			
			for(int x=0;x<27;x++)
			{
				int next=-1;
				for(int y=0;y<=27;y++)
				{
					if(x!=y)
					{
						if(ketemu[x][y]==1)next=y;
					}
				}
				if(next!=-1)
				{
				
					if(cek(x)==cek(next))g=false;
					else
					{
					//	cout<<x<<" "<<cek(x)<<" "<<next<<" "<<cek(next)<<endl;
						if(ans[cek(next)]==0)ans[cek(next)]=1;
						if(ans[cek(x)]==0)ans[cek(x)]=1;
						ans[cek(next)]*=ans[cek(x)];
						ans[cek(next)]%=mod;
						ans[cek(x)]=0;
						parent[cek(x)]=cek(next);
					
					}
				}
			}
			if(g==false)printf("Case #%d: 0\n",tc);
			else
			{
				//cout<<"hai"<<r<<endl;
				
				for(int x=0;x<=27;x++)
				{
					if(parent[x]==x && ans[x]>0)
					{
						//cout<<x<<" "<<ans[x]<<endl;
						res*=ans[x];
						res%=mod;
						found++;
					}
				}
				//cout<<found<<endl;
				res*=fakt[found];
				res%=mod;
				printf("Case #%d: %lld\n",tc,res);
			}
		}
		
	}
	
  return 0;
}

