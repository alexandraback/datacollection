#include "iostream"
#include "cstdio"
#include "vector"
#include "math.h"
#include "algorithm"
#include "string.h"
#include "sstream"
#include "stack"
#include "queue"
#include "map"
#define maX(a,b) ((a)>(b)?(a):(b))
#define miN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<(0)?(a)*(-1):(a))
#define pb(x) push_back(x)
#define pdd pair<double,double>
#define ll long long
using namespace std;
int main()
{
	int test,tt,n,N,y,i,j;
	cin>>test;
	double D,a,v,T,t;
	
	for(tt=1;tt<=test;tt++){
		printf("Case #%d:\n",tt);
		cin>>D>>N>>y;
		vector<pdd> A(N);
		
		for(i=0;i<N;i++){
			cin>>A[i].first>>A[i].second;
		}
		for(i=0;i<y;i++)
		{
			cin>>a;
			T=0.;
			if(N==2){
				///v=double(A[1].second-A[0].second)/double(A[1].first-A[0].first);
				T=(double(D-A[0].second)*(double)(A[1].first-A[0].first))/double(A[1].second-A[0].second);
			}
			t=sqrt((2.*D)/a);
			double res=maX(T,t);
			printf("%.10lf\n",res);
		}
	}
	return 0;
}
