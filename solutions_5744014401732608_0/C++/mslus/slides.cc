/*
 * slides.cc
 *
 *  Created on: May 8, 2016
 *      Author: maciek
 */

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <list>


using namespace std;


int main(int argc,char *argv[]){

	long long T, B, M;
	string s;
	ifstream fs(argv[1]);

	getline(fs, s);
	istringstream(s) >> T;
	for(int i = 0; i < T; i++){
		getline(fs,s);
		istringstream(s) >> B >> M;
		if( M > (1 << (B-2)) )
			cout << "Case #" << i+1 << ": IMPOSSIBLE" << endl;
		else{
			cout << "Case #" << i+1 << ": POSSIBLE" << endl;
			int s[51][51];
			int index = 1;
			for(int j = 0; j < B; j++)
				for(int k = 0; k < B; k++)
					s[j][k] = 0;

			while(M > 0){
				if((M % 2) == 1){
					for(int j = 0; j < index; j++ ){
						s[j][index] = 1;
					}
					s[index][B-1] = 1;
				}
				M = M >> 1;
				index++;
			}

			for(int j = 0; j < B;j++)
				s[B-1][j] = 0;

			int marked = 0;
			for(int j = 0; j < B-1; j++)
				for(int k = B-1; k > j; k--)
					if(marked == 1)
						s[j][k] = 1;
					else if(marked == 0 && s[j][k] == 1)
						marked = 1;


			for(int j = 0; j < B; j++){
				for(int k = 0; k < B; k++)
				  cout << s[j][k];
				cout << endl;
			}

		}
	}

}
