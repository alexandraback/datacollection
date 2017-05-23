#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main(){ 
    ofstream fout("A.out"); 
	int cases;
	cin >> cases;
	long long  input1 , input2;
	for ( int j = 0 ; j < cases ; j ++ ){
		cin >> input1 >> input2;
		if ( input2 > pow(2,input1 - 2) ){
			fout << "Case #" << j + 1 <<": IMPOSSIBLE" << endl ;
			continue;
		}
		bool bri[input1][input1];
		for (int  i = 0 ; i< input1 ; i ++ )
			for ( int   k = 0 ; k< input1 ; k ++ )
				bri[i][k] = 0;
	for ( int  i = 0 ; i< input1 ; i ++ )
			for (int   k = i + 1 ; k< input1 ; k ++ )
				bri[i][k] = 1;
	


		long long  temp = pow(2 , input1 - 3);
		if ( temp == 0 ) temp = 1;
		long long  i = 1;
		while ( input2 > 0 ){
			if ( input2 >= temp ){
				input2 -= temp;
				if ( temp / 2 > 0 ) temp /= 2;
				i ++;
				if (  input2 == 0){
						for ( int j = i ; j < input1 ; j ++ ){
							bri[0][j] = 0;

						}
					}
			}
			else {
				if ( temp / 2 > 0 ) temp /= 2;
				bri[0][i] = 0;
				for ( int k = i ; k < input1 ; k ++ )
							bri[i][k] = 0;
				i ++;
			}
		}
		

	
		fout << "Case #" << j + 1 <<": POSSIBLE" << endl ;
				for ( int i = 0 ; i< input1 ; i ++ ){
				
			for ( int k = 0 ; k< input1 ; k ++ )
				fout << bri[i][k];
				fout << endl;
			}
	}
	
	return 0;
}
