/* BA 2014 */
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

void print(vector<double> v){
	For(i,v.size()){
		cout << v[i] << " ";
	}
	cout << endl;
}

double highest(vector<double> v){
	return v[v.size()-1];
}

int main(){
	int numCases;
	cin >> numCases;

	for(int caseN=1; caseN <= numCases; caseN++){
		int numBlocks;
		cin >> numBlocks;
		vector<double> na = vector<double>(numBlocks,0.0);
		vector<double> ken = vector<double>(numBlocks,0.0);
		For(n,numBlocks){
			cin >> na[n];
		}
		For(n,numBlocks){
			cin >> ken[n];
		}
		int y,z;
		// Sort from low to high
		sort(na.begin(),na.end());
		sort(ken.begin(), ken.end());
		/*******************************/
		// A refers to Naomi
		// B refers to Ken
		int deceitScore = 0;
		int indexA = 0;
		int indexB = 0;
		while(indexA < numBlocks){
			if(na[indexA] > ken[indexB]){
				// A won
				deceitScore++;
				// A and B lost the lowest element
				indexA++;
				indexB++;
			} else {
				// B won but B lost the highest element
				// not necessary to literally delete it
				//ken.pop_back();
				// A lost the lowest element
				indexA++;
			}
		}

		int warScore = 0;
		indexA = 0;
		indexB = 0;
		while(indexA < numBlocks){
			if(na[indexA] < highest(ken)){
				// Ken will win -- delete the number just above na[indexA]
				// low is the position that is just higher than na[indexA]
				//cout << "Ken's vector before and after" << endl;
				//print(ken);
				vector<double>::iterator low = lower_bound(ken.begin(), ken.end(), na[indexA]);
				ken.erase(low);
				//print(ken);
				// A lost the lowest one
				indexA++;
			} else {
				// A lost the lowest one
				indexA++;
				// B lost the lowest one too
				indexB++;
				// A got 1 point
				warScore++;
			}
		}




		cout << "Case #" << caseN << ": " << deceitScore << " " << warScore << endl;
	}

	return 0;
}
