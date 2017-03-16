#include <cstdio>
#include <string>
#include <vector>

using namespace std;

typedef long long int ll;

const int mod = 1e9 + 7;

ll sil[10005];

char tmp[1005];
string wczyt()
{
	scanf("%s", tmp);
	return tmp;
}

bool prefiks(char c, string s)
{
	int i = 0;
	for(; i < s.length(); i++)
		if(s[i] != c)
			break;
	if(i == 0)
		return false;
	if(i == s.length())
		return false;
	for(; i < s.length(); i++)
		if(s[i] == c)
			return false;
	return true;
}

bool sufiks(char c, string s)
{
	string g;
	for(int i = s.length() - 1; i >= 0; i--)
		g += s[i];
	return prefiks(c, g);
}

bool caly(char c, string s)
{
	for(int i = 0; i < s.length(); i++)
		if(s[i] != c)
			return false;
	return true;
}

bool zawiera(char c, string s)
{
	for(int i = 0; i < s.length(); i++)
		if(s[i] == c)
			return true;
	return false;
}

ll przem;

void yolo(vector<string> &v)
{
	vector<string> res;
	for(int i = 0; i < v.size(); i++)
		if(v[i] != "")
			res.push_back(v[i]);
	v = res;
}


bool zlezaw(char c, string s)
{
	while(s[s.length() - 1] != c)
		s = s.substr(0, s.length() - 1);
	while(s[0] != c)
		s = s.substr(1);
	return !caly(c, s);
}

void wyrz(char c, vector<string> &v)
{
	vector<string> pref, cal, suf, zaw, res;
	for(int i = 0; i < v.size(); i++)
	{
		if(prefiks(c, v[i]))
			pref.push_back(v[i]);
		else if(sufiks(c, v[i]))
			suf.push_back(v[i]);
		else if(caly(c, v[i]))
			cal.push_back(v[i]);
		else if(zawiera(c, v[i]))
			zaw.push_back(v[i]);
		else
			res.push_back(v[i]);
	}
	v.clear();
	if(!zaw.empty())
	{
		if(zaw.size() > 1 || !pref.empty() || !suf.empty() || !cal.empty())
		{
			przem = 0LL;
			return;
		}
		if(zlezaw(c, zaw[0]))
		{
			przem = 0LL;
			return;
		}
		v = res;
		v.push_back(zaw[0]);
		return;
	}
	if(pref.size() > 1)
	{
		przem = 0LL;
		return;
	}
	if(suf.size() > 1)
	{
		przem = 0LL;
		return;
	}
	if(pref.empty())
		pref.push_back("");
	if(suf.empty())
		suf.push_back("");
	przem = (przem * sil[cal.size()]) % mod;
	v = res;
	if(!cal.empty())
		v.push_back(suf[0] + cal[0] + pref[0]);
	else if(pref[0] != "" || suf[0] != "")
		v.push_back(suf[0] + pref[0]);
}

ll przyp()
{
	przem = 1LL;
	int n;
	vector<string> v;
	scanf("%d", &n);
	while(n--)
		v.push_back(wczyt());
	for(int i = 'a'; i <= 'z'; i++)
	{
		//printf("lit = %c\n", (char) i);
		//for(int j = 0; j < v.size(); j++)
			//printf("%s ", v[j].c_str());
		////printf("\n");
		//printf("przem = %lld\n", przem);
		wyrz(i, v);
		yolo(v);
	}
	return (sil[v.size()] * przem) % mod;
}

int main()
{
	sil[0] = 1LL;
	for(int i = 1; i < 10005; i++)
		sil[i] = (sil[i - 1] * i) % mod;
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
		printf("Case #%d: %lld\n", i, przyp());
	return 0;
}
