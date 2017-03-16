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

string problem_name = "A-small-attempt1";

void init(){
  freopen((problem_name+".in").c_str(),"rt",stdin);
 freopen((problem_name+".out").c_str(),"wt",stdout);
}


int main()
{

    init();

	int tst;
	scanf("%d\n",&tst);

	for (int cas=1;cas<=tst;cas++) 
	{
		int a,n;
		scanf("%d %d",&a,&n);
		vi mas;
		for (int i=0;i<n;i++)
		{
			int t;
			scanf("%d",&t);
			mas.push_back(t);
		}
		int res=0;
		sort(all(mas));
		if (a==1) res=n; else
		for (int i=0;i<n;i++)
		{
			if (mas[i]>=a)
			{
				int t=a;
				int cur=0;
				while (t<=mas[i]) 
				{
					t+=t-1;
					cur++;
				}
				if (n-i<=cur)
				{
					res+=n-i;
					break;
				}
				a=t;
				res+=cur;
			};
				a+=mas[i];
		//	res--;
		}
	
	
		printf("Case #%d: %d\n",cas,res);
	}




	return 0;
}
