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
#define FILENAME "B-small-attempt0"

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
		int x,y;
		cin>>x>>y;
		printf("Case #%d: ",t+1);
		if(x>0){
			REP(i,abs(x)){
				printf("WE");
			}
		}
		else{
			REP(i,abs(x)){
				printf("EW");
			}
		}
		if(y>0){
				REP(i,abs(y)){
					printf("SN");
				}
			}
			else{
				REP(i,abs(y)){
					printf("NS");
				}
			}
		printf("\n");
		cerr<<t+1<<endl;
		fflush(stdout);
	}
}
