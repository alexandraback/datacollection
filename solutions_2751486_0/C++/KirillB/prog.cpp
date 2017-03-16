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

string problem_name = "A-small-attempt0(2)";

void init(){
  freopen((problem_name+".in").c_str(),"rt",stdin);
  freopen((problem_name+".out").c_str(),"wt",stdout);
}

char s[1000100];

int isv(char c)
{
	return c=='a' || c == 'e' || c=='i' || c=='o' || c=='u';
}
int main()
{
    init();


	int tst;
	scanf("%d\n",&tst);

	for (int cas=1;cas<=tst;cas++)
	{
		int k;
		scanf("%s %d\n",&s,&k);
		long long res=0;
		int len=strlen(s);
		int p=-1;
		int col=0;
		for (int i=0;i<len;i++)
		{
			while (col<k)
			{
				p++;			
				if (p>=len) break;
				if (isv(s[p])) col=0; else
				col++;
			}		
			if (p>=len) break;
			if (col>=k) res+=len-p;
			if (p-i+1==col) col--;
		}
		
		printf("Case #%d: %lld\n",cas,res);
	}


	




	return 0;
}
