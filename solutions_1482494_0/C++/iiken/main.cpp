/*
 * 
 *  Created by Xiaojun Zhang.  All rights reserved.
 *
 */


#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;

int T;
int N;
const int MAX = 1001;
int a[MAX][2][2];
int main(int argv, char** args){
	ifstream in;
	in.open("kingdom_small.in");
	ofstream out;
	out.open("kingdom_small.out");
	in >> T;
	for (int i = 0; i < T; i++){
		
		in >> N;
		memset( a, 0, sizeof(int)*MAX*2*2);
		//out << N<<endl;
		for ( int j = 0; j < N ; j++){
			in >> a[j][0][0] >> a[j][1][0];
			//out << a[j][0][0] << " "<< a[j][1][0]<<endl ;
		}
		
		int score = 0;
		int times = 0;
		bool flag = true;
		while ( flag){
			int minimal2 = 2002;
			int target2 = -1;
			for ( int j = 0 ; j < N ; j++)
				if ( a[j][1][0] < minimal2 && a[j][1][1] == 0 ) {
					target2 = j;
					minimal2 = a[j][1][0];
				}
			if ( minimal2  == 2002 ) {
				break;
				
			}
			bool changed = true;
			while ( score < minimal2 && changed){
				changed = false;
				for ( int k = 0; k < N; k++)
					if ( a[k][0][0] <= score && a[k][0][1] == 0){
						a[k][0][1] = 1;
						times++;
						score++;
						changed = true;
						break;
					}
			}
			if ( score >= minimal2 ){
				
				times ++;
				a[target2][1][1] = 1;
				if (a[target2][0][1] == 1 ) score ++;
				if (a[target2][0][1] == 0 ) score += 2;
			}else flag = false;
			
		}
		if ( flag ) 
			out << "Case #" << i+1<<": "<< times <<endl;
		else out << "Case #" << i+1<<": Too Bad"<<endl ;
		//out << endl;
	}
}