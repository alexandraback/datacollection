#include <cstdlib>
#include <cstdio>
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

typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;

#define PB push_back
#define MP make_pair

struct attack
{
    int d,w,e,s ;
} ;

int day[1001] ;
int h[1000] ;
attack a[1001] ;
vector<attack> aa[1001] ;

int N,d,n,w,e,s,dd,dp,ds,TN,td ;

int main()
{
	int T ;
	cin>>T ;
	for (int t=1;t<=T;t++)
	{
		cin>>N ;
		TN = 0 ;
		memset(h,0,sizeof(h)) ;
		for (int i=0;i<N;i++){
			cin>>d>>n>>w>>e>>s>>dd>>dp>>ds ;
			e += 500 ; w += 500 ;
			for (int j=0;j<n;j++){
				day[TN] = d + j * dd ;

				a[TN].d = d + j * dd ;
				a[TN].e = e + j * dp ;
				a[TN].w = w + j * dp ;
				a[TN].s = s + j * ds ;
				TN++ ;
			}
		}
		sort(day,day+TN) ;
		td = unique(day,day+TN) - day ;
		for (int i=0;i<=500;i++)
			aa[i].clear() ;
		for (int j=0;j<TN;j++){
			for (int i=0;i<td;i++){
				//cout<<"sdf"<<endl ;
				if (a[j].d==day[i]){
					aa[i].push_back(a[j]) ;
				}
			}
		}
		int res = 0 ;
		for (int i=0;i<td;i++){
			for (int j=0;j<aa[i].size();j++){
				bool flag = 1 ;
				for (int k=aa[i][j].w;k<aa[i][j].e;k++){
					if (h[k]<aa[i][j].s){
						flag = 0 ;
						break ;
					}
				}
				if (!flag) res++ ;
			}
			for (int j=0;j<aa[i].size();j++){
				for (int k=aa[i][j].w;k<aa[i][j].e;k++)	{
					h[k] = max(h[k],aa[i][j].s) ;
				}
			}
		}
		printf("Case #%d: %d\n",t,res) ;
	}
}
