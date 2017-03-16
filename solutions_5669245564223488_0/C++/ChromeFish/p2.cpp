#include<fstream>
#include<algorithm>
#include<vector>
#include <iomanip>  
#include<string>
using namespace std;

ifstream in("b.in");
ofstream out("b.out");

int t, n;
string st[110];
string ss[110];
int len[110];
bool vis[27];
int cnt[30];
int cnt2[30];
int cnt3[30];
int f[27];
int head[27];
int g[27][27];
long long ans;


int main()
{
	in>>t;
	for (int i=1; i<=t; i++)
	{
		ans=0;
		in>>n;
		for (int j=0; j<n; j++)
		{
			in>>st[j];
			ss[j]="";
			len[j]=st[j].length();
		}
		for (int j=0; j<30; j++)
			cnt[j]=0;
		for (int j=0; j<n; j++)
		{
			ss[j]+=st[j][0];
			for (int l=1; l<len[j]; l++)
				if (st[j][l]!=st[j][l-1])
					ss[j]+=st[j][l];
		}
		for (int j=0; j<26; j++)
		{
			f[j]=-1;
			cnt[j]=0;
			cnt2[j]=0;
			cnt3[j]=0;
			vis[j]=0;
			head[j]=1;
		}
		for (int j=0; j<n; j++)
			for (int k=1; k<ss[j].length()-1; k++)
				f[ss[j][k]-'a']=j;
		bool flag=1;
		for (int j=0; j<n; j++)
			for (int k=0; k<ss[j].length(); k++)
				if (f[ss[j][k]-'a']!=-1 && f[ss[j][k]-'a']!=j)
				{
					flag=0;break;
				}
		if (flag)
		{
			for (int j=0; j<n; j++)
			{
				vis[ss[j][0]-'a']=1;
				if (ss[j][0]==ss[j][ss[j].length()-1])
				{
					cnt[ss[j][0]-'a']++;
				}
				else
				{
					cnt2[ss[j][ss[j].length()-1]-'a']++;
					cnt3[ss[j][0]-'a']++;
					head[ss[j][ss[j].length()-1]-'a']=0;
				}
			}
			for (int j=0; j<26; j++)
				if (cnt2[j]>1 || cnt3[j]>1)
				{
					flag=0;break;
				}
			if (flag)
			{
			ans=1;
			int sum=0;
			for (int j=0; j<26; j++)
				if (vis[j] && head[j])
					sum++;
			if (sum==0) ans=0;
			for (int j=1; j<=sum; j++)
				ans*=j;
			for (int j=0; j<26; j++)
				for (int k=1; k<=cnt[j]; k++)
					ans=ans*k;
			}
		}
		out<<"Case #"<<i<<": "<<ans<<endl;; 
	}
}