#pragma comment(linker,"/STACK:256000000")
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;
int main(){
	//double ti=clock();
	//freopen("A-small-attempt0.in","r",stdin);
	freopen("A-large.in","r",stdin);
	//freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		int n;
		cin>>n;
		vector<int> a(n);
		int x=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			x+=a[i];
		}
		printf("Case #%d:",t+1);
		for(int i=0;i<n;i++){
			double lt=0,rt=1,md;
			int u=30;
			
			while(u--){
				double sum=0;
				md=(lt+rt)/2;
				double d=md*x+a[i];
				for(int j=0;j<n;j++)
					if(i!=j)
						sum+=max(d-a[j],0.0);
				if(sum<=x*(1-md)) lt=md;
				else rt=md;
			}
			printf(" %.6lf",rt*100);
		}
		printf("\n");
	}
	//printf("%lf\n",(clock()-ti)/CLOCKS_PER_SEC);
}