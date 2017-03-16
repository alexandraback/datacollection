// =====================================================================================
//       Filename:  BullsEye.cpp
//    Description:  
//        Created:  04/27/2013 07:01:13 AM
//         Author:  BrOkEN@!
// =====================================================================================

#include<fstream>
#include<iostream>
#include<sstream>
#include<bitset>
#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>
#include<cassert>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>

#define FOR(i,a,b) for(typeof((a)) i=(a); i <= (b) ; ++i)       
#define FOREACH(it,x) for(typeof((x).begin()) it=(x).begin(); it != (x).end() ; ++it)   
#define MAX 101


using namespace std;

typedef pair<int,int> PI;
typedef vector<PI> VI;

typedef long long int __int64;

__int64 r=0,k=0;


__int64 solve(){
//	printf("%lld\t%lld\n",r,k);

	__int64 c=0,u=0;

	for(int j=0;j<k;j=j+2){
		u=u+(((r+j+1)*(r+j+1)-(r+j)*(r+j)));
		if(u>k)
			break;
		else
			c++;
	}


	return c;
}


int main(){
	int T=0;
	scanf("%d",&T);
	FOR(t,1,T){
		scanf("%lld %lld",&r,&k);	
		printf("Case #%d: %lld\n",t,solve());
	}


	return 0;
}

