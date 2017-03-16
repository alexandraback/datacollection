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

const int maxn = 100;
int T,N,M;
long long  a[3][2];
long long b[maxn][2];

long long res( int index, int start){
	if ( index == N-1){
		long long total = 0;
		for ( int i = start; i < M; i++)
			if ( b[i][1] == a[index][1] ) total += b[i][0];
		return total > a[index][0] ? a[index][0] : total; 
	}else{
		long long maxRes = 0;
		long long total = 0;
		long long result = 0;
		maxRes = res(index+1, start);
		for (int i = start; i < M ; i++){
			if ( b[i][1] == a[index][1] ){
				total += b[i][0];
				if ( total > a[index][0] ){
					long long value = a[index][0];
					long long tmp  = b[i][0] ;
					b[i][0] = total - b[i][0];
					result = value + res(index+1,i);
					b[i][0]  = tmp;
				}else {
					long long value = total;
					result = value + res(index+1,i+1);
				}
				if ( result > maxRes ) maxRes = result;
			}
		}
		return maxRes;
	}
	
	return 0;
}
int main(int argv, char** args){
	ifstream in;
	in.open("box_small.in");
	ofstream out;
	out.open("box_small.out");
	
	in >> T;
	for (int t = 0; t < T; t++){
		
		in >> N >> M;
		memset ( a, 0, sizeof a);
		memset ( b, 0, sizeof b);
		int i;
		for ( i = 0; i < N; i++){
			in >> a[i][0] >> a[i][1];
			if ( i > 0 && a[i][1] == a[i-1][1]) {
				a[i-1][0] = a[i-1][0] + a[i][0];
				i--;
				N--;
			}
		}
		int j;
		for ( j = 0 ; j < M; j++){
			in >> b[j][0] >> b[j][1];
			if ( j > 0 && b[j][1] == b[j-1][1]){
				b[j-1][0] += b[j][0];
				j--;
				M--;
			}
		}
		long long num = res (0,0);
		out << "Case #" << t+1<<": " << num<<endl;
	}
}