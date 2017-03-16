//#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
ifstream cin("B-Large.in");
ofstream cout("B-Large.txt");

int main(){
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int N = 0;
		cin >> N;
		vector <int> va;
		vector <int> vb;
		va.assign(N,0);
		vb.assign(N,0);
		vector <int> vc;
		vc.assign(N,0);
		for(int j=0;j<N;j++){
			cin >> va[j];
			cin >> vb[j];
		}
		//at every step, check if there's a way to get two stars
		//if not, find the accessible item with the highest b and do it.
		bool finished = false;
		int ns = 0;
		int np = 0;
		while(!finished){
			if(ns == 2*va.size()){
				finished = true;
				break;
			}
			
			bool b = false;
			for(int j=0;j<va.size();j++){
				if((vb[j]<=ns) && (vc[j]<2)){
					ns+=2-vc[j];
					vc[j] = 2;
					np++;
					b = true;
					break;
				}
			}
			if(b) continue;//not correct loop must terminate
			int bestval=-1, bestj = -1;
			for(int j=0;j<va.size();j++){
				if((va[j]<=ns)&& (vb[j]>bestval)&&(vc[j]==0)){
					bestval = vb[j];
					bestj = j;
				}
			}
			if(bestval!=-1){
				vc[bestj]++;
				ns++;
				np++;
			}
			else break;

		}
		if(!finished)
			cout << "Case #" << i+1 << ": Too Bad" << endl;
		else
			cout << "Case #" << i+1 << ": " << np << endl;
	}
	system("pause");
	return 0;
}

