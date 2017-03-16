#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool myfunction ( pair<int,int> i , pair <int,int> j ) {
	if ( i.first < j.first ) return 1;
	if ( ( i.first == j.first ) && ( i.second < j.second ) ) return 1;
	return 0; 
}

void Readata(){

	ifstream fin("input.txt");
	int T;
	fin >> T ;
	vector <pair<int,int> > vect; 
	int i ,j ;

	//cout << T << endl;
	for ( j = 0 ; j <  T ; j++ ) {

		vector<int> v;
		int n ;
		fin >> n;

		//cout << n << endl;
		int Sum = 0;
		for (  i = 0 ; i < n ; i++ ) {

			int x;
			fin >> x;
			v.push_back(x);
			Sum+=x;
		}

		//cout << Sum << endl;

		//sort(v.begin(),v.end());

		/*for ( i = 0 ; i < n ; i++ )
			cout << v[i] << " ";
		cout << endl;*/

		float avg1=(2*Sum);

		//cout << "avg1 " << avg1 <<  endl;

		avg1=avg1/n;

		//cout << " avg1 " << avg1 << endl;
		
		int num = 0;

		int val = 0;

		for ( i = 0 ; i < n ; i++ ) {

			if ( v[i] <  avg1 )  { num++; val+=v[i]; } 
		}
		
		//cout << " val " << val << " num " << num << endl;
		float avg2 = (Sum+val);
		avg2=avg2/num;

		//cout << " avg 2 " << avg2 << endl;

		vector <long double> per;
		for ( i = 0 ; i < n ; i++ ) {

			if ( v[i] < avg2 ) {
				long double p = avg2-v[i];

				p=p/(Sum);
				p=p*100;
				per.push_back(p);
			}
			else per.push_back(0.00000);
 
		}

		cout.precision(6);
		cout << "Case #" << j+1 << ": ";
		for ( i = 0 ; i < n ; i++ ) 
			cout << fixed << per[i] << " ";
		cout << endl;
	}

	/*double y = 2;
	cout.precision(4);
	cout << fixed << y  <<  endl;*/

}

int main()
{
	Readata();
	return 0;
}
