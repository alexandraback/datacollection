//UESTC_L3

#include <stdexcept>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <exception>
#include <memory>
#include <locale>
#include <sstream>
#include <set>
#include <list>
#include <bitset>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <string>
#include <utility>
#include <cctype>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <functional>
#include <complex>
#include <valarray>
using namespace std;

double a[1100];
double b[1100];
bool visb[1100];
bool visa[1100];
int n;

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("out.out","w",stdout);
	
	int test;
	scanf("%d",&test);
	int ct=0;
	while(test--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%lf",&a[i]);
		for(int i=0;i<n;i++)scanf("%lf",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		
		int ret1=0,ret2=0;
		memset(visa,0,sizeof(visa));
		memset(visb,0,sizeof(visb));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(visb[j])continue;
				if(b[j]>a[i]){
					visb[j]=true;
					break;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(!visb[i])ret1++;
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++){
				if(visa[j])continue;
				if(a[j]>b[i]){
					visa[j]=true;
					break;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(visa[i])ret2++;
		}
		
		printf("Case #%d: %d %d\n",++ct,ret2,ret1);
	}
	return 0;
}