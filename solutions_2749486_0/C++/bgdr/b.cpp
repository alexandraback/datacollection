#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<string>
using namespace std;
int xf, yf;

struct State {
	int x, y, step;
	State *par;
};
string sol(State *s){
	string ans = "";
	while(s->par){
		State *par = s->par;
		if(par->x == s->x){
			if(par->y > s->y) ans += "S"; else ans += "N";
		} else {
			if(par->x > s->x) ans += "W"; else ans += "E";
		}
		s = par;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int dir_y[4] = {1, 0, -1, 0};
int dir_x[4] = {0, 1, 0, -1};

string solve1(){
	bool xfneg = xf < 0;
	bool yfneg = yf < 0;
	int xfa = xf < 0 ? -xf : xf;
	int yfa = yf < 0 ? -yf : yf;
	string s = "";
	for(int i = 0; i < xfa; ++i){
		if(xfneg) s += "EW"; else s += "WE";
	}
	for(int i = 0; i < yfa; ++i){
		if(yfneg) s += "NS"; else s += "SN";
	}
	return s;


}
int main(){
	int T;
	cin >> T;
	for(int c = 1; c <= T; c++){
		cin >> xf >> yf;
		cout << "Case #" << c << ": " << solve1() << endl;
	}
	cout.flush();
	return 0;
}
