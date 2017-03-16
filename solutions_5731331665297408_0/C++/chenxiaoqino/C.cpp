#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

	int n;
	int val[51];
	int sval[51];
	int id2seq[51];
	int seq2id[51];
	int conn[51][51];

int debug=false;


string ansstr;
string recstr;
int root;
int visited[51],parent[51];


int bsvisited[51];
int bsrec(int cur, int par)
{
	if(conn[cur][par])return 1;
	bsvisited[cur]=1;
	int i;
	for(i=1;i<=n;i++)
	if(!visited[i])
	if(!bsvisited[i])
	if(conn[cur][i])
	{
		if(bsrec(i,par))return 1;
	}
	return 0;
}
int backsearch2root(int start, int par)
{
	memset(bsvisited,0,sizeof(bsvisited));
	return bsrec(start, par);
}

int footprint(int cur)
{
	char s[50];
	sprintf(s,"%d",val[cur]);
	ansstr+=s;
	
	sprintf(s,"%d-",cur);
	recstr+=s;
	visited[cur]=1;
	
	if(debug) cout<<"visiting:"<<cur;
	if(debug) cout<<"sr:"<<recstr<<endl;
	return 0;
}

int searchtree(int root)
{
	parent[root]=-1;
	int vcnt=1;
	int cur=root;
	
	//visited[root]=1;
	
	while(1)
	{
		if(cur==-1)return 0;
		if(!visited[cur])
		{
			footprint(cur);
		}
		//bool flag=false;
		
		int minmg=-1;
		int mingo=-1;
		
		for(int i=1;i<=n;i++)
		if(conn[cur][i])
		if(!visited[i])
		{
			if(! backsearch2root(i, parent[cur]))
			{
				if(minmg==-1)minmg=i;
				else if(val[minmg]>val[i])minmg=i;
			}
			else
			{
				if(mingo==-1)mingo=i;
				else if(val[mingo]>val[i])mingo=i;
			}
		}
		if(debug)cout<<"mmg"<<minmg<<":"<<mingo;
		if(minmg>0)
		{
			if(mingo==-1||val[minmg]<val[mingo])
			{parent[minmg]=cur;cur=minmg;continue;}
			else {parent[mingo]=cur;cur=mingo;continue;}
		}
		int curmingo=mingo;
		//else //if(minmg==-1)
		{
			
			int ptr=cur;
			while(ptr!=root)
			{
				ptr=parent[ptr];
					for(int i=1;i<=n;i++)
					if(conn[ptr][i])
					if(!visited[i])
					{
						if(val[mingo]>val[i])mingo=i;
					}
			}
			//if(mingo==-1)mingo=i;
			//else if(val[mingo]>val[i])mingo=i;
		}
		if(curmingo==mingo&&mingo>0)
		{parent[mingo]=cur;cur=mingo;continue;}
		else
		{
			if(debug) cout<<"nothing to do at"<<cur;
			cur=parent[cur];
			if(debug) cout<<"go parent"<<cur;
		}
	}
}

/*
int searchtree(int cur)
{
	char s[50];
	sprintf(s,"%d",val[cur]);
	ansstr+=s;
	
	sprintf(s,"%d-",cur);
	recstr+=s;
	cout<<"visiting:"<<cur;
	cout<<"sr:"<<recstr<<endl;
	visited[cur]=1;
	
	while(1)
	{
		int gomin=-1;int gominval=99999+1;
		
		int ismg[51];
		memset(ismg,0,sizeof(ismg));
		
		for(int i=1;i<=n;i++)
		if(!visited[i])
		if(conn[cur][i])
		{
			cout<<"check:"<<i;
			if(! backsearch2root(i))
			{
				cout<<"mustgo"<<endl;
				//searchtree(i);
				//flag=true;
				//break;
				ismg[i]=1;
			}
			//else
			{
				if(val[i]<gominval)
				{
					gominval=val[i];
					gomin=i;
				}
				//relax, write down
			}
		}
		//if(flag)continue;
		cout<<"mingo:"<<gomin<<"(from:"<<cur<<endl;
		if(gomin<0)break;
		//if not any, break;
		//go to minimum, if any
		//search again
		searchtree(gomin);		
	}
	
	return 0;
}
*/
int main()
{


int T,ti;
cin>>T;

for(ti=0;ti<T;ti++)
{
	//id=1..50

	ansstr=": ";
	recstr="-";
	
	int m,i,j,t1,t2;
	memset(conn,0,sizeof(conn));
	
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>val[i+1];
		sval[i+1]=val[i+1];
	}
	for(i=0;i<m;i++){
		cin>>t1>>t2;
		conn[t1][t2]=1;
		conn[t2][t1]=1;
	}
	sort(&sval[1],&sval[n+1]);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		if(sval[j]==val[i])
		{
			id2seq[i]=j;
			seq2id[j]=i;
		}
	}
	
	//start searching tree!
	memset(visited,0,sizeof(visited));
	root=seq2id[1];
	searchtree(root);
	
	cout<<"Case #"<<(ti+1);
	cout<<ansstr;
	
	cout<<endl;
}
return 0;
}