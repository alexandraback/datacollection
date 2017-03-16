#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

typedef long long ll;

const int MODULO = (int)1e9 + 7;

int fact[111];
char carSet[111][111];
int carSetLen[111];

bool isPure[111];
int pureCnt[26];
bool vis[111];
int n = 0;
deque<int> wtf;
int chainNext(char ch)
{
	int ans = 1;
	if(pureCnt[ch-'a'])
	{
		ans = (ll)ans * fact[pureCnt[ch-'a']] % MODULO;
		pureCnt[ch-'a'] = 0;
	}
	int cnt = 0;
	int which = 0;
	for(int i = 0;i < n;i++)
	{
		if(isPure[i] || vis[i] || carSet[i][0] != ch) continue;

		cnt++;
		which = i;
	}
	if(cnt > 1) return 0; // obv.
	if(cnt == 0) return ans;
	vis[which] = true;
	wtf.push_back(which);
	return (ll)ans * chainNext(carSet[which][carSetLen[which]-1]) % MODULO;
}

int chainPrev(char ch)
{
	int ans = 1;
	if(pureCnt[ch-'a'])
	{
		ans = (ll)ans * fact[pureCnt[ch-'a']] % MODULO;
		pureCnt[ch-'a'] = 0;
	}
	int cnt = 0;
	int which = 0;
	for(int i = 0;i < n;i++)
	{
		if(isPure[i] || vis[i] || carSet[i][carSetLen[i]-1] != ch) continue;

		cnt++;
		which = i;
	}
	if(cnt > 1) return 0; // obv.
	if(cnt == 0) return ans;
	vis[which] = true;
	wtf.push_front(which);
	return (ll)ans * chainPrev(carSet[which][0]) % MODULO;
}

int main(void)
{
	
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	fact[0] = 1;
	for(int i = 1;i <= 110;i++) fact[i] = fact[i-1] * (ll)i % MODULO;

	int T = 0;
	int TK = 0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",++TK);

		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		memset(pureCnt,0,sizeof(pureCnt));
		for(int i = 0;i < n;i++)
		{
			scanf("%s",carSet[i]);
			carSetLen[i] = strlen(carSet[i]);

			isPure[i] = true;
			for(int j = 0;j < carSetLen[i];j++)
			{
				isPure[i] &= carSet[i][j] == carSet[i][0];
			}
			if(isPure[i]) pureCnt[carSet[i][0]-'a']++;
		}

		bool fail = false;
		for(int i = 0;i < n;i++)
		{
			bool occur[26] = {0};
			for(int j = 0;j < carSetLen[i];j++)
			{
				if(occur[carSet[i][j]-'a'] && carSet[i][j] != carSet[i][j-1]) fail = true;
				occur[carSet[i][j]-'a'] = true;
			}
		}
		if(fail) { puts("0"); continue; }

		string fans;
		int part = 0;
		int ans = 1;
		for(int i = 0;i < n;i++)
		{
			if(isPure[i] || vis[i]) continue;
			vis[i] = true;
			part++;
			wtf.clear();
			wtf.push_back(i);
			ans = (ll)ans * chainNext(carSet[i][carSetLen[i]-1]) % MODULO;
			ans = (ll)ans * chainPrev(carSet[i][0]) % MODULO;

			for(int j = 0;j < wtf.size();j++) fans += carSet[wtf[j]];
		}
		for(int i = 0;i < 26;i++) if(pureCnt[i])
		{
			ans = (ll)ans * fact[pureCnt[i]] % MODULO;
			pureCnt[i] = 0;
			part++;
		}
		ans = (ll)ans * fact[part] % MODULO;

		bool occur[26] = {0};
		for(int i = 0;i < fans.length();i++)
		{
			if(occur[fans[i]-'a'] && fans[i] != fans[i-1]) fail = true;
			occur[fans[i]-'a'] = true;
		}
		if(fail) ans = 0;
		printf("%d\n",ans);
	}
	return 0;
}