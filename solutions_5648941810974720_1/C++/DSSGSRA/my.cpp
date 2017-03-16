#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<queue>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define rep(i,k,n) for(int i=(k);i<=(n);i++)
#define rep0(i,n) for(int i=0;i<(n);i++)
#define red(i,k,n) for(int i=(k);i>=(n);i--)
#define sqr(x) ((x)*(x))
#define clr(x,y) memset((x),(y),sizeof(x))
#define pb push_back
#define mod 1000000007

const char ss[20][10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int cnt[200],cc[20];
char s[100010];

int main()
{
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",++cas);
		scanf("%s",s);
		int len=strlen(s);
		clr(cnt,0);clr(cc,0);
		for(int i=0;i<len;i++)cnt[s[i]]++;
		//0
		cc[0]=min(min(cnt['Z'],cnt['E']),min(cnt['R'],cnt['O']));
		cnt['Z']-=cc[0];cnt['E']-=cc[0];cnt['R']-=cc[0];cnt['O']-=cc[0];
		//2
		cc[2]=min(min(cnt['T'],cnt['W']),cnt['O']);
		cnt['T']-=cc[2];cnt['W']-=cc[2];cnt['O']-=cc[2];
		//4
		cc[4]=min(min(cnt['F'],cnt['O']),min(cnt['U'],cnt['R']));
		cnt['F']-=cc[4];cnt['O']-=cc[4];cnt['R']-=cc[4];cnt['U']-=cc[4];
		//6
		cc[6]=min(min(cnt['S'],cnt['I']),cnt['X']);
		cnt['S']-=cc[6];cnt['I']-=cc[6];cnt['X']-=cc[6];
		//8
		cc[8]=min(cnt['T'],min(min(cnt['E'],cnt['I']),min(cnt['G'],cnt['H'])));
		cnt['T']-=cc[8];cnt['E']-=cc[8];cnt['G']-=cc[8];cnt['H']-=cc[8];cnt['I']-=cc[8];
		//1
		cc[1]=min(min(cnt['O'],cnt['E']),cnt['N']);
		cnt['N']-=cc[1];cnt['E']-=cc[1];cnt['O']-=cc[1];
		//5
		cc[5]=min(min(cnt['F'],cnt['E']),min(cnt['I'],cnt['V']));
		cnt['F']-=cc[5];cnt['E']-=cc[5];cnt['I']-=cc[5];cnt['V']-=cc[5];
		//3
		cc[3]=min(min(cnt['T'],cnt['E']/2),min(cnt['R'],cnt['H']));
		cnt['T']-=cc[3];cnt['E']-=cc[3]*2;cnt['R']-=cc[3];cnt['H']-=cc[3];
		//7
		cc[7]=min(min(cnt['S'],cnt['E']/2),min(cnt['V'],cnt['N']));
		cnt['S']-=cc[7];cnt['E']-=cc[7]*2;cnt['V']-=cc[7];cnt['N']-=cc[7];
		//9
		cc[9]=min(min(cnt['N']/2,cnt['E']),cnt['I']);
		cnt['N']-=cc[9]*2;cnt['E']-=cc[9];cnt['I']-=cc[9];
		
		for(int i=0;i<=9;i++)
		{
			while(cc[i]--)putchar('0'+i);
		}
		puts("");
	}
	
	return 0;
}
