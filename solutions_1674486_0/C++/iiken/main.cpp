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
const int maxn = 1000;
bool a[maxn][2][maxn] , kp[maxn], jc[maxn];
int T,N;
int main(int argv, char** args){
	ifstream in;
	in.open("diamond_small.in");
	ofstream out;
	out.open("diamond_small.out");
	
	in >> T;
	for (int i = 0; i < T; i++){
		
		memset ( a, false, sizeof a);
		in >> N;
		int m = 0, p =0;
		bool flag = false;
		
		for ( int j = 0 ; j < N; j++){
			in >> m;
				for ( int k = 0; k < m; k++){
					in >> p;
					p--;
					// k+ k.parents -> j.parents
					// k+ k.parents -> j.child.parents
					// j.child +j -> k.child
					if ( !flag ){ 
						memset( kp, false, sizeof kp);
						kp[p] = true;
						for ( int kpi = 0; kpi < N; kpi++){
							if (a[p][0][kpi]) 
								kp[kpi] = true;
						}
						
						
						memset ( jc, false, sizeof jc);
						jc[j] = true;
						for ( int jci = 0; jci < N; jci++){
							if (a[j][1][jci]) 
								jc[jci] = true;
						}
						for ( int kpi  = 0 ; kpi < N; kpi++)
							if (kp[kpi]){
								for ( int jci = 0 ; jci < N; jci++)
									if (jc[jci]){
										if ( a[jci][0][kpi]){
											flag  = true;
											break;
										}else{
											a[jci][0][kpi] = true;
											a[kpi][1][jci] = true;
										}
									}
								if ( flag ) break;
							}
					}
				}
		}	
		out << "Case #" << i+1<<": ";
		if ( flag ) out << "Yes" <<endl;
			else out << "No" <<endl;
		
	}
}