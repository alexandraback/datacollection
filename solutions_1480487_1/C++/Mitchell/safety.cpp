#include <bitset>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <deque>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
FILE * fout = fopen("A.out", "w");
FILE * fin = fopen("A.in", "r");
double s[1000];
int main(){
	int T;
	fscanf(fin, "%d", &T);
	for(int casenum=0;casenum<T;casenum++){
		int N;
		double ssum=0;
		fscanf(fin, "%d", &N);
		for(int i=0;i<N;i++){
			fscanf(fin, "%lf", &s[i]);
			ssum += s[i];
		}
		fprintf(fout, "Case #%d:", casenum + 1);
		for(int i=0;i<N;i++){
			double a = 0;
			double b = 1;
			while(b - a > 0.000000001){
				double mid = (a + b)/2;
				double score = s[i]/ssum + mid;
				double total = 0;
				for(int j=0;j<N;j++){
					total += max(0.0, score - s[j]/ssum);
				}
				if(total > 1.0){
					b = mid;
				} else {
					a = mid;
				}
			}
			fprintf(fout, " %2.6f", 100*a);
		}
		fprintf(fout,"\n");
		
	}
}
