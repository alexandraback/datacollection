#include<cstdio>
#include<cassert>
#include<algorithm>
using namespace std;
int N;
char S[100];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int testcount;scanf("%d",&testcount);
	while(testcount--)
	{
		scanf("%s",S);
		N=-1;while(S[++N]);
		N=unique(S,S+N)-S;
		if(S[N-1]=='+')N--;
		static int kase=0;
		printf("Case #%d: ",++kase);
		printf("%d\n",N);
	}
	return 0;
}
