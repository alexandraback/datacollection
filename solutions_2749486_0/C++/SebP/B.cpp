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

int main(){
freopen("Bin.txt","r",stdin);
freopen("Bout.txt","w",stdout);
	tint TC;cin>>TC;
	formn(tc,1,TC+1){
		int X,Y;cin>>X>>Y;
		char cx[2];
		if(X >= 0){
			cx[0] = 'W';
			cx[1] = 'E';
		}
		else{
			cx[0] = 'E';
			cx[1] = 'W';
		}
		
		char cy[2];
		if(Y >= 0){
			cy[0] = 'S';
			cy[1] = 'N';
		}
		else{
			cy[0] = 'N';
			cy[1] = 'S';
		}
		
		string res = "";
		forn(i,abs(X)){
			res += cx[0];
			res += cx[1];
		}
		forn(i,abs(Y)){
			res += cy[0];
			res += cy[1];
		}
		
		cout<<"Case #"<<tc<<": "<<res<<endl;
	}
    return 0;
}
