#include"stdio.h"
#include"string.h"
#include"algorithm"
#include"string"
#include"map"
using namespace std;
char s1[200][50],s2[200][50];
int ss[200];
map<string,int>mp; 
int main(){
		freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		int n,le;
		scanf("%d %d",&n,&le);
		for(int i=0;i<n;i++)
		{
			scanf("%s",s1[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%s",s2[i]);
		}
		int ans=le+1;
		for(int i=0;i<n;i++)
		{
			mp.clear();
			int cnt=0;
			for(int j=0;j<le;j++)
			{
				if(s1[0][j]!=s2[i][j])
				{ss[j]=1;
				 cnt++;} 
				 else ss[j]=0;
			}
	//		printf("-->%d%d\n",ss[0],ss[1]);
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<le;k++)
				if(ss[k])
				{
					if(s1[j][k]=='1')s1[j][k]='0';
					else if(s1[j][k]=='0')s1[j][k]='1';
				}
				mp[s1[j]]++;
				
				for(int k=0;k<le;k++)
				if(ss[k])
				{
					if(s1[j][k]=='1')s1[j][k]='0';
					else if(s1[j][k]=='0')s1[j][k]='1';
				}
			}
		
			for(int j=0;j<n;j++)
			{
				if(mp[s2[j]]>0)
				{
					mp[s2[j]]--;
				}	 
				else {
					goto st;
				}
			}
			
			ans=min(ans,cnt);
			st:;
		}
		if(ans<=le)
		printf("Case #%d: %d\n",cas++,ans);
		else 
		printf("Case #%d: NOT POSSIBLE\n",cas++);
	}
}