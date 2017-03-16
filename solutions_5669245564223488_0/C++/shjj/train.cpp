//shjj-train

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

char s[300][300],A[3000000];
int g[30],len[30],n,ans;
bool use[30],cuse[30];

void dfs(int w)
{
if (w>n)
  {
  ans++;
  return;
  }
bool cuse2[26];
for (int i=0;i<26;i++) cuse2[i]=cuse[i];
for (int i=1;i<=n;i++)
  if (!use[i])
    {
	g[w]=i;
	use[i]=1;
	for (int j=0;j<26;j++) cuse[j]=cuse2[j];
	for (int j=0;j<len[i];j++) cuse[s[i][j]-'a']=1;
	for (int j=1;j<=n;j++)
	  if (!use[j])
	    {
		for (int k=0;k<len[j];k++)
		  if (cuse[s[j][k]-'a']&&s[j][k]!=s[i][len[i]-1])
		    {
			for (int l=0;l<26;l++) cuse[l]=cuse2[l];
			use[i]=0;
			return;
			}
		}
	dfs(w+1);
	use[i]=0;
	}
}

int main()
{
freopen("train.in","r",stdin);
freopen("train.out","w",stdout);
int Test,tt=0;scanf("%d",&Test);
for (;Test--;)
  {
  scanf("%d",&n);
  for (int i=1;i<=n;i++)
    {
	scanf("%s",s[i]);len[i]=strlen(s[i]);
	int tmp=0;
	for (int j=1;j<len[i];j++)
	  if (s[i][j]!=s[i][tmp]) s[i][++tmp]=s[i][j];
	len[i]=tmp+1;
	}
  //printf("%d\n",++tt);
  ans=0;
  memset(cuse,0,sizeof(cuse));
  dfs(1);
  printf("Case #%d: %d\n",++tt,ans);
  }
}