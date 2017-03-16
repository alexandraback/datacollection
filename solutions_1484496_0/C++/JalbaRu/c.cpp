#pragma comment(linker,"/STACK:256000000")
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;
int main(){
	//double ti=clock();
	freopen("C-small-attempt0.in","r",stdin);
	//freopen("C-large.in","r",stdin);
	//freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		vector<int> m(21*100000);
		int pr=1;
		for(int i=0;i<(1<<n);i++)
		{
			int sum=0;
			for(int j=0;j<n;j++)
				if((1<<j)&i)
					sum+=a[j];
			if(m[sum]!=0){
				pr=0;
				printf("Case #%d:\n",t+1);
				vector<int> p;
				for(int j=0;j<n;j++)
					if((1<<j)&m[sum]) p.push_back(a[j]);
				for(int j=0;j<p.size();j++)
				{
					if(j) printf(" ");
					printf("%d",p[j]);
				}
				printf("\n");
				p.clear();
				for(int j=0;j<n;j++)
					if((1<<j)&i) p.push_back(a[j]);
				for(int j=0;j<p.size();j++)
				{
					if(j) printf(" ");
					printf("%d",p[j]);
				}
				printf("\n");
				break;
			}
			else m[sum]=i;
		}
		if(pr) printf("Case #%d:\nImpossible\n",t+1);

	}
	//printf("%lf\n",(clock()-ti)/CLOCKS_PER_SEC);
}