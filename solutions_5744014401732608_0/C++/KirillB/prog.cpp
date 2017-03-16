
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <cassert>



using namespace std;
#pragma comment(linker, "/STACK:50000000")

typedef vector<int> vi; 
#define sz(a) int((a).size()) 
#define all(c) (c).begin(),(c).end() 

string problem_name = "B-small-attempt0(7)";

void init(){
  freopen((problem_name+".in").c_str(),"rt",stdin);
  freopen((problem_name+".out").c_str(),"wt",stdout);
}


int mas[55][55];

int main()
{
	init();

	int tst;
	scanf("%d\n",&tst);

	for (int cas = 1; cas<=tst;cas++)
	{

		int n;
		long long m;
		scanf("%d%lld",&n,&m);
		vi d;

		memset(mas,0,sizeof(mas));
		for (int i=n-1;i>1;i--)
		{
			for (int j=i+1;j<=n;j++)
				mas[i][j]=1;		
		}
		
		for (int i=n-2;i>=2;i--)
		if ((1ll<<(i-1))<=m)
		{
			m-=(1ll<<(i-1));
			mas[1][n-i]=1;
		}

		if (m)
		{
			mas[1][n]=1;
			m--;
		}
		if (m==1 && n>2)
		{
			m--;
			mas[1][n-1]=1;
		
		}

		if (m!=0)
		{
			printf("Case #%d: IMPOSSIBLE\n",cas);
		} else
		{
			printf("Case #%d: POSSIBLE\n",cas);

			for (int i=1;i<=n;i++) {
				for (int j=1;j<=n;j++)
					printf("%d",mas[i][j]);
			
				printf("\n");
			}
		}




		
		
	
	}


	return 0;
}
