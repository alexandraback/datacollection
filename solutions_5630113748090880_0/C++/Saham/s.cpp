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
int c[2555];
vector<int> v;
int main(){
	ifstream fin("B-small-attempt0.in");
	ofstream fout("b.txt");
	int T;
	fin>>T;
	for(int t=1;t<=T;t++){
		memset(c,0,sizeof(c));
		v.clear();
		int n;
		fin>>n;
		for(int i=0;i<2*n-1;i++){
			for(int j=0;j<n;j++){
				int a;
				fin>>a;
				c[a]++;
			}
		}
		for(int i=0;i<2555;i++)if(c[i]%2)v.pb(i);
		fout<<"Case #"<<t<<": ";
		for(int i=0;i<v.size();i++)fout<<v[i]<<" ";
		fout<<endl;
	}
}
