#define Federico using
#define Javier namespace
#define Pousa std;
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>


Federico Javier Pousa

typedef pair<int,int> pii;

int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


int main(){
	int T;
	cin >> T;
	for(int caso=1; caso<=T; ++caso){
		int J, P, S, K;
		cin >> J >> P >> S >> K;
		vector< vector<int> > pos;
		vector<int> act;
		for(int i=0; i<J; ++i){
			act.push_back(i);
			for(int j=0; j<P; ++j){
				act.push_back(j);
				for(int k=0; k<S; ++k){
					act.push_back(k);
					pos.push_back(act);
					act.pop_back();
				}
				act.pop_back();
			}
			act.pop_back();
		}
		int maxi = 1;
		for(int i=0; i<(1<<(int)pos.size()); ++i){
			if(__builtin_popcount(maxi)>__builtin_popcount(i))continue;
			bool sirve = true;
			map<pii, int> dicc1, dicc2, dicc3;
			for(int j=0; sirve&&j<(int)pos.size(); ++j){
				if(i&(1<<j)){
					dicc1[pii(pos[j][0],pos[j][1])]++;
					if(dicc1[pii(pos[j][0],pos[j][1])]>K)sirve = false;
					dicc2[pii(pos[j][0],pos[j][2])]++;
					if(dicc2[pii(pos[j][0],pos[j][2])]>K)sirve = false;
					dicc3[pii(pos[j][2],pos[j][1])]++;
					if(dicc3[pii(pos[j][2],pos[j][1])]>K)sirve = false;
				}
			}	
			if(sirve)maxi = i;
		}
		cout << "Case #" << caso << ": " << __builtin_popcount(maxi) << endl;
		for(int i=0; i<(int)pos.size(); ++i){
			if(maxi&(1<<i)){
				cout << pos[i][0]+1 << " " << pos[i][1]+1 << " " << pos[i][2]+1 << endl;
			}
		}
	}
	
	return 0;
}
