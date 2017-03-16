#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f

int sol = INF;
vector<int> v1sol, v2sol;

void brute(vector<int> v1, vector<int> v2)
{
	vector<int> v1aux = v1;
	vector<int> v2aux = v2;
	
	bool changedv1 = 0;
	for(int i=0; i<(int)v1.size(); ++i)
		if(v1[i] == -1)
			for(int d=0; d<=9; ++d)
			{
				v1aux[i] = d;
				brute(v1aux, v2);
				changedv1 = 1;
			}
	
	bool changedv2 = 0;
	if(!changedv1)
	{
		for(int i=0; i<(int)v2.size(); ++i)
			if(v2[i] == -1)
				for(int d=0; d<=9; ++d)
				{
					v2aux[i] = d;
					brute(v1, v2aux);
					changedv2 = 1;
				}
	}

	if(!changedv1 && !changedv2)
	{
		int n1 = 0, n2 = 0;

		int k = 1;
		for(int i=(int)v1.size()-1; i>=0; --i, k *= 10)
		{
			n1 += k*v1[i];
			n2 += k*v2[i];
		}

		int lsol = abs(n1 - n2);
		if(lsol < sol)
		{
			sol = lsol;
			v1sol = v1;
			v2sol = v2;
		}
		else if(lsol == sol)
		{
			if(v1 < v1sol)
			{
				v1sol = v1;
				v2sol = v2; 
			}
			else if(v1 == v1sol)
			{
				if(v2 < v2sol) v2sol = v2;
			}
		}
	}
}

int t;

int main()
{
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		sol = INF;
		v1sol.clear();
		v2sol.clear();
		
		vector<int> v1, v2;	
		char s1[20], s2[20];
		scanf(" %s %s ", s1, s2);
		int len = strlen(s1);
		for(int i=0; i<len; ++i)
		{
			if(s1[i] == '?') v1.pb(-1);
			else v1.pb(s1[i] - '0');

			if(s2[i] == '?') v2.pb(-1);
			else v2.pb(s2[i] - '0');
		}
		
		brute(v1, v2);

		printf("Case #%d: ", tc);
		for(int i=0; i<(int)v1sol.size(); ++i) printf("%d", v1sol[i]);
		putchar(' ');
		for(int i=0; i<(int)v2sol.size(); ++i) printf("%d", v2sol[i]);
		puts("");
	}

	return 0;
}
