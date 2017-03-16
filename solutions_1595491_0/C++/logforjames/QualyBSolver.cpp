#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

#define forsn(i,s,n) for(int i = (s);i < (int)(n);i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i = (n - 1);i >= 0;i--)
#define dforn(i,n) dforsn(i,0,n)
#define esta(x,c) (c.find(x) != c.end())
#define all(v) v.begin(),v.end()

int main(){
	freopen("QualyB.in","r",stdin);
	freopen("QualyB.out","w",stdout);
	int t;
	cin >> t;
	forn(i,t){
		int n,s,p,l[100];
		cin >> n >> s >> p;
		forn(j, n)
			cin >> l[j];
		int tot = 0;
		sort(l, l + n);
		//for(int j = (n - 1);j >= 0;j--){
		dforn(j,n){
			int notSurprising = (l[j] + 2) / 3;
			if(notSurprising >= p){
				tot++;
			}
			else{
				int surprising = (l[j] > 0 ? (l[j] + 4) / 3 : 0);
				if(surprising >= p && s > 0){
					tot++;
					s--;
				}
				else{
					break;
				}
			}
		}
		cout << "Case #" << i + 1 << ": " << tot << endl;
	}
}
