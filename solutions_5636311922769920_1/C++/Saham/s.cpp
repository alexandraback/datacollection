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
	ifstream fin("D-large.in");
	ofstream fout("b.txt");
	int T;
	fin>>T;
	for(int t=1;t<=T;t++){
		ll k,c,s,r=0,e=1;
		fin>>k>>c>>s;
		if(s*c<k){
			fout<<"Case #"<<t<<": "<<"IMPOSSIBLE"<<endl;
			continue;
		}
		for(int i=1;i<c;i++){
			e*=k;
			r+=e;
		}
		fout<<"Case #"<<t<<": ";
		ll tmp=0;
		for(int i=1;i<=k;i++){
			tmp=tmp*k+i;
			if(i==k){
				while(i%c){
					i++;
					tmp=tmp*k+1;
				}
			}
			if(i%c==0){
				fout<<tmp-r<<" ";
				tmp=0;
			}
		}
		fout<<endl;
	}
}
