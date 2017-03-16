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

#define INF 1000000000

char tmp_str[1000];
string scanf_string() {
	scanf("%s",tmp_str);
	return tmp_str;
}

const int N = 100;
int n,m;

int sas[N][N];
string zip[N];

VI perm;

void czysc()
{
	for(int i=0;i<N;i++)
	for(int i2=0;i2<N;i2++)
	sas[i][i2]=0;
	perm.clear();
}

int main() {
	int d;scanf("%d",&d);
	for(int ind=1;ind<=d;ind++) {
		scanf("%d%d",&n,&m);
		czysc();
		for(int i=0;i<n;i++) {zip[i] = scanf_string();perm.PB(i);}
		for(int i=0;i<m;i++) {
			int a,b;
			scanf("%d%d",&a,&b);a--;b--;
			sas[a][b]=sas[b][a]=1;
		}
		
		string best = "z";
		do {
			string cur = zip[perm[0]]; 
			deque<int> list;
			list.push_back(perm[0]);
			for(int i=1;i<n;i++) {
				while(list.size()>0 && sas[list.back()][perm[i]] == 0) {
					list.pop_back();
				}
				if(list.size() > 0 && sas[list.back()][perm[i]]) {
					cur +=zip[perm[i]];
					list.push_back(perm[i]);
				}
				else 
				{
				
					cur = "";
					break;
				}
			}
			if(cur.size()!=0)
				best = min(best,cur);
		
		} while(next_permutation(ALL(perm)));
		
		printf("Case #%d: ",ind);
		printf("%s\n",best.c_str());
	}
	return 0;
}
