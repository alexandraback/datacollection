#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;

typedef long long LL;
typedef pair<int,int> PI;
typedef vector<int> VI;
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define FT first
#define SD second
#define Y first
#define X second

vector<string>token(string a) {
    vector<string>w;a.push_back(' ');
    while(!a.empty()){w.push_back(a.substr(0,a.find(" ")));a=a.substr(a.find(" ")+1,a.size()-1);}return w;
}

map<string,int> mapik;
vector<string> amapik;
int dodaj(string a) {if(mapik.count(a)==0) {mapik[a]=mapik.size()-1;amapik.PB(a);}return mapik[a];}

#define INF 1000000000

char tmp_str[1000];
string scanf_string() {
	scanf("%s",tmp_str);
	return tmp_str;
}

const int N = 1000;
int n;
char plansza[10][10];
string res;

bool wygrana(char znak) {
	// pionowo
	for(int i=0;i<4;i++) {
		bool wygrana = true;
		for(int i2=0;i2<4;i2++) {
			if(!(plansza[i][i2] == 'T' || plansza[i][i2] == znak)) {
				wygrana = false;
			}
		}
		if(wygrana) return true;
	}
	// poziomo
	for(int i=0;i<4;i++) {
		bool wygrana = true;
		for(int i2=0;i2<4;i2++) {
			if(!(plansza[i2][i] == 'T' || plansza[i2][i] == znak)) {
				wygrana = false;
			}
		}
		if(wygrana) return true;
	}
	// skos
	if((plansza[0][0] == 'T' || plansza[0][0] == znak) & (plansza[1][1] == 'T' || plansza[1][1] == znak) & (plansza[2][2] == 'T' || plansza[2][2] == znak) & (plansza[3][3] == 'T' || plansza[3][3] == znak)) {
		return true;
	}
	
	if((plansza[3][0] == 'T' || plansza[3][0] == znak) & (plansza[2][1] == 'T' || plansza[2][1] == znak) & (plansza[1][2] == 'T' || plansza[1][2] == znak) & (plansza[0][3] == 'T' || plansza[0][3] == znak)) {
		return true;
	}    
	return false;
}

bool zajete() {
	for(int i=0;i<4;i++) for(int i2=0;i2<4;i2++) {
		if(plansza[i][i2] == '.') {
			return false;
		}
	}
	return true;
}

int main() {
	int d;scanf("%d",&d);
	for(int ind=1;ind<=d;ind++) {
		for(int i=0;i<4;i++) {
			scanf("%s",plansza[i]);
		}
		
		if(wygrana('X')) {
			res = "X won";
		}
		else if(wygrana('O')) {
			res = "O won";
		}
		else if(zajete()) {
			res = "Draw";
		}
		else {
			res = "Game has not completed";
		}
		printf("Case #%d: ",ind);
		printf("%s\n",res.c_str());
	}
	return 0;
}
