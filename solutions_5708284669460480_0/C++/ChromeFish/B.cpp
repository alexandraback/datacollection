#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
ifstream in("B.in");
ofstream out("B.out");

int n, s, m;
long long ans, sum, maxn;
double ex;
string s1, s2;

int check(string s1, string s2)
{
	int ans =1;
	int len =s1.length();
	if (len < m ) return 0;
	for (int i=1; i<=m; i++)
		if (s1[len-i] != s2[m-i])
		{
			ans =0;
			break;
		}
	return ans;
}

void dfs(int x, int cnt, string tmp)
{
	if (x==s)
	{
		sum++;
		ans+=cnt;
		maxn = max(maxn, (long long)cnt);
	}
	else
		for (int i=0; i<n; i++)
			dfs(x+1, cnt+check(tmp+s1[i],s2), tmp+s1[i]);
}

int main()
{
	int T;
	in>>T;
	for (int i=1; i<=T; i++)
	{
		in>>n>>m>>s;
		in>>s1;
		in>>s2;
		sum = 0;
		ans =0;
		maxn=0;
		dfs(0, 0, "");
		ex = maxn-(ans+0.0)/sum;
		out<<"Case #"<<i <<": "<<ex<<endl;
	}
}