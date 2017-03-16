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
FILE * fout = fopen("C.out", "w");
FILE * fin = fopen("C.in", "r");

int main(){
	int T;
	fscanf(fin, "%d\n", &T);
	for(int a=0;a<T;a++){
		int A, B;
		fscanf(fin, "%d %d", &A, &B);
		int L = 1;
		int Q = A;
		while(Q > 0){
			Q /= 10;
			L *= 10;
		}
		L /= 10;
		cout << L << endl;
		int ans = 0;
		for(int i=A;i<=B;i++){
			int k = i;
			for(int j=0;j<10;j++){
				k = (k / 10) + (k % 10) * L;
				if(k <= B && k > i){
					ans++;
				} else if (k == i){
					break;
				}
			}
		}
		fprintf(fout, "Case #%d: %d\n", a+1, ans);
	}
}
