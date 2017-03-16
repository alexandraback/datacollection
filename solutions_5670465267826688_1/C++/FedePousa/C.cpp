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

int p[5][5] = {{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};


int prod(int a, int b){
	int res = p[abs(a)][abs(b)];
	if(a<0)res *= -1;
	if(b<0)res *= -1;
	return res;
}

int main(){	
	int T, L, desde[10005], hasta[10005];
	long long X;
	string S;
	vector<int> S2;
	cin >> T;
	for(int caso=1; caso<=T; ++caso){
		S2.clear();
		cin >> L >> X;
		cin >> S;
		for(int i=0; i<(int)S.size(); ++i){
			if(S[i]=='i')S2.push_back(2);
			if(S[i]=='j')S2.push_back(3);
			if(S[i]=='k')S2.push_back(4);
		}
		hasta[0] = 1;
		for(int i=1; i<=(int)S2.size(); ++i){
			//~ cerr << "Aver " << hasta[i-1] << " " << S2[i] << " " << prod(hasta[i-1],S2[i]) << endl;
			hasta[i] = prod(hasta[i-1],S2[i-1]);
			//~ cerr << i << " " << hasta[i] << endl;
		}
		desde[S2.size()] = 1;
		for(int i=S2.size()-1; i>=0; i--){
			desde[i] = prod(S2[i],desde[i+1]);
			//~ cerr << i << " " << desde[i] << endl;
		}
		 
		int todo = hasta[S2.size()]; 
		bool res = false;
		if(X>1){
			for(int i=0;!res&&i<(int)S2.size(); ++i){
				for(int j=0; !res&&j<=(int)S2.size(); ++j){
					int xi, vaxi=1;
					for(xi=0; xi<4; ++xi){
						if(prod(vaxi,hasta[i])==2)break;
						vaxi = prod(vaxi,todo);
					}
					if(xi==4)continue;
					int xj, vaxj=1;
					for(xj=0; xj<4; ++xj){
						if(prod(prod(desde[i],vaxj),hasta[j])==3)break;
						vaxj = prod(vaxj,todo);
					}
					if(xj==4)continue;
					int xk, vaxk=1;
					for(xk=0; xk<4; ++xk){
						if(prod(desde[j],vaxk)==4)break;
						vaxk = prod(todo,vaxk);
					}
					if(xk==4)continue;
					if(xi+xj+xk+2<=X&&(X-xi-xj-xk-2)%4==0)res = true;
				}
			}
		}
		if(!res){
			for(int i=0;!res&&i<(int)S2.size(); ++i){
				for(int j=i+1;!res&&j<=(int)S2.size(); ++j){
					int xi, vaxi=1;
					for(xi=0; xi<4; ++xi){
						if(prod(vaxi,hasta[i])==2)break;
						vaxi = prod(vaxi,todo);
					}
					if(xi==4)continue;
					int xk, vaxk=1;
					for(xk=0; xk<4; ++xk){
						if(prod(desde[j],vaxk)==4)break;
						vaxk = prod(todo,vaxk);
					}
					if(xk==4)continue;
					if(prod(hasta[i],3)!=hasta[j])continue;
					if(xi+xk+1<=X&&(X-xi-xk-1)%4==0)res = true;
				}
			}
		}
		cout << "Case #" << caso << ": " << (res?"YES":"NO") << endl;
	}
	return 0;
}
