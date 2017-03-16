#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
#include <functional>
using namespace std;

#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define ll long long
#define ld long double
#define mod 1000000007
#define inf 1061109567LL
#define pii pair< int, int >
#define pll pair< ll, ll >
#define psi pair< string, int >
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int T = 1;
	while(t--){
		string s[2];
		cin>>s[0]>>s[1];
		vector <int> a[2],b[2];
		int x = 0;
		for(int i=0;i<s[0].size();i++){
			a[x].clear();
			if(s[0][i]=='?'){
				if(i==0){
					for(int j=0;j<10;j++){
						a[x].PB(j);
					}
				}
				else{
					for(int k=0;k<a[x^1].size();k++){
						for(int j=0;j<10;j++){

							a[x].PB(a[x^1][k]*10+j);
						}
					}
				}
			}
			else{
				if(i==0){
					a[x].PB(s[0][i]-'0');
				}
				else{
					for(int k=0;k<a[x^1].size();k++){
						a[x].PB(a[x^1][k]*10+s[0][i]-'0');
					}
				}
			}
			x^=1;
		}
		int y=0;
		for(int i=0;i<s[1].size();i++){
			b[y].clear();
			if(s[1][i]=='?'){
				if(i==0){
					for(int j=0;j<10;j++){
						b[y].PB(j);
					}
				}
				else{
					for(int k=0;k<b[y^1].size();k++){
						for(int j=0;j<10;j++){
							b[y].PB(b[y^1][k]*10+j);
						}
					}
				}
			}
			else{
				if(i==0){
					b[y].PB(s[1][i]-'0');
				}
				else{
					for(int k=0;k<b[y^1].size();k++){
						b[y].PB(b[y^1][k]*10+s[1][i]-'0');
					}
				}
			}
			y^=1;
		}
		x^=1;
		y^=1;

		int l,r;
		int mn=inf;
		for(int i=0;i<a[x].size();i++){
			for(int j=0;j<b[y].size();j++){
				//if(a[x][i]<100)cout<<a[x][i]<<" "<<b[y][j]<<endl;
				if(mn>abs(a[x][i]-b[y][j])){
					mn = abs(a[x][i]-b[y][j]);
					l=a[x][i];
					r=b[y][j];
				}
				else if(mn==abs(a[x][i]-b[y][j])){
					if(l>a[x][i]){
						l=a[x][i];
						r=b[y][j];
					}
					else if(l==a[x][i]){
						if(r>b[y][j]){
							r=b[y][j];
						}
					}
				}
			}
		}
		int tem = s[0].size()-1;
		int p = 1;
		while(tem--){
			p*=10;
		}
		cout<<"Case #"<<T<<": ";
		if(l==0)
			p/=10;
		while(p>l){
			cout<<"0";
			p/=10;
		}
		cout<<l<<" ";
		tem = s[0].size()-1;
		p = 1;
		while(tem--){
			p*=10;
		}
		if(r==0){
			p/=10;
		}
		while(p>r){
			cout<<"0";
			p/=10;
		}
		cout<<r;
		cout<<endl;
		T++;
	}
	return 0;
}