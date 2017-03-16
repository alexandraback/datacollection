#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
ifstream cin("B-small-attempt1.in");
ofstream cout("out.txt");

const long long mod=1000000007;
string a[100];
bool v[100];
int n;
long long ans;
int check[40];
int check1[40];
char noww[1050];

bool checker(string now)
{
	int i,k;
	for (i=0;i<=29;i++)
		check1[i]=-1;
	for (i=0;i<now.length();i++)
	{
		k=now[i]-'a';
		if (check1[k]!=-1&&check1[k]!=i-1)
			break;
		check1[k]=i;
	}
	if (i==now.length())
		return true;
	return false;
}

void work(int x,int p)
{
	int i,j,k;
	if (x==n+1)
	{
		for (i=0;i<=29;i++)
			check[i]=-1;
		for (i=0;i<p;i++)
		{
			k=noww[i]-'a';
			if (check[k]!=-1&&check[k]!=i-1)
				break;
			check[k]=i;
		}
		if (i==p)
			ans=(ans+1)%mod;
		return;
	}
	for (i=1;i<=n;i++)
		if (!v[i])
		{
			v[i]=1;
			for (j=0;j<a[i].length();j++)
			{
				noww[p+j]=a[i][j];
			}
			work(x+1,p+a[i].length());
			v[i]=0;
		}
}

int main()
{
	int t,i,j,k,count=0;
	cin>>t;
	while (t--)
	{
		count++;
		cin>>n;
		for (i=1;i<=n;i++)
			cin>>a[i];
		memset(v,0,sizeof(v));
		ans=0;
		work(1,0);
		cout<<"Case #"<<count<<": ";
		cout<<ans<<endl;
	}
	return 0;
}