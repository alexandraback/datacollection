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

const int N = 50;
int n;

int k;
VI posiadanie(N);
int wymagany[N];
VI klucze[N];

void wprowadz(VI &posiadane, int numer, int mnoznik = 1) {
	for(int i=0;i<klucze[numer].size();i++) {int klucz = klucze[numer][i];
		posiadane[klucz]+= mnoznik;
	}
}

bool gorszy(VI &a, VI&b) {
	// Jeœli zestaw a jest gorszy ni¿ b.
	for(int i=0;i<a.size();i++) {
		if(a[i] > b[i]) return false; 
	}
	
	return true;
}

bool lepszy(VI &a, VI&b) {
	for(int i=0;i<b.size();i++) {
		if(a[i] < b[i]) return false; 
	}
	
	return true;
}

bool sukces = false;
VI porazka[1<<21]; // z jakim zestawem przegrali.
int glebia;
VI probuj(int maska, VI &posiadane) {
	if(maska == (1<<n)-1) {
		sukces = true;
		return VI();
	}
	
	// Ucinaj jeœli posiadane jest gorsze ni¿ porazka
	if(gorszy(posiadane,porazka[maska]))
		return VI();
	
	//printf("%d-%d\n", maska, glebia);
	for(int i=0;i<n;i++) {
		// próbuj po kolei
		if((maska & (1<<i)) == false && posiadane[wymagany[i]] > 0) {
			posiadane[wymagany[i]]--;
			wprowadz(posiadane,i,1);
			int nowaMaska = maska | (1<<i);
			glebia++;
			VI wynik = probuj(nowaMaska,posiadane);
			glebia--;
			if(sukces) {
				wynik.PB(i);
				return wynik;
			}
			else {
				wprowadz(posiadane,i,-1);
				posiadane[wymagany[i]]++;
			}
		}
	}
	
	// Uaktualnij jeœli lepszy ni¿ poprzedni
	if(lepszy(posiadane,porazka[maska])) {
		porazka[maska] = posiadane;
	}
	
	return VI();
}

int main() {
	int d;scanf("%d",&d);
	for(int ind=1;ind<=d;ind++) {
		scanf("%d%d",&k,&n);
		fill(ALL(posiadanie),0);
		sukces = false;
		for(int i=0;i<(1<<n);i++) porazka[i] = VI(N,0);
		
		for(int i=0;i<k;i++) {
			int tmp;scanf("%d",&tmp);tmp--;
			posiadanie[tmp]++;
		}
		for(int i=0;i<n;i++) {
			scanf("%d",&wymagany[i]); wymagany[i]--;
			int tmp;scanf("%d",&tmp);
			for(int i2=0;i2<tmp;i2++) {
				int kl;scanf("%d",&kl);kl--;klucze[i].PB(kl);
			}
		}
		
		VI wynik = probuj(0,posiadanie);
		reverse(ALL(wynik));
		
		printf("Case #%d: ",ind);
		if(wynik.size()==0) {
			printf("IMPOSSIBLE\n");
		}
		else {
			for(int i=0;i<n;i++) {
				printf("%d ",wynik[i]+1);
			}printf("\n");
		}
		fflush(stdout);
		for(int i=0;i<n;i++) klucze[i].clear(); 
	}
	return 0;
}
