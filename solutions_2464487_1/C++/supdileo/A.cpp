#include <iostream>
#include <fstream>

using namespace std;
typedef unsigned long long ULL;
const ULL max_rad = 1e18;

ULL comb(ULL r,ULL k){
	return (2*r+2*k-1)*(k);
}


int main(){
	ifstream cin("A-large.in");
	ofstream cout("A-large.out");

	int ncase;
	cin>>ncase;
	for(int icase=1;icase<=ncase;icase++){
		ULL r,t;
		cin>>r>>t;
		ULL min_r=1,max_r=1;
		while(comb(r,max_r)<=t) max_r *=2;
		ULL k=max_r/2;
		ULL pre,cur,next;
		while(1){
			pre=comb(r,k-1);
			cur=comb(r,k);
			next=comb(r,k+1);
			if(comb(r,k)<=t && comb(r,k+1)>t){
				break;
			}
			else if(comb(r,k+1)<=t){
				min_r=k;
				k=(min_r+max_r+1)/2;
			}
			else if(comb(r,k)>t){
				max_r=k;
				k=(min_r+max_r)/2;
			}
		}		
		cout<<"Case #"<<icase<<": "<<k<<endl;
	}
		
	return 0;
}