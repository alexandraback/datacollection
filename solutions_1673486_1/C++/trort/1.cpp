#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

double _main(){
	int A, B;
	double p[100001];
	int i, j, k;
	fin>>A>>B;
	for(i=0; i<A; i++) fin>>p[i];
	
	double exp[100002];
	double pie;
	int back;
	for(back = 0; back <= A; back++){
		pie = 1;
		for(i = 0; i < A-back; i++){
			pie *= p[i];
		}
		exp[back] = 2*back + (B-A) + 1 + (1-pie)*(B+1);
	}
	exp[A+1] = B+2;
	
	double best = 99999999;
	//fout<<endl;
	for(i=0; i<=A+1; i++){
		if(exp[i]<best) best = exp[i];
		//fout<<exp[i]<<endl;
	}
	return best;
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            fout.precision(10);
            fout<<_main();
            fout<<endl;
    }
}
