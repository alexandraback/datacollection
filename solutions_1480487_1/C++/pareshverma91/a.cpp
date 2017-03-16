
/*Paresh Verma*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <cstring>
#include <queue>		//max heap implementation
#include <limits.h>

#define pub push_back
#define pob pop_back
#define fi first
#define se second
#define debug(a) { for( typeof(a.begin()) it = a.begin() ; it != a.end() ; it++ ) cout << *it << " "; cout << endl; }

using namespace std;

//class comparators for queue and others
class classcomp{
	public:
		bool operator() (const int& l, const int& r)const{
			return l<r;
		}
};


int main(){
	int T,i,j,k,l,n,a[500], m;
	int b[500], sum;
	double c[500];
	scanf("%d",&T);
	for(int p=1;p<=T;p++){
		printf("Case #%d: ", p);
		scanf("%d",&n);
		sum=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		double x,y,z,yy;
		yy=0;
		for(i=0;i<n;i++){
			k=sum;
			l=n;
			while(1){
				x = ((double)k+sum)/(l);
				if(a[i]>=x){
					c[i]=0;
					break;
				}
				k=0;
				m=n;
				for(j=0;j<n;j++){
					if(a[j]>x){
						m--;
					}
					else{
						k+=a[j];
					}
				}
				if(m==l){
					c[i]=(x-a[i])/sum*100;
					break;
				}
				l=m;
			}
			yy+=c[i];
		}
		for(i=0;i<n;i++){
			printf("%lf%c",c[i]*100.0/yy, i==n-1?'\n':' ');
		}
	}
	return 0;
}
