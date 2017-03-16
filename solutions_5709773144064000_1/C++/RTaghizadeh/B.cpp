#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ofstream fout;
	fout.open("d:\\ans.txt");
	cout.rdbuf(fout.rdbuf());

	ifstream fin;
	fin.open("d:\\1.in");
	cin.rdbuf(fin.rdbuf());
	int t,te;
	cin>>t;
	double c,f,x,s,e;
	for(te=1;te<=t;te++){
		s=0;
		e=2;
		cin>>c>>f>>x;
		while(x/e>c/e+x/(e+f)){
			s+=c/e;
			e+=f;
		}
		s+=x/e;



		cout<<"Case #"<<te<<": ";
		cout.precision(7);
		cout.setf(ios::fixed, ios::floatfield);
		cout<<s<<endl;
	}
	return 0;
}