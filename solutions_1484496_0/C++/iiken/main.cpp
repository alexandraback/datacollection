/*
 * 
 *  Created by Xiaojun Zhang.  All rights reserved.
 *
 */


#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const long maxn = 2000000;
int T,N;

int a[20];
int map[maxn][2];

int main(int argv, char** args){
	ifstream in;
	in.open("equal_small.in");
	ofstream out;
	out.open("equal_small.out");
	
	in >> T;
	int number;
	for (int i = 0; i < T; i++){
		memset ( map, 0, sizeof map);
		map[0][1] = -1;
		map[0][0] = 1;
		in >> N;
		bool out_flag = false;
		int sum = 0;
		out << "Case #" << i+1<<": ";
		for ( int j = 0; j < N; j++){
			in >> number;
			if (! out_flag)
			for ( int k = sum; k >=0; k--)
				if (  map[k][0] == 1  ) {
					int value = k + number;
					if ( map[value][0] == 1 ){
						out << endl;
						out << number << " ";
						while ( k != 0){
							out << k - map[k][1]<< " ";
							k = map[k][1];
						}
						out << endl;
						while ( value != 0){
							out << value - map[value][1] << " ";
							value = map[value][1];
						}
						out << endl;
						out_flag = true;
						break;
					}
					else{
						map[value][0] = 1;
						map[value][1] = k;
					}
			}
			//if ( out_flag ) break;
			sum += number;
		}
		if (! out_flag )
			out <<"Impossible" <<endl;
		
	}
}