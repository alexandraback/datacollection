#include<fstream>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
	ifstream fin("B-large.in");
	ofstream fout("B-large.out");
	int tt=0;
	fin>>tt;
	int h[50];
	int ans;
	int n,t;
	int hh[2501];
	for(int kk=1;kk<=tt;kk++){
		fin>>n;
		for(int i=0;i<2501;i++){
			hh[i]=0;
		}
		for(int i=0;i<2*n-1;i++){
			for(int j=0;j<n;j++){
				fin>>t;
				hh[t]++;
			}
		}
		int i=0;
		for(int j=1;j<2501;j++){
			if(hh[j]%2==1){
				h[i]=j;
				i++;
			}
		}
		sort(h,h+n);
		//fout<<"Case #"<<kk<<": "<<ans<<endl;
		fout<<"Case #"<<kk<<": ";
		for(int j=0;j<n;j++){
			fout<<h[j]<<' ';
		}
		fout<<endl;
	}
	return 0;
}