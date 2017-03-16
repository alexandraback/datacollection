#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <queue>
using namespace std;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
#define SIZE(x) ((int)(x).size())
#define for0(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for0r(i,n) for(int i=(n)-1;i>=0;i--)
#define for1r(i,n) for(int i=(n);i>=1;i--)
typedef long long ll;

const int W = 521196;
//const int W = 2;
char word[600000][20];
int len[600000];

void read()
{
	//FILE *f = fopen("g.txt","r");
	FILE *f = fopen("garbled_email_dictionary.txt","r");
	for(int i=0;i<W;i++)
	{
		fgets(word[i],sizeof(word[i]),f);
		len[i]=strlen(word[i])-1;
		word[i][len[i]]='\0';
	}
	fclose(f);
}

int f[5000][5];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("C-small-attempt2.in","r",stdin);
	//freopen("C-small-attempt2.out","w",stdout);
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	read();
	int T,TC=0;

	scanf("%d ",&T);
	while (++TC<=T)
	{
		printf("Case #%d: ",TC);
		static char s[5000];
		gets(s);
		int n = strlen(s);
		int ans=5000;
		memset(f,-1,sizeof(f));
		f[0][0]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<W;j++)
			{
				if(len[j]>n-i)continue;
				int first=1,p=0,pre=-5,mn=4;
				int c=0;
				while(p<len[j])
				{
					if(word[j][p]!=s[i+p])
					{
						if(first)
						{
							mn=p;
							first=0;
						}
						else
						{
							if(p-pre<5)break;
						}
						c++;
						pre=p;
					}
					p++;
				}
				if(p<len[j])continue;
				for(int k=0;k<=mn;k++)
				{
					if(f[i][k]==-1)continue;
					int t=max(max(0,k-len[j]),pre+5-len[j]);
					if(f[i+len[j]][t]==-1 || f[i+len[j]][t]>f[i][k]+c)
					{
						f[i+len[j]][t]=f[i][k]+c;
						//printf("%s %d %d %d %d\n",word[j],i+len[j],t,f[i][k],c);
						if(i+len[j]==n)checkmin(ans,f[i][k]+c);
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
