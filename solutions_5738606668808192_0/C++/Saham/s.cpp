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
vector<ll> v;
int main(){
	//ifstream fin("D-large.in");
	ofstream fout("b.txt");
	int T,e=0,n,q;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n>>q;
		fout<<"Case #"<<t<<":"<<endl;
		for(int i=(1<<15)+1;i<(1<<16);i+=2){
			bool f1=1;
			v.clear();
			for(int j=2;j<11;j++){
				ll r=1,s=0;
				for(int k=0;k<16;k++){
					if(i & (1<<k))s+=r;
					r*=j;
				}
				bool f2=0;
				for(ll k=2;k*k<=s;k++){
					if(s%k==0){
						v.pb(k);
						f2=1;
						break;
					}
				}
				if(!f2){
					f1=0;
					break;
				}
			}
			if(!f1)continue;
			fout<<bitset<16>(i)<<" ";
			for(int j=0;j<v.size();j++)fout<<v[j]<<" ";
			fout<<endl;
			if(f1)e++;
			if(e==50)break;
		}
	}
}
