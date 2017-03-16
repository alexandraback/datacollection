#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 20005

int t;
int n;
char s[MAX];


int main()
{
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		scanf(" %s ", s);	
		
		map<char, int> cnt;
				
		n = strlen(s);
		for(int i=0; i<n; ++i)
		{
			if(cnt.find(s[i]) == cnt.end()) cnt[s[i]] = 0;
			cnt[s[i]]++;
		}
	
		vector<int> out;
		
		while(cnt['Z'])
		{
			cnt['Z']--;
			cnt['E']--;
			cnt['R']--;
			cnt['O']--;
			out.pb(0);
		}
		while(cnt['W'])
		{
			cnt['T']--;
			cnt['W']--;
			cnt['O']--;
			out.pb(2);
		}
		while(cnt['U'])
		{
			cnt['F']--;
			cnt['O']--;
			cnt['U']--;
			cnt['R']--;
			out.pb(4);
		}
		while(cnt['X'])
		{
			cnt['S']--;
			cnt['I']--;
			cnt['X']--;
			out.pb(6);
		}
		while(cnt['G'])
		{
			cnt['E']--;
			cnt['I']--;
			cnt['G']--;
			cnt['H']--;
			cnt['T']--;
			out.pb(8);
		}
		
		////

		while(cnt['O'])
		{
			cnt['O']--;
			cnt['N']--;
			cnt['E']--;
			out.pb(1);
		}
		while(cnt['H'])
		{
			cnt['T']--;
			cnt['H']--;
			cnt['R']--;
			cnt['E']--;
			cnt['E']--;
			out.pb(3);
		}
		while(cnt['F'])
		{
			cnt['F']--;
			cnt['I']--;
			cnt['V']--;
			cnt['E']--;
			out.pb(5);
		}
		while(cnt['S'])
		{
			cnt['S']--;
			cnt['E']--;
			cnt['V']--;
			cnt['E']--;
			cnt['N']--;
			out.pb(7);
		}

		////

		while(cnt['N'])
		{
			cnt['N']--;
			cnt['I']--;
			cnt['N']--;
			cnt['E']--;
			out.pb(9);
		}

		sort(out.begin(), out.end());
		printf("Case #%d: ", tc);
		for(int i=0; i<(int)out.size(); ++i) printf("%d", out[i]);
		puts("");
	}

	return 0;
}
