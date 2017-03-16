#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define NINF -0x3f3f3f3f

using namespace std;

typedef pair<int,int> pii;

int hist[26];
string digits[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
pair<char,int> order[10];

void solve ()
{
	
	string str;
	cin >> str;
	
	memset(hist,0,sizeof hist);
	for (int i = 0; i < str.size(); i += 1)
	{
		hist[str[i]-'A']++;
	}
	
	order[0] = make_pair('Z',0);
	order[1] = make_pair('W',2);
	order[2] = make_pair('X',6);
	order[3] = make_pair('S',7);
	order[4] = make_pair('V',5);
	order[5] = make_pair('F',4);
	order[6] = make_pair('O',1);
	order[7] = make_pair('R',3);
	order[8] = make_pair('H',8);
	order[9] = make_pair('I',9);
	
	int cc[10] = {0};
	for (int i = 0; i < 10; i += 1)
	{
		int cIdx = order[i].first-'A';
		if (hist[cIdx])
		{
			int dig = order[i].second;
			
			cc[dig] = hist[cIdx];
			//printf("%c de %d = %d\n",order[i].first,dig,cc[dig]);
			
			for (int j = 0; j < digits[dig].size(); j += 1)
			{
				int idx = digits[dig][j]-'A';
				hist[idx] -= cc[dig];
			}
		}
	}

	for (int i = 0; i < 10; i += 1)
	{
		if (cc[i])
		{
			for (int j = 0; j < cc[i]; j += 1)
			{
				printf("%d",i);
			}
		}
	}
	printf("\n");
}

int main (int argc, char const* argv[])
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
