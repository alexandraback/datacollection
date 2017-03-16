#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL
#define ll long long

string C, J;

vector<string> res;

void generate(string s,int pos)
{
	if(pos==s.size())
	{
		res.push_back(s);
		return;
	}
	if(s[pos]!='?')
		generate(s,pos+1);
	else
	{
		for(int i=0;i<10;++i)
		{
			string t = s;
			t[pos] = char(i+'0');
			generate(t,pos+1);
		}
	}
}

int toInt(string s)
{
	int res = 0;
	for(int i=0;i<s.size();++i)
	{
		res *= 10;
		res += (s[i]-'0');
	}
	return res;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;++tc)
	{
		cin >> C >> J;
		generate(C,0);
		vector<string> posC = res;
		res.clear();
		generate(J,0);
		vector<string> posJ = res;
		res.clear();
		pair<string,string> cand;
		int res = 1e8;
		for(int i=0;i<posC.size();++i)
			for(int j=0;j<posJ.size();++j)
			{
				int tmp = abs(toInt(posC[i])-toInt(posJ[j]));
				if(tmp<res)
				{
					res = tmp;
					cand.first = posC[i];
					cand.second = posJ[j];
				}
				else if(tmp==res)
				{
					if(posC[i]<cand.first)
					{
						cand.first = posC[i];
						cand.second = posJ[j];	
					}
					else if(posC[i]==cand.first)
					{
						if(posJ[j]<cand.second)
							cand.second = posJ[j];
					}
				}
			}
		cout << "Case #" << tc << ": " << cand.first << " " << cand.second << endl;
	}
	return 0;
}
