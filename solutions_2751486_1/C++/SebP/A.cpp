///SACAR FREOPEN.
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<list>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<map>
#include<sstream>

using namespace std;

#define all(c) (c).begin(),(c).end()
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define formn(i,m,n) for(int i=m;i<(int)n;i++)
#define dformn(i,m,n) for(int i=n-1;i>=m;i--)
#define mp make_pair
#define pb push_back

const double PI=acos(-1.0);

typedef long long tint;
typedef pair<int,int> pint;

bool isCon(char & c){
	return (c!='a' && c!='e' && c!= 'i' && c!='o' && c!='u');
}

int main(){
freopen("A-large.txt","r",stdin);
freopen("Aout.txt","w",stdout);
	tint TC;cin>>TC;
	formn(tc,1,TC+1){
		string s;cin>>s;
		tint n;cin>>n;
		tint l  = s.size();
		tint res = 0;
		tint lo = 0;
		tint hi = 0;
		tint racha = 0;
		while(lo < l){
			///quiero hallar la cantidad de substr. buenos que empiezan en lo.
			///invariante: hi es la primera posicion no visitada.
			///tengo que hallar el nuevo hi que me da la racha.
			while(hi < l && racha < n){
				if(isCon(s[hi])){
					racha++;
					hi++;
				}
				else{
					racha = 0;
					hi++;
				}
			}
			///ya tengo hi calculado.
			if(racha == n){
				res += (l - hi + 1)*((hi - n) - lo + 1);
				lo = hi - n + 1;
				racha--;
			}
			else{
				break;
			}
		}
		cout<<"Case #"<<tc<<": "<<res<<endl;
	}
    return 0;
}
