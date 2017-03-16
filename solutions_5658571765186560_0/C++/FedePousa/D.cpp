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

int main(){
	int T, X, R, C;
	cin >> T;
	string res;
	for(int caso=1; caso<=T; ++caso){
		cin >> X >> R >> C;
		if(C<R)swap(R,C);
		if(X==1){
			res = "GABRIEL";
		}
		if(X==2){
			if((R*C)%2==0){
				res = "GABRIEL";
			}else{
				res = "RICHARD";
			}
		}
		if(X==3){
			if((R==2&&C==3)||((R==3&&C==4))||((R==3&&C==3))){
				res = "GABRIEL";
			}else{
				res = "RICHARD";
			}
		}
		if(X==4){
			if((R==3&&C==4)||((R==4&&C==4))){
				res = "GABRIEL";
			}else{
				res = "RICHARD";
			}
		}
		cout << "Case #" << caso << ": " << res << endl;
	}
	return 0;
}
