
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

long long get(int a, int s, int e){
	map<int,int> dd;
	int i,j,k,l;
	int ans=0;
	char t[20],x[20];
	sprintf(t,"%d",a);
	l=strlen(t);
	sprintf(x,"%d",a);
	strcat(t,x);
	sprintf(x,"%%%dd",l);
//	printf("%s\n",x);
	for(i=1;i<l;i++){
		sscanf(t+i,x,&k);
		if(s<k && k<=e && k>a){
			ans+=1-dd[k];
			dd[k]=1;
		}
	}
	return (long long)ans;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int p=1; p<=T; p++){
		int i,j,k,l,a,b;
		long long ans=0;
		scanf("%d%d",&a,&b);
		for(i=a;i<b;i++){
			ans+=get(i,a,b);
		}
		printf("Case #%d: %lld\n",p,ans);
	}
	return 0;
}
