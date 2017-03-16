#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//istream& fin = cin;
//ifstream fin ("A-sample.txt");
//ifstream fin ("A-small-attempt1.in");
//ofstream fout ("A-small-attempt1.out");
ifstream fin ("A-large.in");
ofstream fout ("A-large.out");
//ostream& fout = cout;

int d[200];

int main(){
	fout.precision(5);
	int t,n;
	fin >> t;
	for(int i=1; i<=t; i++){
    fout << "Case #" << i << ":";
		fin >> n;
		int sum=0;
		for(int j=0; j<n; j++){
			fin >> d[j];
			sum+=d[j];
		}
		double avg=sum*2.0/n;
		int sum2=0;
		int n2=0;
		for(int j=0; j<n; j++){
			if(d[j]<avg){
				sum2+=d[j];
				n2++;
			}
		}
		double avg2=double(sum+sum2)/n2;
		for(int j=0; j<n; j++){
			if(d[j]<avg){
				double tmp = (avg2-d[j])*100/sum;
				fout << ' ' << fixed << tmp;
			}else{
				fout << ' ' << 0.0;
			}
		}
		fout << endl;
	}
	system("pause");
}
