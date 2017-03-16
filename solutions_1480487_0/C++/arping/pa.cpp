#include <iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstdlib>
#include <iomanip>
using namespace std;

int main() {
	int ts;cin>>ts;
	for(int t=1;t<=ts;t++){
		int N;cin>>N;
		int X=0;
		int s[300];for(int k=0;k<N;k++){
			cin>>s[k];
			X+=s[k];
		}
		cout<<"Case #"<<t<<":";
		double a[300];
		for(int k=0;k<N;k++) a[k]=1;
		bool again=true;
		while(again){
			again=false;
			double sum=0,count=0;
			for(int k=0;k<N;k++)if(a[k]>0){sum+=s[k];count++;}
			double same=(sum+X)/count;
			for(int k=0;k<N;k++){
				if(a[k]>0){
					a[k]=(same-s[k])/X;
					if(a[k]<=0){a[k]=0;again=true;}
				}
			}
		}

		for(int k=0;k<N;k++){
			a[k]*=100;
//			long long n=int(a[k]);
//			long long r=long long((a[k]-n)*10000000);
			cout<<" "<<fixed<<setprecision(6)<<a[k];
		}
		cout<<endl;
	}
	return 0;
}