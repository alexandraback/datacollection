#include <iostream>
#define mod 1000000007
#include<cstdio>
#include<stack>
#include<string>
using namespace std;
string s[110],tmp;
stack <string> v[30];
int visit[110];
//int check[110][30];
int choose[110];
int front,back,both;
int st,cnt;
long long ans;
long long fact[110];
int aa[1000];
int check(int x,int y)
{
	for(int i=0;i<s[x].size();i++) if(s[x][i]==y+'a') return 1;
	return 0;
}
void solve(int tt)
{
	for(int i=0;i<=100;i++) visit[i]=0;
	//for(int i=0;i<=100;i++) for(int j=0;j<=26;j++) check[i][j]=0;
	for(int i=0;i<=26;i++) while(!v[i].empty()) v[i].pop();
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
		//for(int j=0;j<s[i].size();j++) check[i][s[i][j]-'a']=1;
		//v[tmp[0]-'a'].push(tmp);
	}
	ans=1;
	for(int j=0;j<26;j++)
	{
		front=0;back=0;both=0;cnt=0;
		for(int i=0;i<n;i++) choose[i]=0;
		for(int i=0;i<n;i++)
		{
			if(visit[i]==0&&check(i,j)==1)
			{
				if(s[i][0]=='a'+j && s[i][s[i].size()-1]=='a'+j)
				{
					both++;
					choose[i]=2;
				}
				else if(s[i][0]=='a'+j)
				{
					front++;
					choose[i]=1;
				}
				else if(s[i][s[i].size()-1]=='a'+j)
				{
					back++;
					choose[i]=3;
				}
			}
		}
		//cout << front << " " << both << " " << back << endl;
		if(front > 1 || back > 1) {ans=0;return;}
		if(front+back+both==1) continue;
		if(back>0)
			for(int i=0;i<n;i++) {if(choose[i]==3) st=i;}
		else
		{
			for(int i=0;i<n;i++) if(choose[i]==2)
			{
				st=i;
				choose[i]=3;
				cnt++;
				break;
			}
		}
		//cout << st << " " << choose[st] << endl;
		for(int i=0;i<n;i++) if(choose[i]==2)
		{
			cnt++;
			s[st]=s[st]+s[i];
			visit[i]=1;
		}
		for(int i=0;i<n;i++) if(choose[i]==1)
		{
			s[st]=s[st]+s[i];
			visit[i]=1;
		}
		ans=ans*fact[cnt]%mod;
		//for(int i=0;i<n;i++) cout << s[i] << " ";
		//cout << endl;
	}
	cnt=0;
	for(int i=0;i<n;i++) if(visit[i]==0) cnt++;
	ans=ans*fact[cnt]%mod;
	string ttt;
	ttt.clear();
	for(int i=0;i<n;i++) if(visit[i]==0) ttt=ttt+s[i];
	//cout << endl << ttt << endl;
	int z=ttt.size();
	for(int i=0;i<=26;i++) aa[i]=0;
	aa[ttt[0]-'a']=1;
	//cout << ans << endl;
	for(int i=1;i<z;i++)
	{
		if(aa[ttt[i]-'a']==0)
		{
			aa[ttt[i]-'a']=1;
		}
		else if(ttt[i]!=ttt[i-1])
		{
			//cout << i << " " << ttt[i] << endl;
			ans=0;return;
		}
	}
	return;
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	fact[0]=1;
	for(long long i=1;i<=100;i++) fact[i]=fact[i-1]*i%mod;
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		solve(i);
		printf("Case #%d: %lld\n",i+1,ans);
	}
}