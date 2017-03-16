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
const int maxs = 100002;
double per[maxs];
double cal[maxs];
int A,B;


double getAC()
{
	double res = 1 + B + 1;
	double tp[maxs];tp[0] = 1.0;//all delete
	int cnt = 0;
	for (int i=A-1;i>=0;i--)
		tp[A-i] = tp[A-i-1] * per[cnt++];
	//for (int i=A;i>=0;i--)
	//	cout << tp[i] << " ";
	//cout << endl;
	for (int i=0;i<=A;i++)
	{
		int tmp = i + i + B - A + 1;
		double tper = tmp * tp[A-i] + (tmp + B + 1) * (1-tp[A-i]);
		res = std::min(res,tper);
	}
	return res;
}
int main()
{
	//freopen("A-small-attempt0.in","r",stdin);freopen("AA-small-attempt0.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
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