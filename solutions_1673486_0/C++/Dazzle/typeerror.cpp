#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

double p[100000];
double ap[100000];
double expect[100000];
void all_correct(double p[],double ap[],int len){
	ap[0]=p[0];
	for(int i=1;i<len;i++){
		ap[i]=p[i]*ap[i-1];
	}
	return;
}
void expectation(double ap[],double expect[],int A,int B){
	for(int i=0;i<A;i++){
		expect[i]=0;
		expect[i]+=ap[i]*(2*(A-1-i)+(B-A+1));
		expect[i]+=(1-ap[i])*(2*(A-1-i)+(B-A+1)+B+1);
	}
	return;
}
int main()
{
	ifstream fin;
	fin.open("E:\\codejam\\input.txt");
	ofstream fout;
	fout.open("E:\\codejam\\output.txt");
	int T;
	int A,B;
	fin>>T;
	for(int t=1;t<=T;t++){
		fin>>A>>B;
		for(int i=0;i<A;i++){
			fin>>p[i];
		}
		cout<<A<<B<<endl;
		all_correct(p,ap,A);
		expectation(ap,expect,A,B);
		for(int i=0;i<A;i++){
			cout<<expect[i]<<" ";
		}
		double threshold=2+B;
		cout<<threshold<<endl;
		double best_expect=threshold;
		for(int i=0;i<A;i++){
			if(expect[i]<best_expect){
				best_expect=expect[i];
			}
		}
		fout<<"Case #"<<t<<": ";
		fout<<fixed<<setprecision(6)<<best_expect<<endl;
	}
	return 0;
}