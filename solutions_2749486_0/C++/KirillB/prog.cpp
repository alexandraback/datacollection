#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <memory.h>
#include <cassert>
#include <time.h>
using namespace std;
#pragma comment(linker, "/STACK:20000000")

typedef vector<int> vi; 
#define sz(a) int((a).size()) 
#define all(c) (c).begin(),(c).end() 

string problem_name = "B-small-attempt2";

void init(){
  freopen((problem_name+".in").c_str(),"rt",stdin);
  freopen((problem_name+".out").c_str(),"wt",stdout);
}

char u[433][433][222];
int a,b;
char s[222];
int ok=0;
int len=0;
int go(int x, int y, int step)
{
	if (step>220) return 0;
	if (x<0) return 0;
	if (y<0) return 0;
	if (x>430) return 0;
	if (y>430) return 0;

	if (ok) return 0;
	if (u[x][y][step]) return 0;
	if (x==a && y==b)
	{
		len=step;
		ok=1;
		return 0;
	}

	u[x][y][step] = 1;

	s[step]='W';
	go(x-step,y,step+1);

	if (ok) return 0;
	s[step]='E';
	go(x+step,y,step+1);

	if (ok) return 0;
	s[step]='S';
	go(x,y-step,step+1);

	if (ok) return 0;
	s[step]='N';
	go(x,y+step,step+1);	

}

int main()
{
    init();


	int tst;
	scanf("%d\n",&tst);

	for (int cas=1;cas<=tst;cas++)
	{
		scanf("%d %d",&a,&b);
		memset(u,0,sizeof(u));
		len=0;
		ok=0;
		a+=200;
		b+=200;

		go(200,200,1);

		if (!ok) while (1);
		printf("Case #%d: ",cas);
		for (int i=1;i<len;i++)
			printf("%c",s[i]);
		printf("\n");

		
		
	}


	




	return 0;
}
