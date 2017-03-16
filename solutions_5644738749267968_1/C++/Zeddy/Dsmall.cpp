#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int compare(const void *a, const void *b){
	if( *(double*)a < *(double*)b) return -1;
	if( *(double*)a == *(double*)b) return 0;
	if( *(double*)a > *(double*)b) return 1;
}


int main(){
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w+", stdout);
	int t;
    cin >> t;

	int numBlocks;
	int dwar = 0;
	int war = 0;
	cout.precision(20);

	double naiomi[2000];
	double ken[2000];


	for(int ti = 0; ti < t; ti++){

		dwar = 0;
		war = 0;

		cout << "Case #" << (ti+1) << ": ";
		
				cin >> numBlocks;

		for(int i = 0; i < numBlocks; i++){
			cin >> naiomi[i];
		}
		for(int i = 0; i < numBlocks; i++){
			cin >> ken[i];
		}

		qsort(naiomi, numBlocks, sizeof(double), compare);
		qsort(ken, numBlocks, sizeof(double), compare);

		int naiomiCounter = numBlocks -1;
		int kenCounter = numBlocks -1;

		while(naiomiCounter >= 0){
			while(kenCounter >= 0){
				if(naiomi[naiomiCounter] > ken[kenCounter]){
					dwar++;
					kenCounter--;
					break;
				}
				kenCounter--;
			}
			naiomiCounter--;
		}
		
		naiomiCounter = 0;
		kenCounter = 0;
		
		while(naiomiCounter < numBlocks){
			while(kenCounter < numBlocks){
				if(naiomi[naiomiCounter] < ken[kenCounter]){
					war++;
					kenCounter++;
					break;
				}
				kenCounter++;
			}
			naiomiCounter++;
		}

		war = numBlocks - war;

		cout << dwar << ' ';
		cout << war;


		cout << endl;
	}

	fclose(stdout);
	fclose(stdin);
	return 0;
}