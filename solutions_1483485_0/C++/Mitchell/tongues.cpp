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
char case1[1000] = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv y qee z";
char case2[1000] = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up a zoo q";
char translate[256];
bool used[256];
int main(){
	for(int i=0;i<strlen(case1);i++){
		translate[case1[i]] = case2[i];
		used[i] = true;
	}
	for(int i='a';i<='z';i++){
		if(!translate[i]){
			cout << "DARN\n";
			for(int j='a';j<='z';j++){
			if(!used[j]){
				translate[i] = j;
			}
			}
		}
		
	}
	int T;
	fscanf(fin, "%d\n", &T);
	for(int s=0;s<T;s++){
		char c[1000];
		fgets(c, sizeof c, fin);
		cout << c << endl;
		for(int i=0;i<strlen(c);i++){
			c[i] = translate[c[i]];
		}
		cout << c << endl;
		fprintf(fout, "Case #%d: %s\n", s + 1, c);
	}
}
