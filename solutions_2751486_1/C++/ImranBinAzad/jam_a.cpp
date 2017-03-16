#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<iomanip>
#include<fstream>

#include<string>
#include<utility>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#define ii long long int
#define pi 2*acos(0.0)
#define eps 1e-9
#define mem(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(a) (int)a.size()
#define inf 2147483640

#define mx 1000010

using namespace std;

const int debug= 0;

ii par[1000010];
char s[1000010],s2[1000010];

void failure()
{
	ii i,len= strlen(s2+1),k= 0;
	par[1]= 0;
	par[0]= 0;

	for (i=2; i<=len; ++i)
	{
		while (k>0 && s2[k+1]!=s2[i])
			k= par[k];

		if (s2[k+1]==s2[i]) k++;
		par[i]= k;
	}
}

ii match()
{
	ii len1= strlen(s+1),len2= strlen(s2+1),k= 0,i,ans= 0;
	ii start= 1;
	
	for (i=1; i<=len1; ++i)
	{
		while (k>0 && s2[k+1]!=s[i])
			k= par[k];

		if (s2[k+1]==s[i]) k++;

		if (k==len2)
		{
			ii now= 0,st= i-len2+1,age= st-start+1,pore= len1-i+1;
			//cout<<"found in "<<i<<" age "<<age<<", pore "<<pore<<endl;
			now= age*pore;
			ans+= now;
			start= i-len2+2;
			k= par[k];
		}
	}

	return ans;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int x,t;
	scanf("%d",&t);
	
	bool vow[130]= {0};
	vow['a']= vow['e']= vow['i']= vow['o']= vow['u']= 1;
	
	for (x=1;x<=t;++x)
	{
		int n;
		ii cnt= 0;
		scanf("%s",s+1);
		scanf("%d",&n);
		
		int len= strlen(s+1),i;
		for (i=1;i<=len;++i) if (vow[(int)s[i]]) s[i]= 'a';else s[i]= 'b';
		for (i=1;i<=n;++i) s2[i]= 'b';
		s2[n+1]= 0;
		
		failure();
		//reverse(s+1,s+len+1);
		
		cnt= match();
		printf("Case #%d: %lld\n",x,cnt);
	}
	
	return 0;	
}
