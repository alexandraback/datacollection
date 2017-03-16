/* BA 2013 */
#include <iostream>
#include <cmath>
#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <utility>
#include <limits>
#include <limits.h>
#include <iomanip>


using namespace std;
#define pb push_back
#define EPS 0.00001
#define For(x,y) for ( int (x) = 0; (x) < (y); (x)++ )
#define MAX 1


int main(){
	int numCases;
	cin >> numCases;

	for(int caseN=1; caseN <= numCases; caseN++){
		int N;
		cin >> N;
		vector<string> v = vector<string>(N,"");
		For(i,N){
			cin >> v[i];
			//cout << v[i] << endl;
		}
		/*******************/
		vector<vector<char> > vc = vector<vector<char> >(N, vector<char>());
		vector<vector<int> > vi = vector<vector<int> >(N, vector<int>());
		For(i,N){
			// Need N vector
			char c = '\n';
			int count = 0;
			For(j,v[i].size()){
				//cout << v[i][j] << endl;
				if(j==0){
					vc[i].push_back( v[i][j] );
					count = 1;
					c = v[i][j];

					if(j == v[i].size() -1){
						vi[i].push_back(count);
					}
					continue;
				}
				
				if(c!= v[i][j]){
					vc[i].push_back(v[i][j]);
					vi[i].push_back(count);
					c = v[i][j];
					count = 1;
					if(j == v[i].size()-1){
						vi[i].push_back(count);
					}
				} else {
					count++;
					if(j == v[i].size()-1){
						vi[i].push_back(count);
					}
				}

			}

			/// Display
			//cout << "vc[i] size " << vc[i].size() << endl;
			//cout << "vi[i] size " << vi[i].size() << endl;
/*
			For(j, (vc[i].size()) ){
				cout << vc[i][j] << "Count = " << vi[i][j] << endl;
			}
	*/		
		}
		/***********************/
		bool impossible = false;
		int numChanges = 0;
		For(j, vc[0].size()){
			// for each charactor
			char c = vc[0][j];
			For(i,N){
				if(vc[i][j] != c){
					impossible = true;
					break;
				}
			}
//cout << "HERE" << endl;
//cout << "j=" << j << endl;
			/*
			int max=0;
			For(i,N){
				//cout << "size v[i] " << vi[i].size() << endl;
				if(vi[i][j] > max){
					max = vi[i][j];
				}
			}
			// find the median
			int minSum = 1<<30;
			int lenOpt = 1;
			//cout << "MAX is " << max << endl;
			for(int median=1; median < max ; median++){
				int absErr = 0;
				For(i,N){
					absErr += abs(median - vi[i][j]);
				}
				//cout << "absErr " << absErr << endl;
				if(absErr < minSum){
					minSum = absErr;
					lenOpt = median;
				}
			}
			if(max == 1){
				minSum = 0;
			}
			*/
			vector<int> lens = vector<int>(N,0);
			For(i,N){
				lens[i] = vi[i][j];
			}
			sort(lens.begin(), lens.end());
			int mid = lens.size()/2;
			int median = lens[mid];
			int minSum = 0;
			For(i,N){
				minSum += abs(lens[i] - median);
			}


			//cout << "The median is " << median << endl;
			//cout << "minSum is" << minSum << endl;
			numChanges += minSum;
		}

		// check if the lengths are equal as well
		//int theLen = vc[0].size();
		For(i,N){
			if(vc[i].size() != vc[0].size()){
				impossible = true;
				break;
			}
		}

		cout << "Case #" << caseN << ": ";
		if(impossible){
			cout << "Fegla Won" << endl;
		} else{
			cout << numChanges << endl;
		}
	}

	return 0;
}
