#include <cstdio>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

typedef pair<int, int> pr;

int map[1100][1100], via[1100][1100];

pr mapCoord(int x, int y) {

	pr ret;
	ret.first=x+500, ret.second=y+500;

	return ret;

}

char dirName[4]={'N','S','E','W'};
int dx[4]={ 0, 0, 1,-1};
int dy[4]={ 1,-1, 0, 0};

queue < pair< int, pr > > qe;

int main() {

	int casen;

	scanf("%d", &casen);

	for(int i=0;i<1100; ++i) for(int j=0; j<1100; ++j) map[i][j]=-1, via[i][j]=-1;

	qe.push(make_pair(0, make_pair(0,0)));
	int stx=mapCoord(0,0).first, sty=mapCoord(0,0).second;
	map[stx][sty]=0, via[stx][sty]=-1;
	while(!qe.empty()) {

		pair < int, pr > now = qe.front(), next=now; qe.pop();
		++next.first;

		for(int i=0; i<4; ++i) {

			next.second=now.second;
			next.second.first+=dx[i]*next.first, next.second.second+=dy[i]*next.first;

			//if(next.second.first>150 || next.second.first<-150 || next.second.second<-150 || next.second.second>150) continue;
			pr mapped=mapCoord(next.second.first, next.second.second);
			if(mapped.first<0 || mapped.first>=1100 || mapped.second<0 || mapped.second>=1100) continue;
			if(map[mapped.first][mapped.second]!=-1) continue;

			map[mapped.first][mapped.second]=next.first;
			via[mapped.first][mapped.second]=i;
			qe.push(next);

		}

	}

	for(int t=0; t<casen; ++t) {

		pr inp;
		scanf("%d %d", &inp.first, &inp.second);

		pr key=mapCoord(inp.first, inp.second), dest=mapCoord(0,0);
		string res="";

		if(inp.first==0 && inp.second==85) {
			int a;
			a=1;
		}

		while(key!=dest) {

			int mapVal=map[key.first][key.second];
			if(mapVal==-1) break;
			int viaVal=via[key.first][key.second];

			res=dirName[viaVal]+res;
			key.first-=dx[viaVal]*mapVal; key.second-=dy[viaVal]*mapVal;

		}
	cout << "Case #" << t+1 << ": " << res << endl;

	}


}