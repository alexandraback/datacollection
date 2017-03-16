#include<fstream>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
	ifstream fin("C-small-attempt0.in");
	ofstream fout("C-small-attempt0.out");
	int tt=0;
	fin>>tt;
	int ans;
	int n;
	int bff[1000];
	int el[1000],ssl[1000];
	int m[1000];
	int ml=0;
	for(int kk=1;kk<=tt;kk++){
		ml=0;
		fin>>n;
		for(int i=0;i<n;i++){
			fin>>bff[i];
			bff[i]--;
			el[i]=0;
			ssl[i]=0;
			m[i]=0;
		}
		for(int i=0;i<n;i++){
			int j=i;
			for(int i=0;i<n;i++)m[i]=0;
			int tl=0;
			while(m[j]==0){
				m[j]=1;
				j=bff[j];
				tl++;
			}
			if(bff[bff[j]]==j){
				if(tl>el[j]){
					el[j]=tl;
					ssl[i]=i;
				}
			}
			else{
				tl=1;
				int tj=j;
				while(bff[tj]!=j){
					tl++;
					tj=bff[tj];
				}
				if(tl>ml)ml=tl;
			}
		}
		int sl=0;
		for(int i=0;i<n;i++){
			sl+=el[i];
			if(bff[bff[i]]==i)sl--;
		}
		ans=ml>sl?ml:sl;
		fout<<"Case #"<<kk<<": "<<ans<<endl;
	}
	return 0;
}