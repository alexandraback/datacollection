#include <fstream>
#include <cstring>
#include <vector>
#define MOD 1000000007
using namespace std;
int T, n, ns[110], sol, nrplin[26], fact[110], ord[12], interior[26];
char cuv[110][110];
bool ok, uz[110], viz[110];
vector <int> inc[26], sf[26];

inline void Verif()
{
	char S[10100];
	bool anterior[26];
	int i, nS = 0, j, k, last;
	for(i = 0; i < 26; ++i)
		anterior[i] = false;
	for(i = 1; i <= n; ++i)
		nS += ns[i];
	j = 1;
	for(i = 1; i <= n; ++i)
	{
		for(k = 1; k <= ns[ord[i]]; ++k)
		{
			S[j] = cuv[ord[i]][k];
			j++;
		}
	}
	last = 1;
	i = 1;
	while(i <= nS)
	{
		while(i <= nS && S[i] == S[last])
			i++;
		if(anterior[S[last] - 'a'])
			return;
		anterior[S[last] - 'a'] = true;
		last = i;
	}
	sol++;
	if(sol == MOD)
		sol -= MOD;
}

inline void Back(int pas)
{
	if(pas == n + 1)
		Verif();
	else
	{
		int i;
		for(i = 1; i <= n; ++i)
		{
			if(!uz[i])
			{
				ord[pas] = i;
				uz[i] = true;
				Back(pas + 1);
				uz[i] = false;
			}
		}
	}
}

inline void DFS(int c)
{
	viz[inc[c][0]] = true;
	if(inc[cuv[inc[c][0]][ns[inc[c][0]]] - 'a'].size() == 1)
	{
		if(viz[inc[cuv[inc[c][0]][ns[inc[c][0]]] - 'a'][0]])
		{
			ok = false;
			return;
		}
		DFS(cuv[inc[c][0]][ns[inc[c][0]]] - 'a');
	}
}

int main()
{
	int t, i, j, nrcomp, st, dr;
	fact[0] = 1;
	for(i = 1; i <= 100; ++i)
		fact[i] = (1LL * i * fact[i - 1]) % MOD;
	ifstream fin("B.in");
	ofstream fout("B.out");
	fin >> T;
	for(t = 1; t <= T; ++t)
	{
		ok = true;
		for(i = 0; i < 26; ++i)
		{
			inc[i].clear();
			sf[i].clear();
			nrplin[i] = 0;
			interior[i] = 0;
		}
		fin >> n;
		for(i = 1; i <= n; ++i)
		{
			viz[i] = false;
			fin >> (cuv[i] + 1);
			ns[i] = strlen(cuv[i] + 1);
			if(ns[i] >= 3 && cuv[i][1] == cuv[i][ns[i]])
			{
				j = 1;
				while(j < ns[i] && cuv[i][j] == cuv[i][1])
					j++;
				if(j < ns[i])
					ok = false;
			}
			j = 1;
			while(j <= ns[i] && cuv[i][j] == cuv[i][1])
				j++;
			if(j == ns[i] + 1)
			{
				nrplin[cuv[i][1] - 'a']++;
				continue;
			}
			if(ns[i] >= 2)
			{
				inc[cuv[i][1] - 'a'].push_back(i);
				sf[cuv[i][ns[i]] - 'a'].push_back(i);
			}
		}
		for(i = 1; i <= n; ++i)
		{
			if(ns[i] >= 3)
			{
				st = 1;
				while(st <= ns[i] && cuv[i][st] == cuv[i][1])
					st++;
				st--;
				dr = ns[i];
				while(dr > 0 && cuv[i][dr] == cuv[i][ns[i]])
					dr--;
				dr++;
				for(j = st + 1; j < dr; ++j)
				{
					if(!interior[cuv[i][j] - 'a'])
						interior[cuv[i][j] - 'a'] = 1;
					else
					{
						if(cuv[i][j - 1] != cuv[i][j] && cuv[i][j + 1] != cuv[i][j])
							ok = false;
					}
				}
			}
		}
		for(i = 0; i < 26; ++i)
		{
			if(interior[i] && (inc[i].size() > 0 || sf[i].size() > 0 || nrplin[i] > 0))
				ok = false;
		}
		//sol = 0;
		//Back(1);
		for(i = 0; i < 26; ++i)
			if(inc[i].size() >= 2 || sf[i].size() >= 2)
				ok = false;
		if(!ok)
			sol = 0;
		else
		{
			nrcomp = 0;
			sol = 1;
			for(i = 0; i < 26; ++i)
				sol = (1LL * sol * fact[nrplin[i]]) % MOD;
			for(i = 0; i < 26; ++i)
			{
				if(inc[i].size() == 1)
				{
					if(viz[inc[i][0]])
						continue;
					if(sf[i].size() == 0)
					{
						nrcomp++;
						DFS(i);
					}
				}
				else
				{
					if(sf[i].size() == 0 && nrplin[i] > 0)
					{
						nrcomp++;
					}
				}
			}
			for(i = 0; i < 26; ++i)
			{
				if(sf[i].size() > 0 && !viz[sf[i][0]])
				{
					viz[sf[i][0]] = true;
					nrcomp++;
					if(inc[i].size() > 0)
						DFS(i);
				}
			}
			if(!ok)
				sol = 0;
			sol = (1LL * sol * fact[nrcomp]) % MOD;
		}
		fout << "Case #" << t << ": " << sol << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
