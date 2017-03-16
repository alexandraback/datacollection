/*×Ô¶¯AC*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std ;
char str[105][105],temp[105][105] ;
int l[105][105] ;
int ABS(int x)
{
	return x>0?x:-x ;
}
int main()
{
	freopen("D:\A-small-attempt0 (1).in","r",stdin) ;
	freopen("D:\A-small-attempt0 (1).out","w",stdout) ;
	int t ;
	scanf("%d",&t) ;
	int n ;
	for(int cas=1 ;cas<=t ;cas++)
	{
		memset(l,0,sizeof(l)) ;
		scanf("%d",&n) ;
		int maxn=-1 ;
		for(int i=0 ;i<n ;i++)
		{
			scanf("%s",str[i]) ;
			int st=0 ;
			char re=str[i][0] ;
			int len=strlen(str[i]) ;
			maxn=max(maxn,len) ;
			temp[i][st++]=re ;
			for(int j=0 ;j<len ;j++)
			{
				if(str[i][j]!=re)
				{
					re=str[i][j] ;
					temp[i][st++]=re ;
				}
			}
			temp[i][st]='\0' ;
		}
		int flag=1 ;
		for(int i=1 ;i<n ;i++)
		{
			if(strcmp(temp[0],temp[i]))
			{
				flag=0 ;
				break ;
			}
		}
		if(!flag)
		{
			printf("Case #%d: Fegla Won\n",cas) ;
			continue ;
		}
		int len=strlen(temp[0]) ;
		int ans=0 ;
		//puts(temp[0]) ;
		for(int i=0 ;i<n ;i++)
		{
			int xx=0 ;
			for(int j=0 ;j<len ;j++)
			{
				int cc=0 ; 
				while(str[i][xx]==temp[i][j])
				{
					cc++ ;
					xx++ ;
				}
				l[i][j]=cc ;
			}
		}
		/*for(int i=0 ;i<3 ;i++)
		{
			for(int j=0 ;j<3 ;j++)
				printf("%d??\n",l[i][j]) ;
		}*/
		for(int i=0 ;i<len ;i++)
		{
			int ct=0xfffffff ;
			for(int j=1 ;j<=100 ;j++)
			{
				int cnt=0 ;
				for(int k=0 ;k<n ;k++)
				{
					cnt+=ABS(j-l[k][i]) ;
				}
				ct=min(ct,cnt) ;
			}
			ans+=ct ;
		}
		printf("Case #%d: %d\n",cas,ans) ;
	}
	return 0 ;
}