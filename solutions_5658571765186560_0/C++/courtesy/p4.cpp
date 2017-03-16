/*  Vivek Kantariya  */
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#define PB push_back
#define pii pair<int,int>
#define MP make_pair
#define sz size()
#define fi first
#define se second
using namespace std;
typedef long long ll;
int x,r,c;
bool fun()
{
	if((r*c)%x!=0)return false;
	if(x==1 || x==2)return true;
	int i,j,k;
	if(r>c)
	{
		k=r;r=c;c=k;
	}
	if(x==3)
	{
		if(r==1)return false;
		return true;
	}
	if(r==1)return false;
	if(r==2)return false;
	return true;
}
int main()
{
	int t,i,j,k,cs,css;
	cin>>css;
	for(cs=1;cs<=css;cs++)
	{
		cout<<"Case #"<<cs<<": ";
		cin>>x>>r>>c;
		if(fun())cout<<"GABRIEL\n";
		else cout<<"RICHARD\n";
	}
	return 0;
}
