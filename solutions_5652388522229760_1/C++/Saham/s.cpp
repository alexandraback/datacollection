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
bool mark[11];
int main(){
	ifstream fin("A-large.in");
	ofstream fout("b.txt");
	int T;
	fin>>T;
	for(int t=1;t<=T;t++){
		memset(mark,0,sizeof(mark));
		int n,tmp=0,c=0,r;
		fin>>n;
		if(n==0){
			fout<<"Case #"<<t<<": INSOMNIA\n";
			continue;
		}
		while(c<10){
			tmp+=n;
			r=tmp;
			while(r){
				if(!mark[r%10])c++;
				mark[r%10]=1;
				r/=10;
			}
		}
		fout<<"Case #"<<t<<": "<<tmp<<endl;
	}
}
