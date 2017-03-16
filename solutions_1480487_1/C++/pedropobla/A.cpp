#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

struct contestant {
	int pos, judge;
	double prob;
};

int T, N;
vector<contestant> cs;
int X;
int maxC, aux;
double thisProb;

bool sortByJudge (contestant c1, contestant c2) { return c1.judge < c2.judge; }
bool sortByProb (contestant c1, contestant c2) { return c1.pos < c2.pos; }

int main() {
	cin >> T;
	for(int t=1; t<=T; ++t) {
		cout << "Case #" << t << ": ";
		cs.clear();
		X = 0;
		cin >> N;
		double result[200];
		for(int i=0; i<N; ++i) {
			contestant c;
			c.pos = i;
			cin >> c.judge;
			cs.push_back(c);
			X += c.judge;
		}
		
		sort(cs.begin(), cs.end(), sortByJudge);
		

		for(int i = cs.size()-1; i >= 0; --i){
			aux = X;
			int j;
			for(j = 0; j < i && aux >= 0; ++j){
				aux -= cs[i].judge - cs[j].judge;
			}
			if(aux < 0) cs[i].prob = 0.0;
			else{
				thisProb = (double) (((double)aux/(double)(j+1)) + (double) cs[i].judge);
				for(j = 0; j <= i; ++j){
					cs[j].prob = ((thisProb - (double) cs[j].judge)/X)*100; 
				}
				break;
			}
		}
		sort(cs.begin(), cs.end(), sortByProb);
		
		for(int i = 0; i < N; ++i) printf(" %.6f",cs[i].prob);
		//cout << queda;

		/*
		int max;
		for(max=0; max<N; ++max) {
			queda = X;
			maxC = cs[max].judge;
			bool possible = true;
			
			for(int j=max+1; j<N && possible; ++j) {
				queda -= maxC - cs[j].judge;
				if(queda < 0) { result[cs[max].pos] = 0; possible = false; break; }
			}
			if(possible) break;
		}
		*/
		
		cout << endl;
	}
	return 0;
}