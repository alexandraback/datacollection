#include <cstdlib>  
#include <cctype>  
#include <cstring>  
#include <cstdio>  
#include <cmath>  
#include <algorithm>  
#include <vector>  
#include <string>  
#include <iostream>  
#include <sstream>  
#include <map>  
#include <set>  
#include <queue>  
#include <stack>  
#include <fstream>  
#include <numeric>  
#include <iomanip>  
#include <bitset>  
#include <list>  
#include <stdexcept>  
#include <functional>  
#include <utility>  
#include <ctime>  
using namespace std;  

#define PB push_back  
#define MP make_pair  

#define REP(i,n) for(i=0;i<(n);++i)  
#define FOR(i,l,h) for(i=(l);i<=(h);++i)  
#define FORD(i,h,l) for(i=(h);i>=(l);--i)  
#define CLOCK cout << "Clock " << (double)clock()/CLOCKS_PER_SEC << endl
const int maxs = 100000;
double per[maxs];
double cal[maxs];
double res[maxs];
int A,B;


double getAC()
{
	if (A == 1)
	{
		cal[0] = per[0];
		res[0] = (B - A +1) *cal[0] + (B - A + 1 + B+1) * (1-cal[0]);
		res[1] = (1 + B + 1);
		res[2] = (1 + B + 1);
		return std::min(res[0],res[1]);
	}
	else if(A == 2)
	{
		cal[0] = per[0]*per[1];cal[1] = per[0]*(1-per[1]);cal[2] = (1-per[0])*per[1];cal[3] = (1-per[0])*(1-per[1]);
		res[0] = (B-A+1)*cal[0] + (B - A + 1 + B+1)*(1-cal[0]);
		res[1] = (B+1)*(cal[0]+cal[1]) + (B+1+B+1)*(cal[2]+cal[3]);
		res[2] = (2 + B + 1);
		res[3] = (B + 2);
		double ans = res[0];
		for (int i=1;i<4;i++) ans = std::min(res[i],ans);
		return ans;
	}
	else if(A == 3)
	{
		cal[0] = per[0] * per[1] * per[2];
		cal[1] = per[0] * per[1] * (1-per[2]);
		cal[2] = per[0] * (1-per[1]) * per[2];
		cal[3] = per[0] * (1-per[1]) * (1-per[2]);
		cal[4] = (1-per[0]) * per[1] * per[2];
		cal[5] = (1-per[0])* per[1] * (1-per[2]);
		cal[6] = (1-per[0])* (1-per[1]) * per[2];
		cal[7] = (1-per[0])* (1-per[1]) * (1-per[2]);
		res[0] = (B-A+1)*cal[0] + (B-A+1+B+1)*(1-cal[0]);
		res[1] = (1 + B-A+2)*(cal[0]+cal[1]) + (1 + B - A + 2 + B + 1)*(1-cal[0]-cal[1]);
		res[2] = (2 + B-A+3)*(cal[0]+cal[1]+cal[2]+cal[3])+(2 + B-A+3 + B+1)*(1-cal[0]-cal[1]-cal[2]-cal[3]);
		res[3] = (3 + B + 1);
		res[4] = (B + 2);
		double ans = res[0];
		for (int i=1;i<5;i++) ans = std::min(res[i],ans);
		return ans;
	}
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
	//freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int cases=1;cases<=t;cases++)
	{
		cin >> A >> B;
		for (int i=0;i<A;i++)
			cin >> per[i];
		printf("Case #%d: ",cases);
		printf("%.6lf\n",getAC());
	}
	return 0;
}