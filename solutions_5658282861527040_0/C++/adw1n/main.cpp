#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <numeric> //accumulate(i poczatek,i koniec, wartosc_poczatkowa)
#include <utility> //swap
#include <map>

using namespace std;

typedef vector<int> VI;
typedef long long LL;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second
#define MP make_pair
int main (int argc, char * const argv[]) {
	if(!freopen("in2.txt", "r", stdin)) cout<<"Blad odczytu in.txt"<<endl;
	if(!freopen("out.txt", "w", stdout)) cout<<"Blad pliku wyjsciowego"<<endl;
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	int a,b,k;
	FOR(numer_testu,1,t){
		cin>>a>>b>>k;
		LL ans=0;
		FOR(pierwsza,0,a-1)
		FOR(druga,0,b-1){
			if(k>(pierwsza&druga))ans++;
		}
		cout << "Case #"<<numer_testu<<": "<<ans<<endl;
	}
	
	
    return 0;
}
