#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 99999;

double P[MAXN];

void Readata(){

	ifstream fin("input.txt");
	int T;
	fin >> T;
	int i;
	int j ;

	int A , B;

	for ( i = 0 ; i < T ; i++ ) {
		fin >> A >> B;

		for ( j = 1 ; j < A+1 ; j++ ) {
			double x ;
			fin >> x;
			if ( j > 1 ) P[j]=P[j-1]*x; else P[j]=x;
		}

		P[0]=1;

		double sol = P[A]*(B-A+1)+(1-P[A])*(2*B+2-A);
		
		//cout << " case 1 " << sol << endl;
		if ( sol > B+2 ) sol=B+2;
		int k ;		
		for ( k = 1 ; k <= A ; k++ ){
			double val = P[A-k]*(B-A+2*k+1)+(1-P[A-k])*(B-A+2*k+1+B+1);
			//cout << k << " " << val << endl;
			if ( val < sol ) sol=val;
		}
 
		cout.unsetf(ios::floatfield); 
		cout.precision(6);
		cout  << "Case #" << fixed << i+1 << ": " << sol << endl;  

	       
		
	}	

	
}
int main()
{
	Readata();
	return 0;
}
