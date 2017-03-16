#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define NINF -0x3f3f3f3f

using namespace std;

typedef pair<int,int> pii;

int ans;
vector<int> sol;
vector<int> cur;
vector<string> fs;
map<string,int> jp, js, ps;

void bt (int mask, int d, int K)
{
	if (d > ans)
	{
		ans = d;
		sol = cur;
	}
	
	if (mask)
	{
		for (int i = 0; i < (int)fs.size(); i += 1)
		{
			if (mask & (1<<i))
			{
				string &f = fs[i];
				string jpd; jpd += f[0]; jpd += f[1];
				string jsd; jsd += f[0]; jsd += f[2];
				string psd; psd += f[1]; psd += f[2];
				
				if (jp[jpd]+1 <= K && js[jsd]+1 <= K && ps[psd]+1 <= K)
				{
					jp[jpd]++; js[jsd]++; ps[psd]++;
					cur.push_back(i);
					bt(mask ^ (1<<i),d+1,K);
					cur.pop_back();
					jp[jpd]--; js[jsd]--; ps[psd]--;
				}
			}
		}
	}
}

void solve ()
{
	int J,P,S,K;
	cin >> J >> P >> S >> K;
	
	ans = 0;
	fs.clear();
	sol.clear();
	for (int j = 0; j < J; j += 1)
	{
		for (int p = 0; p < P; p += 1)
		{
			for (int s = 0; s < S; s += 1)
			{
				char cj = '0'+j;
				char cp = '0'+p;
				char cs = '0'+s;
				
				string f;
				f += cj;
				f += cp;
				f += cs;
				fs.push_back(f);
			}
		}
	}
	
	jp.clear();
	js.clear();
	ps.clear();
	
	for (int i = 0; i < fs.size(); i += 1)
	{
		string &f = fs[i];
		string jpd; jpd += f[0]; jpd += f[1];
		string jsd; jsd += f[0]; jsd += f[2];
		string psd; psd += f[1]; psd += f[2];
		
		if (jp[jpd]+1 <= K && js[jsd]+1 <= K && ps[psd]+1 <= K)
		{
			jp[jpd]++; js[jsd]++; ps[psd]++;
			sol.push_back(i);
		}
	}
	
	printf("%d\n",sol.size());
	for (int i = 0; i < sol.size(); i += 1)
	{
		string &f = fs[sol[i]];
		printf("%c %c %c\n",f[0]+1,f[1]+1,f[2]+1);
	}
}

int main ()
{
	int T;
	scanf("%d",&T);
	
	for (int t = 1; t <= T; ++t)
	{
		printf("Case #%d: ",t);
		solve();
	}
	
	return 0;
}
