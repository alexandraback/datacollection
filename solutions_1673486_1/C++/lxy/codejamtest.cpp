#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

//BEGINTEMPLATE_BY_ACRUSH_TOPCODER
#define SIZE(X) ((int)(X.size()))//NOTES:SIZE(
#define LENGTH(X) ((int)(X.length()))//NOTES:LENGTH(
#define MP(X,Y) make_pair(X,Y)//NOTES:MP(
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
#define two(X) (1<<(X))//NOTES:two(
#define twoL(X) (((int64)(1))<<(X))//NOTES:twoL(
#define contain(S,X) (((S)&two(X))!=0)//NOTES:contain(
#define containL(S,X) (((S)&twoL(X))!=0)//NOTES:containL(


using namespace std;

vector<double> vd;

int A,B;

double solve()
{
	double expect = B+2;
	double mul=1;

	for(int i = 0;i< A;i++)
	{
		mul*=vd[i];
		double tmpExp = mul *(B-A+1+2*(A-1-i))+(1-mul)*(B-A+1+2*(A-1-i)+B+1);
		if(tmpExp < expect)
			expect = tmpExp;
	}

	return expect;
}

int main()
{
	//	freopen("D.in","r",stdin);
		//freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
	//	freopen("D-small-attempt1.in","r",stdin);freopen("D-small-attempt1.out","w",stdout);
	//	freopen("D-small-attempt2.in","r",stdin);freopen("D-small-attempt2.out","w",stdout);
	  freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		printf("Case #%d:",caseId);
		scanf("%d %d",&A,&B);
		vd.clear();
		for(int i = 0;i<A;i++)
		{
			double inp;
			scanf("%lf",&inp);
			vd.push_back(inp);
		}
		double result = solve();
		printf(" %.6f\n",result);
		fflush(stdout);
	}
	return 0;
}