#include<stdio.h>
#include<algorithm>
#include<functional>
int main()
{
	int T, caseNum;
	scanf("%d",&T);
	for(caseNum = 1; caseNum <= T; ++caseNum)
	{
		int N,S,p,t[100],i,j;
		scanf("%d%d%d",&N,&S,&p);
		for(i=0;i<N;++i)scanf("%d",t+i);
		int res=0;

		std::sort(t,t+N,std::greater<int>());
		for(i=0; i<N; ++i)
		{
			if((t[i]+2)/3>=p)
				++res;
			else if( S && t[i] && (t[i]+1)/3+1>=p)
				++res, --S;
			else break;
		}

		printf("Case #%d: %d", caseNum,res);

		puts("");
	}
	return 0;
}
/*

驚いてない:最大のスコア=(合計スコア+2)/3
驚いた:最大スコア=(合計スコア+1)/3+1

以上、合計スコアが高い順から貪欲にどうぞ

case#3が丁寧すぎて泣ける


*/
