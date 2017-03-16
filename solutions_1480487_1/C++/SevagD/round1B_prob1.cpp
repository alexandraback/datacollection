#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main ()
{
	ifstream cin;
	cin.open("A-large.in");
	ofstream cout;
	cout.open("safety_large.out");

	int T, N, J[300];
	double mi[300];

	cin>>T;
	for (int t=1; t<=T; t++)
	{
		cin>>N;
		int X=0;
		for (int i=0; i<N; i++){
			cin>>J[i];
			X+=J[i];
		}

		double target= (2.0*(double)X)/(double)N;
		int N_higher=0;

		double X2= 2*X;
		for (int i=0; i<N; i++){
			if (J[i]>=target)
			{
				N_higher++;
				X2-=J[i];
			}
		}
		
		target = X2/(N-N_higher);

		for (int i=0; i<N; i++){
			if (J[i]<target){
				mi[i] = ( (target - (double)J[i]) / (double)X )*100;
			}
			else
				mi[i]=0;
		}
		cout<<"Case #"<<t<<": ";
		for (int i=0; i<N; i++)
			cout<<fixed<<setprecision(6)<<mi[i]<<' ';
		cout<<endl;
	}


	return 0;
}