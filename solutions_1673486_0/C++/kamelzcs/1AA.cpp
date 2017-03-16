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
#define SIZE 100010
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
double data[SIZE];
int T,A,B;
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>T;
	for(int tt=1;tt<=T;++tt)
	{
		printf("Case #%d: ",tt);
		scanf("%d%d",&A,&B);
		for(int i=0;i<A;++i) scanf("%lf",&data[i]);
	
		for(int i=1;i<A;++i) data[i]*=data[i-1];
		double ans=B+2;

		double second=data[A-1]*(B-A+1)+(1.0-data[A-1])*(2*B-A+2);
		ans=min(ans,second);
		//cout<<second<<endl;
		double temp=0.0;
		for(int i=A-2;i>=0;i--)
		{
			int num=i+1;
			int pressedBack=A-1-i;
			temp+=data[i]*(pressedBack+B-num+1)+(1.0-data[i])*(pressedBack+B-num+1+B+1);
			ans=min(ans,temp);
			//cout<<temp<<endl;
		}	
		ans=min(ans,A+B+2.0);
		printf("%.6lf\n",ans);
	}

	return 0;
}