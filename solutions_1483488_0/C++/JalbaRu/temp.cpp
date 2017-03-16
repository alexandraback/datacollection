#pragma comment(linker,"/STACK:256000000")
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;
int main(){
	freopen("C-small-attempt0.in","r",stdin);
	//freopen("B-large.in","r",stdin);
	//freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	vector<vector<int> > g(2000001);
	double ti=clock();
	
	int p[]={1,10,100,1000,10000,100000,1000000};
	for(int i=1;i<=20000;i++)
	{
		int a=i;
		int k=0;
		if(a>=1000){ k+=4; a/=10000;}
		if(a>=100) {k+=3; a/=1000;}
		if(a>=10){ k+=2;a/=100;}
		if(a>=1){ k++; a/=10;}
		a=i;
		vector<int> q;
		for(int j=1;j<k;j++){
			int h=a%p[j];
			int b=a/p[j]+h*p[k-j];
			if(a<b){
				q.push_back(b);
				//cout<<a<<" "<<b<<endl;
				
			}
		}
		sort(q.begin(),q.end());
		for(int j=1;j<q.size();j++)
			if(q[j-1]==q[j]){
				q.erase(q.begin()+j,q.begin()+j+1);
				j--;
			}
		g[a]=q;
	}
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		int ans=0;
		int A,B;
		cin>>A>>B;
		for(int i=A;i<=B;i++)
			for(int j=0;j<g[i].size();j++)
				if(g[i][j]<=B) ans++;
		printf("Case #%d: %d\n",t+1,ans);
	}

	//printf("%lf\n",(clock()-ti)/CLOCKS_PER_SEC);
	
}