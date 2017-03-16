#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int mo=1000000007;
const int N=111;
int test,tot,n;
int same[26],cnt[N],tcnt[N],st[N],en[N];
int hash[N];
int con[N];
char str[N][111],s[111];
long long frac[111];
int main()
{
	//freopen("x.in","r",stdin);
	//freopen("x.out","w",stdout);
	frac[0]=1;
	for (int i=1; i<105; ++i) frac[i]=frac[i-1]*i%mo;
	scanf("%d",&test);
	for (int tt=1; tt<=test; ++tt)
	{
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		tot=0;
		int cc=0;
		bool ok=true;
		memset(str,0,sizeof str);
		memset(same,0,sizeof same);
		memset(cnt,0,sizeof cnt);
		memset(con,0,sizeof con);
		for (int i=0; i<n; ++i)
		{
			scanf("%s",s);
			int len=strlen(s);
			bool flag=true;
			memset(tcnt,0,sizeof tcnt);
			for (int j=0; j<len; ++j)
			{
				if (s[j]!=s[0]) flag=false;
				if (tcnt[s[j]-'a']==0)
				{
					cnt[s[j]-'a']++;
					tcnt[s[j]-'a']++;
				} 
			}
			if (flag) same[s[0]-'a']++;
			else
			{
				strcpy(str[tot],s);
				tot++;
			}
		}
		for (int i=0; i<tot; ++i)
		{
			int len=strlen(str[i]);
			st[i]=str[i][0]-'a'; en[i]=str[i][len-1]-'a';
			con[st[i]]=1; con[en[i]]=1;
			for (int j=1; j<len; ++j)
			  if (str[i][j]!=str[i][0] && str[i][j]!=str[i][len-1])
			  	if (cnt[str[i][j]-'a']>1) 
			  	{
					ok=false;
					break;
				}
			if (!ok) break;
		}
		memset(cnt,0,sizeof cnt);
		memset(tcnt,0,sizeof tcnt);
		for (int i=0; i<tot; ++i)
		{
			cnt[st[i]]++;
			tcnt[en[i]]++;
		}
		
		for (int i=0; i<26; ++i)
			if (cnt[i]>1 || tcnt[i]>1) {ok=false; break;}
		if (ok)
		{
			int find=0;
			memset(hash,0,sizeof hash);
			while (1)
			{
				
				find=0;
				for (int i=0; i<tot; ++i)
					for (int j=i+1; j<tot; ++j)
					if (!hash[i] && !hash[j])
					{
						if (en[i]==st[j])
						{
							en[i]=en[j];
							hash[j]=1;
							find=1;
						} else
						if (en[j]==st[i])
						{
							en[j]=en[i];
							hash[i]=1;
							find=1;
						}
					}
				if (find==0) break;
			}
			memset(cnt,0,sizeof cnt);
			for (int i=0; i<tot; ++i)
			if (!hash[i])
			{
				cnt[st[i]]++; cnt[en[i]]++;
				cc++;
			}
			for (int i=0; i<26; ++i)
			{
				if (cnt[i]>1)
				{ok=false; break;}
			}	
		}
		long long ans=1;
		for (int i=0; i<26; ++i)
			if (same[i])
			{
				if (con[i]) ans=ans*frac[same[i]]%mo;
				else {ans=ans*frac[same[i]]%mo; cc++;}
			}
		ans=ans*frac[cc];
		if (!ok) printf("%d\n",0);
		else printf("%lld\n",ans);
	}
	return 0;
}
