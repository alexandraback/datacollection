#include<fstream>
#include<string.h>
using namespace std;

int main(){
	ifstream fin("D-large.in");
	ofstream fout("D-large.out");
	int t=0;
	fin>>t;
	bool ans;
	int k,c,s;
	for(int kk=1;kk<=t;kk++){
		fin>>k>>c>>s;
		fout<<"Case #"<<kk<<": ";
		if(s*c<k){
			fout<<"IMPOSSIBLE"<<endl;
		}
		else{
			long long n=0;
			int tmp=0;
			if(c>=k){
				for(int i=0;i<k;i++){
					n=n*k+i;
				}
				fout<<n+1<<' '<<endl;
			}
			else{
				for(int i=tmp;i<tmp+c;i++){
					n=n*k+i;
				}
				fout<<n+1<<' ';
				tmp+=c;
				n=0;
				while(tmp+c<k){
					for(int i=tmp;i<tmp+c;i++){
						n=n*k+i;
					}
					fout<<n+1<<' ';
					tmp+=c;
					n=0;
				};
				for(int i=tmp;i<k;i++){
					n=n*k+i;
				}
				fout<<n+1<<' '<<endl;
			}
		}
		//fout<<"Case #"<<kk<<": "<<ans<<endl;
	}
	return 0;
}