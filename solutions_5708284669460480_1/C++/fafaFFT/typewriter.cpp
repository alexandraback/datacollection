#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <deque>
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

const int INF = 1000000000;
const LL INFINF = 1000000000000000000LL;

char tmp_str[1000];
string scanf_string() {
	scanf("%s",tmp_str);
	return tmp_str;
}

inline bool get_bit(int w, int i) {
	return (w>>i)&1;
}

LL wyznacz_skret(PI pkt1, PI pkt2, PI cel)
{
	// -X na lewo, 0 prosto, +X na prawo
	PI wektorA = MP(pkt2.first - pkt1.first, pkt2.second - pkt1.second);
	PI wektorB = MP(cel.first - pkt1.first, cel.second - pkt1.second);
	return (LL)wektorB.first * wektorA.second - (LL)wektorA.first * wektorB.second;
}


LL binarka(LL a, LL b, LL target, LL map(LL)) // [a,b]
{
	// [mniejsze od target][wieksze rowne target]
	// znajdz i pierwszego elementu [wieksze...]
	while (a < b)
	{
		LL c = (a + b) / 2;
		if (map(c) >= target) {
			b = c;
		}
		else {
			a = c + 1;
		}
	}
	return a;
}

LL wyznacz_skret2(PI &pkt1, PI &pkt2, PI &cel)
{
	// -X na lewo, 0 prosto, +X na prawo
	int WA1 = pkt2.first - pkt1.first; 
	int WA2 = pkt2.second - pkt1.second;

	int WB1 = cel.first - pkt1.first;
	int WB2 = cel.second - pkt1.second;
	return (LL)WB1 * WA2 - (LL)WA1 * WB2;
}

// ==========================================================

const int N = 1000;
int n;
int k, l, s;
string keyboard;
string dest;

long double prop[N];

int getMax() {
	if (s < l)
		return 0;

	for (int i = 0; i < dest.size(); i++)
	{
		if (prop[dest[i] - 'A'] == 0)
			return 0;
	}

	int ile = 1;
	string wynik = dest;
	for (int i = 1; i < s - l + 1; i++)
	{
		// czy da sie go tutaj dopasowac
		int wystaje = (i + dest.size()) - wynik.size();
		if (dest.substr(0, dest.size() - wystaje) == wynik.substr(i)) {
			ile++;
		wynik.append(dest.substr(dest.size() - wystaje));
	}
	}
	return ile;
}

long double getExpected() {
	if (s < l)
		return 0;

	long double prawJednego = s - l + 1;
	for (int i = 0; i < dest.size(); i++)
	{
		prawJednego *= prop[dest[i] - 'A'];
	}
	return prawJednego;
}

int main() {
	int d;scanf("%d",&d);
	for(int ind=1;ind<=d;ind++) {
		scanf("%d%d%d", &k, &l, &s);
		keyboard = scanf_string();
		dest = scanf_string();
		for (int i = 0; i < N; i++) prop[i] = 0;
		for (int i = 0; i < keyboard.size(); i++)
			prop[keyboard[i] - 'A'] += (long double)1.0 / keyboard.size();
		
		
		int maks = getMax();
		long double expected = getExpected();


		printf("Case #%d: ",ind);
		printf("%llf\n", max(maks - expected,(long double)0));
	}
	return 0;
}
