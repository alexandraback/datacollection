#include <stdio.h>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[500];
int chk[10];
char str[2020];

int main()
{
	int t,n,i,j;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&t);
	for(int loop = 1;loop <= t;loop++)
	{
		printf("Case #%d: ",loop);
		memset(chk,0,sizeof(chk));
		memset(x,0,sizeof(x));
		scanf(" %s",str);
		n = strlen(str);
		for(i=0;i<n;i++)
			x[str[i]]++;
		while(x['Z'] > 0)
		{
			// printf("%d\n",1);
			chk[0]++;
			x['Z']--;
			x['E']--;
			x['R']--;
			x['O']--;
		}
		while(x['W'] > 0)
		{
			// printf("%d\n",2);
			chk[2]++;
			x['T']--;
			x['W']--;
			x['O']--;
		}
		while(x['X'] > 0)
		{
			chk[6]++;
			x['S']--;
			x['I']--;
			x['X']--;
		}
		while(x['U'] > 0)
		{
			chk[4]++;
			x['F']--;
			x['O']--;
			x['U']--;
			x['R']--;
		}
		while(x['G'] > 0)
		{
			chk[8]++;
			x['E']--;
			x['I']--;
			x['G']--;
			x['H']--;
			x['T']--;
		}
		while(x['O'] > 0)
		{
			chk[1]++;
			x['O']--;
			x['N']--;
			x['E']--;
		}
		while(x['R'] > 0)
		{
			chk[3]++;
			x['T']--;
			x['H']--;
			x['R']--;
			x['E']--;
			x['E']--;
		}
		while(x['F'] > 0)
		{
			chk[5]++;
			x['F']--;
			x['I']--;
			x['V']--;
			x['E']--;
		}
		while(x['S'] > 0)
		{
			chk[7]++;
			x['S']--;
			x['E']--;
			x['V']--;
			x['E']--;
			x['N']--;
		}
		while(x['N'] > 0)
		{
			chk[9]++;
			x['N']--;
			x['I']--;
			x['N']--;
			x['E']--;
		}
		for(i=0;i<=9;i++)
		{
			while(chk[i] > 0)
			{
				printf("%d",i);
				chk[i]--;
			}
		}
		printf("\n");
	}
	return 0;
}