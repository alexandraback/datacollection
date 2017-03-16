
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
	int T;
	scanf("%d",&T);
	for(int p=1;p<=T;p++){
		printf("Case #%d: ",p);
		int i,j,k,l,s,n,q;
		int a[200];
		scanf("%d%d%d",&n,&s,&q);
		int c1=0, c2=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]>=3*q-2 && q<=(a[i]-1)/3+1){
				c1++;
			}
			else if(a[i]>=3*q-4 && q<=(a[i]-2)/3+2 && a[i]>=2){
				c2++;
			}
		}
		printf("%d\n",c1+min(c2,s));
	}

	return 0;
}
