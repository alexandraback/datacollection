#include<stdio.h>
#include<string.h>
int Digit(int x)
{
	int res=0;
	while(x)
	{
		x/=10;
		++res;
	}
	return res;
}
int main()
{
	int T, caseNum;
	scanf("%d",&T);
	static long long digit[20]={1,1};
	int i,j,k;
	for(i=2; i<20;++i)
		digit[i]=digit[i-1]*10;
	for(caseNum = 1; caseNum <= T; ++caseNum)
	{
		static int memo[10000001];

		memset(memo,-1,sizeof(memo));
		int A,B;
		scanf("%d%d",&A,&B);
		int n=Digit(A);
		int res=0;
		for(int i=A; i<=B; ++i)
		{
			if(memo[i]>=0)
				continue;
			int next=i;
			int t=1;
			memo[next]=1;
			for(j=1;j<n;++j)
			{
				int t1 = next/digit[n];
				next = (next*10+t1)%digit[n+1];
				if(A<=next && next<=B && memo[next]<0)
					++t;
				memo[next]=1;
			}
			res+=t*(t-1)/2;
		}
		printf("Case #%d: %d\n", caseNum,res);
	}
	return 0;
}
/*

Smallは総当たりで余裕だけど、
Largeは包除原理なり使わないと死ねる

で、包除原理とするなら？
n桁の数字を回転させてできる数字はn個、
そのうち、ある数X以下であると判定するには・・・


・・・Small解法するか・・・


・・・ある数nをローテションしてできる数全て(n含む)個数がxであるとき、
xのはすべて、ローテションすることでnを確保できる、すなわちnの結果を最利用すればよい
・・・メモ化しておけば楽か？
というより、nのローテションでA以上B以下にあるものがx個あるなら、そのロテーション分全部はxC2=(x*(x-1))/2じゃないの？


*/
