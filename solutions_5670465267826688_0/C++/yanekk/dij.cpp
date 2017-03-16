#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int Mnoz(int a,int b){
	if(b < 0) return -1*Mnoz(a,-b);
	if(a < 0) return -1*Mnoz(-a,b);
	if(a == 1) return b;
	if(b == 1) return a;
	if(a==2 && b == 2) return -1;
	if(a==2 && b == 3) return 4;
	if(a==2 && b == 4) return -3;
	if(a==3 && b == 2) return -4;
	if(a==3 && b == 3) return -1;
	if(a==3 && b == 4) return 2;
	if(a==4 && b == 2) return 3;
	if(a==4 && b == 3) return -2;
	if(a==4 && b == 4) return -1;
}

int main(){
	string s,w;
	int t,l;
	int i,j,all,il;
	long long x,p_indeks,o_indeks,wsk;
	cin >> t;
	for(i=0; i<t; i++){
		cin >> l >> x;
		cin >> s;
		wsk = l*x-1;
		p_indeks = wsk;
		o_indeks = 0;
		il = 1;
		for(j=0; j<l; j++){
			if(s[j] == 'i') il = Mnoz(il,2);
			if(s[j] == 'j') il = Mnoz(il,3);
			if(s[j] == 'k') il = Mnoz(il,4);
		}
		all = 1;
		for(j=0; j<x%4; j++) all = Mnoz(all,il);
		w = s;
		s = "";
		for(j=0; j<min((long long)4,x); j++) s += w;
		il = 1;
		for(j=0; j<s.size(); j++){
			if(s[j] == 'i') il = Mnoz(il,2);
			if(s[j] == 'j') il = Mnoz(il,3);
			if(s[j] == 'k') il = Mnoz(il,4);
			if(il == 2) p_indeks = min(p_indeks,(long long)j);
		}
		il = 1;
		//cout << p_indeks << "\n";
		for(j=s.size()-1; j>=0; j--){
			if(s[j] == 'i') il = Mnoz(2,il);
			if(s[j] == 'j') il = Mnoz(3,il);
			if(s[j] == 'k') il = Mnoz(4,il);
			if(il == 4) o_indeks = max(o_indeks,wsk);
			wsk--;
		}
		if(all == -1 && p_indeks < o_indeks) cout << "Case #" << i+1 << ": YES\n";
		else cout << "Case #" << i+1 << ": NO\n";
		//cout << all << "\n";
	}
	return 0;
}
