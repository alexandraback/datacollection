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

bool match(const string& a, int val){
	int n = a.size();
	for(int i=0; i<n; i++){
		int last = val%10;
		bool ok = a[n-i-1]=='?' || ((a[n-i-1]-'0')==last);
		if(!ok) return false;
		val/=10;
	}
	return true;
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		string a, b;
		cin>>a>>b;
		assert(a.size()==b.size());
		int n = a.size();
		int mindiff = 1000000000;
		int reza = -1;
		int rezb = -1;
		if(n==1){
			for(int u=0; u<=9; u++){
				if(!match(a,u)) continue;
				for(int v=0; v<=9; v++){
					if(!match(b,v)) continue;
					if(abs(u-v)<mindiff){
						reza = u;
						rezb = v;
						mindiff = abs(u-v);
					}
				}
			}
		} else if(n==2){
			for(int u=0; u<=99; u++){
				if(!match(a,u)) continue;
				for(int v=0; v<=99; v++){
					if(!match(b,v)) continue;
					if(abs(u-v)<mindiff){
						reza = u;
						rezb = v;
						mindiff = abs(u-v);
					}
				}
			}
		} else if(n==3){
			for(int u=0; u<=999; u++){
				if(!match(a,u)) continue;
				for(int v=0; v<=999; v++){
					if(!match(b,v)) continue;
					if(abs(u-v)<mindiff){
						reza = u;
						rezb = v;
						mindiff = abs(u-v);
					}
				}
			}
		}
		cout<<"Case #"<<testnum+1<<": "<<setfill('0') << setw(n)<<reza<<' '<<setfill('0') << setw(n)<<rezb<<endl;
	}
	return 0;
}
