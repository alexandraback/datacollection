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
#include <bitset>
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
	ifstream fin("A-large.in");
	ofstream fout("b.txt");
	int T;
	fin>>T;
	for(int t=1;t<=T;t++){
		string s,ans="";
		fin>>s;
		int n=s.length();
		for(int i=0;i<n;i++){
			if(s[i]+ans>ans+s[i])ans=s[i]+ans;
			else ans=ans+s[i];
		}
		fout<<"Case #"<<t<<": "<<ans<<endl;
	}
}
