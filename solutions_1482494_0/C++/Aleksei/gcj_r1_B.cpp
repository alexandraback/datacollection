#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n;
int f[1010][2];
bool use[1010][2];

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		cin>>n;
		for(int i=0; i<n; i++) cin>>f[i][0]>>f[i][1];
		memset(use,false,sizeof(use));
		int total = 0;
		int rez = 0;
		bool ok = true;
		while(total<2*n){
			bool found = false;
			for(int i=0; i<n && !found; i++){
				if(!use[i][1] && total>=f[i][1]){
					use[i][1] = true;
					if(!use[i][0]){
						total+=2;
						use[i][0] = true;
					} else total++;
					rez++;
					found = true;
					break;
				}
			}
			if(found) continue;
			int v = -1;
			for(int i=0; i<n; i++){
				if(!use[i][0] && total>=f[i][0]){
					if(v==-1 || f[i][1]>f[v][1]) v = i;
				}
			}
			if(v==-1) break;
			use[v][0] = true;
			total++;
			rez++;
		}
		cout<<"Case #"<<testnum+1<<": ";
		if(total<2*n) cout<<"Too Bad"<<endl;
		else cout<<rez<<endl;
	}
	return 0;
}
