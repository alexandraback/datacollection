#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cassert>
#include<complex>
using namespace std;

int N,M;
int A[200][200];

bool run()
{
	scanf("%d %d", &N, &M);
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			scanf("%d", &A[i][j]);
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
		{
			bool row=true, col=true;
			for(int k=0;k<N;++k) 
				if(A[k][j] > A[i][j]) col = false;
			for(int k=0;k<M;++k)
				if(A[i][k] > A[i][j]) row = false;
			if(!row && !col) return false;
		}
	return true;
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int test;scanf("%d",&test);
	for(int no=1;no<=test;++no)
	{
		printf("Case #%d: ", no);
		if(run()) puts("YES");
		else puts("NO");
	}
}
