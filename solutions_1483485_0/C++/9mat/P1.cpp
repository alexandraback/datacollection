#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#include <sstream>

#define F(i,n) for(int i=0, n_=(n); i<n_; i++)
#define FS(i,s,n) for(int i=(s), n_=(n); i<n_; i++)
#define FR(i,n) for(int i=(n)-1; i>=0; i--)

#define AA first
#define BB second
#define XX first.first
#define YY first.secomd
#define ZZ second

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VF;
typedef pair<int, int> PRI;
typedef pair<PRI, int> TRI;

template<typename T> inline void updatemin(T &a, T b) { if(a>b) a=b; }
template<typename T> inline void updatemax(T &a, T b) { if(a<b) a=b; }
template<typename T> inline T gcd(T a, T b) { 
	T d; 
	while(b!=0) d=a, a=b, b=d%b; 
	return a;
}


int main(){
	string a = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpos"
		"sibilitiessoitisokayifyouwanttojustgiveupaozq";
	string b = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymved"
		"dknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvyeqz";

	char map[30];
	F(i,a.size()) map[b[i]-'a'] = a[i];

	char line[300];
	cin.getline(line,200);

	int T;
	//cout<<map<<endl;
	stringstream ss(line, stringstream::in);
	ss>>T;
	F(test,T){
		char line[300];
		cin.getline(line,200);
		F(i,strlen(line)) 
			if(line[i]>='a' && line[i]<='z')
				line[i] = map[line[i]-'a'];
			else if(line[i]>='A' && line[i]<='Z')
				line[i] = map[line[i]-'A'] + 'A'-'a';
		cout<<"Case #"<<test+1<<": "<<line<<endl;
	}
}
