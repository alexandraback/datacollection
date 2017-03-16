#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

struct s{
	int pos;
	int sco;
	double prob;
};

int T;
vector<s> scores;

bool f1(s a, s b){ return a.sco < b.sco; }
bool f2(s a, s b){ return a.pos < b.pos; }

int main() {
	int N, total, aux, i, j;
	double top;
	cin >> T;
	for(int t=1; t<=T; ++t) {
		cout << "Case #" << t << ":";
		cin >> N;
		total = 0;
		for(i = 0; i < N; ++i) {
			s aux;
			aux.pos = i;
			cin >> aux.sco; 
			total += aux.sco;
			scores.push_back(aux);
		}
		sort(scores.begin(), scores.end(), f1);
	
		for(i = scores.size()-1; i >= 0; --i){
			aux = total;
			for(j = 0; j < i && aux >= 0; ++j){
				aux -= scores[i].sco - scores[j].sco;
			}
			if(aux < 0) scores[i].prob = 0.0;
			else{
				top = (double) (((double)aux/(double)(j+1)) + (double) scores[i].sco);
				for(j = 0; j <= i; ++j){
					scores[j].prob = ((top - (double) scores[j].sco)/total)*100; 
				}
				break;
			}
		}
		sort(scores.begin(), scores.end(), f2);
		for(i = 0; i < N; ++i) printf(" %.6f",scores[i].prob);
		cout << endl;
		scores.clear();
	}
	return 0;
}
