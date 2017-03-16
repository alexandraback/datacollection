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
int c, d, v;
int liczby[N];

int dasie[N];
int tworca[N];

void uzupelnij(int nowa)
{
	for (int k = 1; k <= v; k++)
	{
		if (k - nowa >= 0 && dasie[k - nowa] && tworca[k - nowa] != nowa && dasie[k] == 0)
		{
			dasie[k] = 1;
			tworca[k] = nowa;
		}
	}
}

int main() {
	int da;scanf("%d",&da);
	for(int ind=1;ind<=da;ind++) {
		scanf("%d%d%d", &c, &d, &v);
		for (int i = 0; i < d; i++)
			scanf("%d", &liczby[i]);
		
		
		for (int i = 0; i < N; i++) {
			dasie[i] = 0;
			tworca[i] = 0;
		}
		dasie[0] = 1;

		for (int i = 0; i < d; i++)
		{
			uzupelnij(liczby[i]);
		}

		int res = 0;
		for (int i = 0; i <= v; i++) if (dasie[i] == 0)
		{
			res++;
			uzupelnij(i);
		}

		printf("Case #%d: ",ind);
		printf("%d\n", res);
	}
	return 0;
}
