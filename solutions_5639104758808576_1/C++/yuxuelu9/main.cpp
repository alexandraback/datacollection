#include<fstream>
using namespace std;

int main(){
	ifstream fin("A-large.in");
	ofstream fout("A-large.out");
	int t;
	fin>>t;
	int smax;
	char a[1001];
	int num,sum;
	for(int k=1;k<=t;k++){
		num=0;
		sum=0;
		fin>>smax;
		for(int i=0;i<=smax;i++){
			fin>>a[i];
			if(i>sum&&num<i-sum)num=i-sum;
			sum+=a[i]-'0';
		}
		fout<<"Case #"<<k<<": "<<num<<endl;
	}
	return 0;
}