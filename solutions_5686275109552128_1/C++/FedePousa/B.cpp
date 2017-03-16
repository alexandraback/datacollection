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

int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

int T, D, P[1005];

bool puedo(int sec, int splits){
	int maxi = sec-splits;
	int llevo = 0;
	for(int i=0; i<D; ++i){
		if(P[i]<=maxi)continue;
		//~ int inf, med, sup;
		//~ inf = 1;
		//~ sup = P[i];
		//~ while(inf+1!=sup){
			//~ med = (inf+sup)>>1;
			//~ if((P[i]-1)/med<=maxi-1){
				//~ sup = med;
			//~ }else{
				//~ inf = med;
			//~ }
		//~ }
		//~ llevo += sup-1;
		if((P[i]%maxi)==0)llevo += (P[i]/maxi)-1;
		if((P[i]%maxi)!=0)llevo += (P[i]/maxi);
	}
	return llevo<=splits;
}

int main(){
	
	//~ for(int i=1; i<=10; ++i){
		//~ int mini = i;
		//~ for(int j=1; j<=i; ++j){
			//~ mini = min(mini, (j-1)+1+(i-1)/j);
		//~ }
		//~ cout << i << " " << mini << endl;
	//~ }
	
	
	
	cin >> T;
	for(int caso=1; caso<=T; ++caso){
		cin >> D;
		memset(P, 0, sizeof P);
		for(int i=0; i<D; ++i){
			cin >> P[i];
		}
		int inf, med, sup;
		inf = 0;
		sup = 1000;
		while(inf+1!=sup){
			med = (inf+sup)>>1;
			bool can = false;
			for(int i=0; !can&&i<med; ++i){
				can = puedo(med,i);
			}
			if(can){
				sup = med;
			}else{
				inf = med;
			}
		}
		cout << "Case #" << caso << ": " << sup << endl;
	}
	return 0;
}
