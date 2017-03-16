#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream reader("in");
ofstream writer("out");

int main(){

	int cases; reader >> cases;

	for(int m = 0; m < cases; ++m){

		int contestants; reader >> contestants;

		int* pts = new int[contestants + 1];
		int* tempts = new int[contestants + 1];
		int* order = new int[contestants + 1];
		
		double* reqpts = new double[contestants];

		int sum_of_pts = 0;

		cout << "Case #" << m + 1 << ": \n";

		for(int a = 0; a < contestants; ++a){
			reader >> pts[a];
			sum_of_pts += pts[a];
		}
		pts[contestants] = sum_of_pts;
		memcpy(tempts, pts, sizeof(int) * (contestants + 1));

		for(int a = 0; a < contestants; ++a){
			int minpts = sum_of_pts + 1;
			int index = -1;
			for(int b = 0; b < contestants; ++b){
				if (minpts > tempts[b]){
					minpts = tempts[b];
					index = b;
				}
			}
			if(index != -1){
				order[a] = index;
				tempts[index] = sum_of_pts + 1;
				cout << order[a] << " ";
			}
		}
		order[contestants] = contestants;

		writer << "Case " << m + 1 << ": ";
		
		double votepts = sum_of_pts;

		for(int a = 0; a < contestants; ++a){
			// in order to avoid elimination, each contestant must
			// score enough points so that if all other contestants
			// score as equally as possible, the lowest-ranking person's score
			// will equal the contestant's score.
			// Starting from the contestant with the least points, give audience points equally.
			
			if(votepts >= (pts[order[a+1]] - pts[order[a]]) * (a+1)){
				for(int b = 0; b <= a; ++b){
					reqpts[b] += (pts[order[a+1]] - pts[order[a]]);
				}
				votepts -= (pts[order[a+1]] - pts[order[a]]) * (a+1);
			}else{
				for(int b = 0; b <= a; ++b){
					reqpts[b] += votepts / (a+1);
				}
				votepts = 0;
			}
		}

		// and to reverse the mapping we need to do this again. >_>
		for(int a = 0; a < contestants; ++a){
			int index;
			for(int b = 0; b < contestants; ++b){
				if(order[b] == a) index = b;
			}
			cout << (reqpts[index] / sum_of_pts) * 100 << " ";
			writer << (reqpts[index] / sum_of_pts) * 100 << " ";
		}

		cout << endl;

		writer << endl;

		delete pts;
		delete tempts;
		delete order;
		delete reqpts;

	}
	
	
	system("pause");

	return 0;

}