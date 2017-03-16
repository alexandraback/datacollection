#include <cstdio>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
int main(){
	int t,no=0; scanf("%d",&t);
	while(t--){
		vector<double> A,B;
		int n,res; scanf("%d",&n);
		for(int i=0;i<n;i++){
			double T; scanf("%lf",&T);
			A.pb(T);
		}
		for(int i=0;i<n;i++){
			double T; scanf("%lf",&T);
			B.pb(T);
		}
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		printf("Case #%d: ",++no);
		/*puts("");
		for(int i=0;i<n;i++){
			printf("%.3lf ",A[i]);
		}puts("");
		for(int i=0;i<n;i++){
			printf("%.3lf ",B[i]);
		}puts("");*/
		res=0;
		int L=0,R=n-1,a=0,b=n-1;
		for(int i=0;i<n;i++){
			while(L<n && A[L]<B[i])L++;
			if(L<n)L++,res++;
		}
		L=0,R=n-1,a=0,b=n-1;
		printf("%d ",res); res=0;
		for(int i=0;i<n;i++){
			while(L<n && B[L]<A[i])L++;
			if(L<n)L++,res++;
		}
		printf("%d\n",n-res);
	}
}
