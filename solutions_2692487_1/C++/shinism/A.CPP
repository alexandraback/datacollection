#include<fstream>
#include<algorithm>
#define N 100003
using namespace std;
int T,n,m,A[N],sol;
void solve();
int main()
{
	FILE *in,*out;
	in=fopen("input.txt","r");
	out=fopen("output.txt","w");
	int i,j;
	fscanf(in,"%d",&T);
	for(i=0;i<T;i++){
		fscanf(in,"%d %d",&m,&n);
		for(j=0;j<n;j++) fscanf(in,"%d",&A[j]);
		sol=N;
		solve();
		fprintf(out,"Case #%d: %d\n",i+1,sol);
	}
	return 0;
}

void solve()
{
	int i,pp=0;

	sort(A,A+n);
	for(i=0;i<n;i++){
		if(m>A[i]){
			m+=A[i]; continue;
		}
		if(sol>pp+n-i){
			sol=pp+n-i;
		}
		if(m==1){
			sol=n; return;
		}
		for(;m<=A[i];){
			pp++;
			m+=m-1;
		}
		m+=A[i];
	}
	if(sol>pp){
		sol=pp;
	}
}