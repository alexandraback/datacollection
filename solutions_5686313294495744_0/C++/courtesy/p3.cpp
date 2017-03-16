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
string a[16][2];
int n;
int ch[16];
int an;
void fn()
{
	int i,j,k;
	map<string,int> mp1,mp2;
	for(i=0;i<n;i++)
	{
		if(ch[i])
		{
			mp1[a[i][0]]=1;
			mp2[a[i][1]]=1;
		}
	}
	k=0;
	for(i=0;i<n;i++)
	{
		if(!ch[i])
		{
			if(mp1[a[i][0]] && mp2[a[i][1]])k++;
		}
	}
	if(k>an)an=k;
}
void fun(int c)
{
	if(c==n)
	{
		fn();
		return;
	}
	ch[c]=0;
	fun(c+1);
	ch[c]=1;
	fun(c+1);
	ch[c]=0;
}
int main()
{
	int t,i,j,k,cs,css;
	cin>>css;
	for(cs=1;cs<=css;cs++)
	{
		cin>>n;
		an=0;
		for(i=0;i<n;i++)cin>>a[i][0]>>a[i][1];
		fun(0);
		cout<<"Case #"<<cs<<": ";
		cout<<an<<endl;
	}
	return 0;
}
