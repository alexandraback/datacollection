#include<bits/stdc++.h>
using namespace std;
map<char,int> Map;
int ans[15];
char s[10000];
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T,test = 0;
	scanf("%d\n",&T);
	while (T--)
	{
		gets(s);
		int n = strlen(s);
		Map.clear();
		for (int i=0;i<n;i++) 
		{
			Map[s[i]]++;
		} 
		memset(ans,0,sizeof(ans));
		ans[0] = Map['Z'];
		ans[2] = Map['W'];
		ans[4] = Map['U'];
		ans[6] = Map['X'];
		ans[8] = Map['G'];
		ans[7] = Map['S'] - ans[6];
		ans[5] = Map['F'] - ans[4];
		ans[3] = Map['H'] - ans[8];
		ans[1] = Map['O'] - ans[0] - ans[2] - ans[4];
		ans[9] = (Map['N'] - ans[1] - ans[7]) / 2;
		printf("Case #%d: ",++test);
		for (int i=0;i<10;i++)
			for (int j=0;j<ans[i];j++) printf("%d",i);
		printf("\n"); 
	}
}
