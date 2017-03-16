//a Hewr
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define fo(i,a,b) for (int i = a; i <= b; ++i)
#define SIZE(x) ((int) (x).size())

const char CODE[]={"ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv"};
const char DECO[]={"ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup"};

int a[26];

int main(){
	fo (i, 0, strlen(CODE) - 1) a[CODE[i] - 'a'] = DECO[i] - 'a';
	a['q' - 'a'] = 25, a[25] = 'q' - 'a';
	int Ca;
	string S;
	cin >> Ca;
	getline(cin, S);
	fo (CA, 1, Ca){
		getline(cin, S);
		fo (i, 0, SIZE(S) - 1) if (S[i] != ' ') 
			S[i] = char(a[S[i] - 'a'] + 'a');
		cout << "Case #" << CA << ": " << S << endl;
	}
}
