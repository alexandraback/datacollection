#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

inline bool bitsett(int a, int bit){
	return (a&(1<<bit))!=0;
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int n;
		cin>>n;
		vector< pair<string, string> > topics(n);
		for(int i=0; i<n; i++) cin>>topics[i].first>>topics[i].second;
		int end = (1<<n);
		int rez = 0;
		for(int mask = 0; mask<end; mask++){
			set<string> firstOrig;
			set<string> secondOrig;
			for(int i=0; i<n; i++){
				if(!bitsett(mask,i)){
					firstOrig.insert(topics[i].first);
					secondOrig.insert(topics[i].second);
				}
			}
			int total = 0;
			bool possible = true;
			for(int i=0; i<n; i++){
				if(bitsett(mask, i)){
					total++;
					if(firstOrig.find(topics[i].first)==firstOrig.end() || secondOrig.find(topics[i].second)==secondOrig.end()){
						possible = false;
						break;
					}
				}
			}
			if(possible){
				rez = max(rez, total);
			}
		}
		cout<<"Case #"<<testnum+1<<": "<<rez<<endl;
	}
	return 0;
}
