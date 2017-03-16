#include<stdio.h>
#include<vector>
using namespace std;
struct A
{
	int jj, pp, ss;
};
vector<A> arr;
int jp[20][20], ps[20][20], js[20][20];
int main()
{
	int i, j, k, tt, xx, T, J, P, S, K;
	A x;
	scanf("%d", &T);
	for(tt=1; tt<=T; ++tt)
	{
		scanf("%d%d%d%d", &J, &P, &S, &K);
		for(i=1; i<=J; ++i){
			for(j=1; j<=P; ++j){
				for(k=1; k<=S; ++k){
					jp[i][j]=0; ps[j][k]=0; js[i][k]=0;
				}
			}
		}
		arr.clear();
		for(i=1; i<=J; ++i)
		{
			for(j=1; j<=P; ++j)
			{
				for(k=1; k<=S; ++k)
				{
					x.jj=i; x.pp=j; x.ss=k;
					if(jp[i][j]==K) continue;
					if(ps[j][k]==K) continue;
					if(js[i][k]==K) continue;
					arr.push_back(x);
					++jp[i][j];
					++ps[j][k];
					++js[i][k];
				}
			}
		}
		printf("Case #%d: %d\n", tt, arr.size());
		for(i=0; i<arr.size(); ++i)
		{
			printf("%d %d %d\n", arr[i].jj, arr[i].pp, arr[i].ss);
		}
	}
}