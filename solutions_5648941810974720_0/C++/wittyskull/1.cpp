#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 3.1415926535897932
#define inf 10000000000000
char str[10009];
int ar[30];
int cunt[35];
int main()
{   
	int t;
	scanf("%d",&t);
	int y=0;
	while(t--)
	{
		y++;
		int i,j,n;
		for(i=0;i<=28;i++)
		{
			ar[i]=0;
			cunt[i]=0;
		}
		scanf("%s",str);
		n=strlen(str);
		for(i=0;i<n;i++)
		{
			ar[str[i]-'A']++;
		}
		//ZERO
		cunt[0]=ar['Z'-'A'];
		ar['E'-'A']-=ar['Z'-'A'];
		ar['R'-'A']-=ar['Z'-'A'];
		ar['O'-'A']-=ar['Z'-'A'];
		ar['Z'-'A']-=ar['Z'-'A'];

		//TWO
		cunt[2]=ar['W'-'A'];
		ar['T'-'A']-=ar['W'-'A'];
		ar['O'-'A']-=ar['W'-'A'];
		ar['W'-'A']-=ar['W'-'A'];

		//FOUR
		cunt[4]=ar['U'-'A'];
		ar['F'-'A']-=ar['U'-'A'];
		ar['R'-'A']-=ar['U'-'A'];
		ar['O'-'A']-=ar['U'-'A'];
		ar['U'-'A']-=ar['U'-'A'];

		//FIVE
		cunt[5]=ar['F'-'A'];
		ar['I'-'A']-=ar['F'-'A'];
		ar['V'-'A']-=ar['F'-'A'];
		ar['E'-'A']-=ar['F'-'A'];
		ar['F'-'A']-=ar['F'-'A'];

		//SIX
		cunt[6]=ar['X'-'A'];
		ar['S'-'A']-=ar['X'-'A'];
		ar['I'-'A']-=ar['X'-'A'];
		ar['X'-'A']-=ar['X'-'A'];

		//SEVEN
		cunt[7]=ar['V'-'A'];
		ar['S'-'A']-=ar['V'-'A'];
		ar['E'-'A']-=ar['V'-'A'];
		ar['E'-'A']-=ar['V'-'A'];
		ar['N'-'A']-=ar['V'-'A'];
		ar['V'-'A']-=ar['V'-'A'];

		//EIGHT
		cunt[8]=ar['G'-'A'];
		ar['E'-'A']-=ar['G'-'A'];
		ar['I'-'A']-=ar['G'-'A'];
		ar['H'-'A']-=ar['G'-'A'];
		ar['T'-'A']-=ar['G'-'A'];
		ar['G'-'A']-=ar['G'-'A'];

		//NINE
		cunt[9]=ar['I'-'A'];
		ar['N'-'A']-=ar['I'-'A'];
		ar['N'-'A']-=ar['I'-'A'];
		ar['E'-'A']-=ar['I'-'A'];
		ar['I'-'A']-=ar['I'-'A'];

		//ONE
		cunt[1]=ar['O'-'A'];
		ar['N'-'A']-=ar['O'-'A'];
		ar['E'-'A']-=ar['O'-'A'];
		ar['O'-'A']-=ar['O'-'A'];

		cunt[3]=ar['T'-'A'];
		printf("Case #%d: ",y);
		for(i=0;i<=9;i++)
		{
			for(j=1;j<=cunt[i];j++)
			printf("%d",i);	
		}
		printf("\n");
	}
	return 0;
}