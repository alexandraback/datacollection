#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string x="yezqejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
string y="aoqzourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";

int main() {
	//freopen("tongues.in","r",stdin);
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int tests;
	cin >> tests;
	string line;
	getline(cin,line);
	for (int test=1;test<=tests;test++) {
		getline(cin,line);
		for (int i=0;i<line.size();i++) if (line[i]!=' ') {
			int p=x.find(line[i]);
			line[i]=y[p];
		}
		cout << "Case #" << test << ": " << line << endl;
	}
    return 0;
}
