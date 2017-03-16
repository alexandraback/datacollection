#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define NINF -0x3f3f3f3f

using namespace std;

typedef pair<int,int> pii;

long long pow10LL[19];

/*void solve ()
{
	string scA, scB;
	cin >> scA >> scB;
	
	reverse(scA.begin(), scA.end());
	reverse(scB.begin(), scB.end());
	
	int len = scA.size();
	long long balance = 0LL;
	for (int i = len-1; i >= 0; i--)
	{	
		if (scA[i] == '?' && scB[i] == '?')
		{
			if (balance > 0)
			{
				scA[i] = '0';
				scB[i] = '9';
			}
			else if (balance == 0)
			{
				scA[i] = scB[i] = '0';
			}
			else
			{
				scA[i] = '9';
				scB[i] = '0';
			}
		}
		else if (scA[i] == '?')
		{
			if (balance > 0)
			{
				scA[i] = '0';
			}
			else if (balance == 0)
			{
				scA[i] = scB[i];
			}
			else
			{
				scA[i] = '9';
			}
		}
		else if (scB[i] == '?')
		{
			if (balance > 0)
			{
				scB[i] = '9';
			}
			else if (balance == 0)
			{
				scB[i] = scA[i];
			}
			else
			{
				scB[i] = '0';
			}
		}
		
		balance += pow10LL[i]*(scA[i]-'0')-pow10LL[i]*(scB[i]-'0');
	}
	
	reverse(scA.begin(), scA.end());
	reverse(scB.begin(), scB.end());
	
	printf("%s %s\n",scA.c_str(),scB.c_str());
}*/

void generateNumbers (int pos, int len, int num, const string &s, vector<int> &ss)
{
	if (pos == len)
	{
		//printf("Num %d\n",num);
		ss.push_back(num);
	}
	else
	{
		if (s[pos] == '?')
		{
			for (int i = 0; i < 10; i += 1)
			{
				int nn = num + pow10LL[pos]*i;
				generateNumbers(pos+1,len,nn,s,ss);
			}
		}
		else
			generateNumbers(pos+1,len,num+pow10LL[pos]*(s[pos]-'0'),s,ss);
	}
}

void solve()
{
	string scA,scB;
	cin >> scA >> scB;
	
	reverse(scA.begin(), scA.end());
	reverse(scB.begin(), scB.end());
	
	int len = scA.size();
	vector<int> vA, vB;
	generateNumbers(0,len,0,scA,vA);
	generateNumbers(0,len,0,scB,vB);
	
	int diff = INF;
	int aA = INF;
	int aB = INF;
	
	for (int i = 0; i < vA.size(); i += 1)
	{
		for (int j = 0; j < vB.size(); j += 1)
		{
			int d = abs(vA[i]-vB[j]);
			
			if (d < diff)
			{
				diff = d;
				aA = vA[i];
				aB = vB[j];
			}
			else if (d == diff)
			{
				if (vA[i] < aA)
				{
					aA = vA[i];
					aB = vB[j];
				}
				else if (vA[i] == aA && vB[j] < aB)
				{
					aB = vB[j];
					aA = vA[i];
				}	
			}
		}
	}
	
	if (len == 3)
		printf("%03d %03d\n",aA,aB);
	else if (len == 2)
		printf("%02d %02d\n",aA,aB);
	else
		printf("%01d %01d\n",aA,aB);
}

int main (int argc, char const* argv[])
{
	pow10LL[0] = 1;
	for (int i = 1; i < 19; i += 1)
	{
		pow10LL[i] = 10LL*pow10LL[i-1];
	}
	
	int T;
	scanf("%d",&T);
	
	for (int t = 1; t <= T; ++t)
	{
		printf("Case #%d: ",t);
		solve();
	}
	
	return 0;
}
