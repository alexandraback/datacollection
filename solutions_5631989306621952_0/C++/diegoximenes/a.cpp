#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 1005

int t;
char s[MAX], sout[MAX];

int main()
{
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		scanf(" %s ", s);
		int n = strlen(s);
		
		memset(sout, 0, sizeof(sout));

		vector<char> vout;
		vout.pb(s[0]);	
		for(int i=1; i<n; ++i)
		{
			if(s[i] >= vout[0]) vout.insert(vout.begin(), s[i]);
			else vout.pb(s[i]);
		}
		
		for(int i=0; i<n; ++i) sout[i] = vout[i];

		printf("Case #%d: %s\n", tc, sout);
	}

	return 0;
}
