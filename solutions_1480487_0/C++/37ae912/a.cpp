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


// data define

const int maxn=1000+5;

int n;
double d[300];
double sum;

double solve(int i)
{
    double res=0;
    double min=1e9;
    for(int j=0;j<n;++j){
        if(j==i)continue;
        if(min>d[j]) min=d[j];    
    }
    
    res = 0.5*(min-d[i])/sum+0.5;
    
    return res;
}
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		scanf("%d",&n);
		sum=0;
		double s2=0;
		for (int i=0;i<n;i++){
            scanf("%lf",d+i);
            sum+=d[i];
        }
		//double ret=solve();
		printf("Case #%d: ",case_id);
		
        double avg = sum/n;
        
        s2=sum;
        int cnt=0;
        for(int i=0;i<n;++i){
            if(d[i]+1e-7>=2*avg)s2-=d[i];    
            else cnt++;
        }
		
		double avg2=(s2+sum)/cnt;
		//printf("avg=%lf\n",avg);
		
		double ret;
		for(int i=0;i<n;++i){
            if(d[i]>=avg2)ret=0.0;
            else ret = (avg2-d[i])/sum;
		  //ret=  //solve(i);
		  if(i)putchar(' ');
          printf("%lf",ret*100);
        }
        puts("");
    }
	return 0;
}
