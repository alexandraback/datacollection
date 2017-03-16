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

char tmp_str[2000000];
string scanf_string() {
	scanf("%s",tmp_str);
	return tmp_str;
}

string vowels = "aeiou";
bool conso(char c) {
	return vowels.find(c) == -1;
}

const int N = 1100000;
int n;
LL przed[N];
LL po[N];
int consans[N];
int l;

int main() {
	int d;scanf("%d",&d);
	for(int ind=1;ind<=d;ind++) {
		string name = scanf_string();
		scanf("%d",&l);
		n = name.size();
		przed[0] = 0;
		/*
		for(int i=1;i<n;i++) {
			if(conso(name[i-1])) {
				przed[i] = przed[i-1] + 1;
			}
			else przed[i] = 0;
		}
		po[n-1] = 0;
		for(int i=n-2;i>=0;i--) {
			if(conso(name[i+1])) {
				po[i] = po[i+1] + 1;
			}
			else po[i] = 0;
		}
		
		int cn = 0;
		for(int i=0;i<n;i++) {
			if(conso(name[i])) {
				consans[cn++] = i;
			}
		}
		
		LL res = 0;
		for(int i=l-1;i<cn;i++) {
			res += (przed[consans[i-(l-1)]] + 1) * (1+po[consans[i]]);
		}*/
		LL res = 0;
		
		int i2 = 0;
		int suma = conso(name[0]);
		for(int i=0;i<n;i++) {
			while(suma < l && i2 < n-1) {
				if(conso(name[i2+1])) suma++;
				else suma = 0;
				i2++;
			}
			if(suma >= l) {
				res += n-i2;
			}
			else break;
			//printf("%I64d\n", res);
			//printf("+%d\n", suma);
			//suma -= conso(name[i]);
			suma = min(suma,i2-i+1 - 1);
			//printf("p %d\n", suma);
		}
		
		printf("Case #%d: ",ind);
		printf("%I64d\n", res);
	}
	return 0;
}
