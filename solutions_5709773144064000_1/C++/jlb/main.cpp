#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <utility>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define FOR(i,n) for(int i=0;i<(int)(n);++i)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define FORR(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define FORE(i,n) for(int i=0;i<=(int)(n);++i)
#define MP(X,Y) make_pair(X,Y)
typedef pair<int,int> ipair;
typedef long long int64;
#define MF(X,val) memset(X,val,sizeof(X))
const double eps=1.0e-6;


//const int MAX_N=1000001;
const int MAX_N=51;

int A[4][4];
int B[4][4];

int main(int argc,char** argv){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int TC;
	cin>>TC;
	double time,t1,t2;
	double C,F,X;
	double rate,n;
	REP(tc,1,TC+1){
		time=0;
		rate=2;
		cin>>C>>F>>X;
		//n=ceil((X-C)*(F+2)/(C*F));
		//int nn=n;
		//FOR(i,nn){
		//	time+=C/rate;
		//	rate+=F;
		//}
		//time+=X/rate;
		while(true){
			t1=X/rate;
			t2=C/rate+X/(rate+F);
			if(t1<t2){
				time+=t1;
				break;
			}else{
				time+=C/rate;
				rate+=F;
			}
		}
		printf("Case #%d: %.7lf\n",tc,time);
	}
	return 0;
}