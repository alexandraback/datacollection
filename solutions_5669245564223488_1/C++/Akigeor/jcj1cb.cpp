#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <algorithm>
#define MOD 1000000007
using namespace std;
long long PPP[105];
int L[26],R[26],F[26];
bool M[26];
long long ans=1;
bool filled(string s)
{
	for (int i=1;i<s.length();i++) if (s[i]!=s[0]) return 0;
	return 1;
}
int main()
{
	int tt,zz;
	cin>>tt;
	PPP[0]=1;
	for (zz=1;zz<=100;zz++) PPP[zz]=(1LL*zz*PPP[zz-1])%MOD;
	for (zz=1;zz<=tt;zz++)
	{
		int n,i,j,k,l;
		cin>>n;
		memset(F,0,sizeof(F));
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		memset(M,0,sizeof(M));
		int cnt=0;
		for (i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			if (filled(s))
			{
				if (M[s[0]-'a']) {ans=0; goto eee;}
				F[s[0]-'a']++;
			}
			else
			{
				cnt++;
				int a=s[0]-'a',b=s[s.length()-1]-'a';
				if (L[a] || R[b] || M[a] || M[b]) {ans=0; goto eee;}
				if (R[a]) cnt--;
				if (L[b]) cnt--;
				if (a==b) {ans=0; goto eee;}
				if (R[a] && R[a]==L[b]) {ans=0; goto eee;}
				L[a]=i;
				R[b]=i;
				j=1; while (s[j]==s[0]) j++;
				k=s.length()-2; while (s[k]==s[s.length()-1]) k--;
				int o=j,p;
				for (l=j+1;l<=k;l++)
				{
					if (s[l]!=s[l-1])
					{
						p=s[o]-'a';
						if (M[p] || L[p] || R[p] || F[p])
						{
							ans=0;
							goto eee;
						}
						M[p]=1;
						o=l;
					}
				}
				if (j<=k)
				{
					p=s[o]-'a';
					if (M[p] || L[p] || R[p] || F[p])
					{
						ans=0;
						goto eee;
					}
					M[p]=1;
					o=l;
				}
			}
		}
		for (i=0;i<26;i++) if (!L[i] && !R[i] && F[i]) cnt++;
		ans=PPP[cnt];
		for (i=0;i<26;i++) ans=(ans*PPP[F[i]])%MOD;
		printf("Case #%d: %lld\n",zz,ans);
		continue;
		eee:
		string ss;
		for (i++;i<=n;i++) cin>>ss;
		printf("Case #%d: %lld\n",zz,ans);
	}
}
