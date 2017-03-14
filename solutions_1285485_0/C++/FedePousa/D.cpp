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

int gcd(int a, int b){
	if(!b)return a;
	return gcd(b,a%b);
}
int main(){
	int T,H,W,D,x,y;
	cin >> T;
	string S;
	vector<string> hall;
	for(int caso=1;caso<=T;++caso){
		hall.clear();
		int veo=0;
		cin >> H >> W >> D;
		cin.ignore();
		for(int i=0;i<H;++i){
			getline(cin,S);
			hall.push_back(S);
		}
		set<pii> conj;
		for(int i=0;i<H;++i){
			for(int j=0;j<W;++j){
				if(hall[i][j]=='X'){
					x=2*(i-1)+1;
					y=2*(j-1)+1;
					break;
				}
			}
		}
		//~ cerr << x << " " << y << endl;
		
		D<<=1;
		H-=2;
		H<<=1;
		W-=2;
		W<<=1;
		//~ cerr << "D es: " << D << endl;
		//~ cerr << "H es: " << H << endl;
		//~ cerr << "W es: " << W << endl;
		int altAct=-x;
		int ancAct;
		bool alter,alter2;
		conj.clear();
		alter=true;
		while(x-altAct<=D){
			ancAct=2*W-y;
			alter2=true;
			while((x-altAct)*(x-altAct)+(ancAct-y)*(ancAct-y)<=D*D){
				conj.insert(pii((x-altAct)/gcd(x-altAct,ancAct-y),(ancAct-y)/gcd(x-altAct,ancAct-y)));
				if(alter2){
					ancAct+=y<<1;
				}else{
					ancAct+=(W-y)<<1;
				}
				alter2=!alter2;
			}
			if(alter){
				altAct-=(H-x)<<1;
			}else{
				altAct-=x<<1;
			}
			alter=!alter;
		}
		veo+=conj.size();
		//~ cerr << conj.size() << endl;
		
		
		
		conj.clear();
		alter=true;
		altAct=-x;
		while(x-altAct<=D){
			ancAct=-y;
			alter2=false;
			while((x-altAct)*(x-altAct)+(-ancAct+y)*(-ancAct+y)<=D*D){
				conj.insert(pii((x-altAct)/gcd(x-altAct,-ancAct+y),(-ancAct+y)/gcd(x-altAct,-ancAct+y)));
				if(alter2){
					ancAct-=y<<1;
				}else{
					ancAct-=(W-y)<<1;
				}
				alter2=!alter2;
			}
			if(alter){
				altAct-=(H-x)<<1;
			}else{
				altAct-=x<<1;
			}
			alter=!alter;
		}
		veo+=conj.size();
		//~ cerr << conj.size() << endl;
		
		conj.clear();
		alter=false;
		altAct=2*H-x;
		while(-x+altAct<=D){
			ancAct=-y;
			alter2=false;
			while((-x+altAct)*(-x+altAct)+(-ancAct+y)*(-ancAct+y)<=D*D){
				conj.insert(pii((-x+altAct)/gcd(-x+altAct,-ancAct+y),(-ancAct+y)/gcd(-x+altAct,-ancAct+y)));
				if(alter2){
					ancAct-=y<<1;
				}else{
					ancAct-=(W-y)<<1;
				}
				alter2=!alter2;
			}
			if(alter){
				altAct+=(H-x)<<1;
			}else{
				altAct+=x<<1;
			}
			alter=!alter;
		}
		veo+=conj.size();
		//~ cerr << conj.size() << endl;
		
		
		conj.clear();
		alter=false;
		altAct=2*H-x;
		while(-x+altAct<=D){
			ancAct=2*W-y;
			alter2=true;
			while((-x+altAct)*(-x+altAct)+(ancAct-y)*(ancAct-y)<=D*D){
				conj.insert(pii((-x+altAct)/gcd(-x+altAct,ancAct-y),(ancAct-y)/gcd(-x+altAct,ancAct-y)));
				if(alter2){
					ancAct+=y<<1;
				}else{
					ancAct+=(W-y)<<1;
				}
				alter2=!alter2;
			}
			if(alter){
				altAct+=(H-x)<<1;
			}else{
				altAct+=x<<1;
			}
			alter=!alter;
		}
		veo+=conj.size();
		//~ cerr << conj.size() << endl;
		
		
		if(x<<1<=D)veo++;
		if(y<<1<=D)veo++;
		if((H-x)<<1<=D)veo++;
		if((W-y)<<1<=D)veo++;
		
		cout << "Case #" << caso << ": " << veo << endl;
	}
	return 0;
}
