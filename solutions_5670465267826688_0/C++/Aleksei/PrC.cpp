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

const int ONE = 1;
const int I = 2;
const int J = 3;
const int K = 4;

int table[5][5] = {
	{0,0,0,0,0},
	{0,ONE,I,J,K},
	{0,I,-ONE,K,-J},
	{0,J,-K,-ONE,I},
	{0,K,J,-I,-ONE},
};

inline int sign(int a){
	if(a<0) return -1;
	else if(a>0) return 1;
	else return 0;
}

inline int mult(int a, int b){
	return table[abs(a)][abs(b)]*sign(a)*sign(b);
}

inline int code(char ch){
	switch(ch){
		case 'i': return I;
		case 'j': return J;
		case 'k': return K;
	}
	return 0;
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int L, x;
		cin>>L>>x;
		string st;
		cin>>st;
		if(L*x<3){
			cout<<"Case #"<<testnum+1<<": "<<"NO"<<endl;
			continue;
		}
		int a[10010];
		bool ai[10010];
		bool ak[10010];
		memset(ai,false,sizeof(ai));
		memset(ak,false,sizeof(ak));
		int n = 0;
		for(int i=0; i<x; i++){
			for(int j=0; j<L; j++){
				a[n++] = code(st[j]);
			}
		}
		int cum = ONE;
		int lastI = -1;
		for(int i=0; i<n; i++){
			cum = mult(cum, a[i]);
			ai[i] = (cum==I);
			if(ai[i]){
				lastI = max(lastI, i);
			}
		}
		if(lastI==-1){
			cout<<"Case #"<<testnum+1<<": "<<"NO"<<endl;
			continue;
		}
		cum = ONE;
		int lastK = -1;
		for(int i=n-1; i>=0; i--){
			cum = mult(a[i], cum);
			ak[i] = (cum==K);
			if(ak[i] && lastK==-1){
				lastK = i;
			}
		}
		if(lastK==-1){
			cout<<"Case #"<<testnum+1<<": "<<"NO"<<endl;
			continue;
		}
		bool found = false;
		for(int i=0; i<=lastI && !found; i++){
			if(!ai[i]) continue;
			int cum = ONE;
			for(int j=i+1; j<lastK && !found; j++){
				cum = mult(cum, a[j]);
				found = (cum==J && ak[j+1]);
			}
		}
		if(found){
			cout<<"Case #"<<testnum+1<<": "<<"YES"<<endl;
		}else{
			cout<<"Case #"<<testnum+1<<": "<<"NO"<<endl;
		}
	}
	return 0;
}
