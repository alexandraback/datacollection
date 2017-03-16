#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <cmath>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <memory.h>


using namespace std;



#define PI 3.14159265359
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define OPENFILE
#define FILENAME "A-large"

typedef long long ll;

int main() {
#ifdef OPENFILE
		char INPUTF[30]=FILENAME;
		char INPUTF2[30]=FILENAME;
		freopen(strcat(INPUTF,".in"),"r",stdin);//redirects standard input
		freopen(strcat(INPUTF2,".out"),"w",stdout);//redirects standard output
#endif
	int T;
	cin>>T;
	REP(t,T){
		int A,N;
		int m[105];
		cin>>A>>N;
		REP(i,N)
			cin>>m[i];
		sort(m,m+N);
		int res=10000000;
		int num[105];
		num[0]=0;
		int sum=A;
		REP(i,N){
			if(sum==1){
				num[i+1]=1000000;
				continue;
			}
			num[i+1]=num[i];
			if(sum>m[i]){
				sum+=m[i];
			}
			else{
				while(sum<=m[i]){
					num[i+1]++;
					sum=2*sum-1;
				}
				sum+=m[i];
			}
		}
		REP(i,N){
			res=min(res,num[i+1]+N-1-i);
		}
		res=min(res,N);
		printf("Case #%d: %d\n",t+1,res);
		cerr<<t+1<<endl;
		fflush(stdout);
	}
}
