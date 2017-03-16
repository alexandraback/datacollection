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
		string s,s2;
		int n,sz,i,j,cnt= 0;
		cin>>s>>n;
		sz= sz(s);
		
		for (i=0;i<sz;++i)
		{
			s2= "";
			int sz2= 0;
			
			for (j=1;i+j<=sz;++j)
			{
				s2+= s[i+j-1];
				sz2= j;
				int k,f= 0;
				for (k=0;k<sz2;++k)
				{
					if (vow[(int)s2[k]]) {f= 0;continue;}
					f++;
					if (f==n) break;
				}
				
				if (f==n)
				{
					
					cnt++;
				}
				
			}
		}
		printf("Case #%d: %d\n",x,cnt);
	}
	
	return 0;	
}
