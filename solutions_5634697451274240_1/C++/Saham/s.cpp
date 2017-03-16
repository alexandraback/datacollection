#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <set>
#include <map>
#include <sstream>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
ll G(ll a,ll b){if(b==0)return a;return G(b,a%b);}
int main(){
	ifstream fin("B-large.in");
	ofstream fout("b.txt");
	int T;
	fin>>T;
	for(int t=1;t<=T;t++){
		string s;
		fin>>s;
		int n=0;
		for(int i=0;i<s.length()-1;i++){
			if(s[i]!=s[i+1])n++;
		}
		if(s[s.length()-1]=='-')n++;
		fout<<"Case #"<<t<<": "<<n<<endl;
	}
}
