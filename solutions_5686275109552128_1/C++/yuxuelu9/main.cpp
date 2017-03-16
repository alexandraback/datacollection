#include<fstream>
using namespace std;

int main(){
	ifstream fin("B-large.in");
	ofstream fout("B-large.out");
	int t;
	fin>>t;
	int d;
	int p[1000];
	int num,tmp,max;
	for(int k=1;k<=t;k++){
		fin>>d;
		num=1001;
		max=0;
		for(int i=0;i<d;i++){
			fin>>p[i];
			if(max<p[i])max=p[i];
		}
		for(int t=1;t<=max;t++){
			tmp=t;
			for(int i=0;i<d;i++){
				tmp+=(p[i]+t-1)/t-1;
			}
			if(num>tmp)num=tmp;
		}
		fout<<"Case #"<<k<<": "<<num<<endl;
	}
	return 0;
}