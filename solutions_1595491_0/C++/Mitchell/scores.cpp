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
FILE * fout = fopen("B.out", "w");
FILE * fin = fopen("B.in", "r");
int scores[100];
int main(){
	int T;
	fscanf(fin, "%d\n", &T);
	for(int a=0;a<T;a++){
		int N, S, p;
		fscanf(fin, "%d %d %d", &N, &S, &p);
		int x=0;
		int y=0;
		int z=0;
		for(int i=0;i<N;i++){
			fscanf(fin, "%d", &scores[i]);
			if(scores[i] >= 2){
				if(scores[i] >= 3*p - 2){
					x ++;
				} else if(scores[i] >= 3*p - 4){
					y ++;
				} else {
					z ++;
				}
			} else if(scores[i] >= p){
				x++;
			} else {
				z++;
			}
		}
		
		fprintf(fout, "Case #%d: %d\n", a+1, x + min(y, S));
	}
}
