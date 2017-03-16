#include<iostream>
#include<cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define MAXLEN 60

char* dict[MAXLEN][500000];
int dl[MAXLEN];

int n;

int dp[60];

int nmod(const string& s1, char* s2)
{
	int nret = 0;
	for(int i=0;i<s1.length();i++)
		nret += s1[i]!=s2[i];

	return nret;
}

int main()
{
	FILE *dfp = fopen("dict.txt","r");
	char buf[100];
	while(fscanf(dfp,"%s",buf)!=EOF)
	{
		int l = strlen(buf);
		if (l>0)
		{
			if (l<MAXLEN)
			{
				char *p = (char*)malloc(l+1);
				strcpy(p,buf);
				dict[l][dl[l]++] = p;
				//cout<<buf<<endl;
			}
		}
		else
			break;
	}
	
	
	freopen("C-small-attempt0.in", "r",stdin);
	freopen("C-small-attempt0.out", "w",stdout);
	

	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		string s;
		cin>>s;
		int n = s.length();
		memset(dp,0x0f,sizeof(dp));
		dp[0] = 0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<i;j++)
			{
				string last = s.substr(j,i-j);
				int ll = last.length();
				if (ll>MAXLEN) continue;
				for(int k=0;k<dl[ll];k++)
				{
					dp[i] = min(dp[i], dp[j] + nmod(last, dict[ll][k]));
				}
			}
		
		cout<< "Case #" << tt << ": " << dp[n] << endl;
	}

	return 0;
}
