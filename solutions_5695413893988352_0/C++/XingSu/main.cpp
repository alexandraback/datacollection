#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>


using namespace std;


char C[25], J[25];
string dp[30][3][2]; //0: <, 1:=, 2:>


long long toNum(string s){
	long long ret = 0;
	for (int i = 0; i < s.length(); i++)
		ret = ret * 10 + s[i] - '0';
	return ret;
}

long long labs(long long x){
	return x < 0 ? -x : x;
}



bool comp(string c0, string j0, string c1, string j1)
{
	if (c1 == "-" || j1 == "-") return true;
	if (c0 == "-" || j0 == "-") return false;
	long long cn0 = toNum(c0), jn0 = toNum(j0), cn1 = toNum(c1), jn1 = toNum(j1);
	long long d = labs(cn0-jn0) - labs(cn1 - jn1);
	if (d < 0)
		return true;
	if (d > 0)
		return false;
	//d = 0
	if (cn0 < cn1)
		return true;
	if (cn0 > cn1)
		return false;
	if (jn0 < jn1)
		return true;
	return false;
}


void gao()
{
	int n;
	int i, j, k;
	char cc, jj;
	scanf ("%s%s", &C, &J);
	n = strlen(C);
	string prev[3][2];
	string curr[3][2];
	for (i = 0; i < 3; i++)
		for (j = 0; j < 2; j++)
			prev[i][j] = "";
		
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
			curr[j][0] = curr[j][1] = "-";
		for (cc = '0'; cc <= '9'; cc++) if (C[i] == '?' || C[i] == cc)
		{
			for (jj = '0'; jj <= '9'; jj++) if (J[i] == '?' || J[i] == jj)
			{
				for (k = 0; k < 3; k++)if(prev[k][0] != "-")
				{
					string temp1 = prev[k][0] + cc;
					string temp2 = prev[k][1] + jj;
					long long d = toNum(temp1) - toNum(temp2);
					if (d < 0 && comp(temp1, temp2, curr[0][0], curr[0][1]))
					{
						curr[0][0] = temp1;
						curr[0][1] = temp2;
					}
					if (d == 0 && comp(temp1, temp2, curr[1][0], curr[1][1]))
					{
						curr[1][0] = temp1;
						curr[1][1] = temp2;
					}
					if (d > 0 && comp(temp1, temp2, curr[2][0], curr[2][1]))
					{
						curr[2][0] = temp1;
						curr[2][1] = temp2;
					}
				}
			}
		}
		for (j = 0; j < 3; j++)
		{
			
			//cout << curr[j][0] << " " << curr[j][1] << endl;
			prev[j][0] = curr[j][0];
			prev[j][1] = curr[j][1];
		}
	}
	string ans[2];
	ans[0] = ans[1] = "-";
	for (j = 0; j < 3; j++)
		if (comp(curr[j][0], curr[j][1], ans[0], ans[1]))
			ans[0] = curr[j][0], ans[1] = curr[j][1];
	cout << ans[0] << " " << ans[1] << endl;
}

int main()
{
	int T;
	freopen ("B-small-attempt0.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	scanf ("%d", &T);
	for (int cas = 1; cas <= T; cas ++)
	{
		printf ("Case #%d: ", cas);
		gao();
	}
	return 0;
}
