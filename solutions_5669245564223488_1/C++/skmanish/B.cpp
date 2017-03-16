#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int ll;
int n;
bool flag[26];
char inp[105][105];
ll mat[26][26];
void process(char inp[])
{
	int i,l=strlen(inp);
	vector<int> v;
	char ch='a';
	v.push_back(inp[0]-'a');
	for(i=1;i<l;i++)
		if((inp[i]-'a')!=v[v.size()-1])
			v.push_back((inp[i]-'a'));
	for(i=1;i<(v.size()-1);i++)
		flag[v[i]]=false;
	mat[v[0]][v[v.size()-1]]++;
	if(v[0] == v[v.size()-1] && v.size()>1)flag[v[0]]=false;
}
bool check()
{
	int i,j;
	for(i=0;i<26;i++)
		for(j=0;j<26;j++)
			{if(j==i)continue;if(mat[i][j]>1)return 0;}
	return 1;
}
ll fact(ll n)
{
	if(n==0)return 1;
	else return (n*fact(n-1))%MOD;
}
void print()
{
	int i,j;
	for(i=0;i<20;i++,putchar('\n'))
	for(j=0;j<20;j++)
		cout<<mat[i][j]<<" ";
}
ll solve()
{
	if(!check())return 0;
	//print();cout<<endl;
	int i,j,x,y;
	ll res=0;
	for(i=0;i<26;i++)
	{
		ll N=0,r1=0,r2=0;
		x=y=i;
		for(j=0;j<26;j++)
		{
			if(j==i)continue;
			if(r1 && mat[j][i]!=0)return 0;
			if(mat[j][i]){x=j;r1 = mat[x][i];}
		}
		for(j=0;j<26;j++)
		{
			if(j==i)continue;
			if(r2 && mat[i][j]!=0)return 0;
			if(mat[i][j]){y=j;r2 = mat[i][y];}
		}
		N = mat[i][i];
		if(!flag[i] && (r1+r2+N)!=0)return 0;
		if(r1==0 && r2==0) {if(N!=0)mat[i][i] = fact(mat[i][i]);continue;}
		if(r1==0) 		{x=i;res = (fact(N)*r2)%MOD;}
		else if(r2==0) 	{y=i;res = (fact(N)*r1)%MOD;}
		else 			res = (((r1*fact(N))%MOD)*r2)%MOD;
		if(r1*r2!=0 && x==y) return 0;
		mat[x][i] = mat[i][y] = mat[i][i] = 0;
		mat[x][y] = res;
	}
	//print();
	ll count=0;
	res=1;
	for(i=0;i<26;i++)
		for(j=0;j<26;j++)		
			if(mat[i][j]!=0){res=(res*mat[i][j])%MOD;count++;}
	return (fact(count)*res)%MOD;
}
int main()
{
	int t,tt,i;
	cin>>t;
	for(tt=1;tt<=t;tt++)
	{
		cin>>n;
		for(i=0;i<26;i++)flag[i]=true;
		memset(mat,0,sizeof(mat));
		for(i=0;i<n;i++)
		{
			scanf("%s",inp[i]);
			process(inp[i]);
		}
		//for(i=0;i<26;i++)cout<<flag[i]<<" ";cout<<endl;
		printf("Case #%d: %lld\n",tt,solve());
	}
	return 0;	
}
