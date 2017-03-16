#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<string>
//#include<map>
//setprecision
using namespace std;
class W{
	public:
//W* l;
//W* r;
int l;
int d;
int y;
};
bool compare(const W w1,const W w2){
	return w1.d<w2.d;
}
int main(){
	int TT;
	cin>>TT;


	int e;
	int r;
	int n;
	int a[11][10];
	int v[10000];
	int mx;
	int over;
	int sc;

	for(int T=1;T<=TT;++T){
		cout<<"Case #"<<T<<": ";
		cin>>e>>r>>n;
		for(int i=0;i<n;++i){
			cin>>v[i];
		}
		for(int i=0;i<=e;++i){
			a[n-1][i]=v[n-1]*i;
		}
		for(int i=n-2;i>=0;--i){
			for(int j=0;j<=e;++j){
				mx=0;
				
				for(int k=0;k<=j;++k){
					sc=k*v[i];
					over=(j-k)+r;
					if(over>e)
						over=e;
					sc+=a[i+1][over];	
					if(sc>mx)
						mx=sc;
				}
				a[i][j]=mx;
			}
		}
		cout<<a[0][e];

		cout<<"\n";
	}
	return 0;
}




//int compare(const void* a,const void* b){
//	//return *((int*)a)-*((int*)b);
//	return ((W*)a)->d-((W*)b)->d;
//}
//qsort(a,10,sizeof(int),compare);
