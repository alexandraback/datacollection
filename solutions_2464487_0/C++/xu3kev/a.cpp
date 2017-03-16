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


	long long int r;
	long long int t;

	long long int n;
	long long int up;
	long long int lo;
	long long int tmp;

	long long int up2;
	long long int LL;

	for(int T=1;T<=TT;++T){
		cout<<"Case #"<<T<<": ";
		cin>>r>>t;

		//LL=2000000000000000001LL;
		up=1000000001;
		//up2=LL/(2r);

		if(up2<up)
			up=up2;

		lo=0;
		//cout<<up<<endl;
		while(lo<up){
			
			//cout<<up<<" "<<lo<<"\n";
			n=(up+lo+1)/2;
			tmp=2*n*n+(2*r-1)*n;

			//cout<<tmp<<" ? "<<n<<" "<<2*n*n<<" "<<(2*r-1)*n<<endl;

			if(tmp<=t){
				lo=n;
			}
			else{
				up=n-1;
			}

		}
		cout<<lo;

		cout<<"\n";
	}
	return 0;
}




//int compare(const void* a,const void* b){
//	//return *((int*)a)-*((int*)b);
//	return ((W*)a)->d-((W*)b)->d;
//}
//qsort(a,10,sizeof(int),compare);
