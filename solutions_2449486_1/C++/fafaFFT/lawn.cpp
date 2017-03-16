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

const int N = 200;
int n,m;
int lawn[N][N];
int minima[N];
int wynik[N];

int main() {
	int d;scanf("%d",&d);
	for(int ind=1;ind<=d;ind++) {
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) for(int i2=0;i2<m;i2++) scanf("%d",&lawn[i][i2]);
		
		bool res = true;
		for(int i=0;i<N;i++) {
			minima[i]=0; // prawdziwa wartoœæ >= 0
			wynik[i] = -1;
		}
		
		for(int i=0;i<n;i++) {
			int maks = *max_element(&lawn[i][0],&lawn[i][0]+m);
			for(int i2=0;i2<m;i2++) {
				if(wynik[i2] == -1) {
					if(maks == lawn[i][i2]) { // tylko ogranicz
						minima[i2] = max(minima[i2],maks);
					}
					else { // ustaw wysokoœæ jeœli mo¿liwa
						if(lawn[i][i2] < minima[i2]) {
							res = false;
							i = N;
							break;
						}
						else {
							minima[i2] = lawn[i][i2];
							wynik[i2] = lawn[i][i2];
						}
					}
				}
				else {
					if(lawn[i][i2] !=  min(wynik[i2],maks)) {
							res = false;
							i = N;
							break;
					}
				}
			}
		}
		
		
		printf("Case #%d: %s\n",ind,res ? "YES" : "NO");
	}
	return 0;
}
